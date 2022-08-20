#include <fstream>
#include "codegen.h"
#include "exception.h"


namespace fx {

namespace detail {

using Predicate = llvm::CmpInst::Predicate;
static std::map<std::pair<OpKind, TypeID>,  Predicate> CmpInstrMappings = {
    {{OpKind::EQ, TypeID::Int}, Predicate::ICMP_EQ},
    {{OpKind::NEQ, TypeID::Int}, Predicate::ICMP_NE},
    {{OpKind::GT, TypeID::Int}, Predicate::ICMP_SGT},
    {{OpKind::GE, TypeID::Int}, Predicate::ICMP_SGE},
    {{OpKind::LT, TypeID::Int}, Predicate::ICMP_SLT},
    {{OpKind::LE, TypeID::Int}, Predicate::ICMP_SLE},

    {{OpKind::EQ, TypeID::Float}, Predicate::FCMP_OEQ},
    {{OpKind::GT, TypeID::Float}, Predicate::FCMP_OGT},
    {{OpKind::GE, TypeID::Float}, Predicate::FCMP_OGE},
    {{OpKind::LT, TypeID::Float}, Predicate::FCMP_OLT},
    {{OpKind::LE, TypeID::Float}, Predicate::FCMP_OLE},
    {{OpKind::NEQ, TypeID::Float}, Predicate::FCMP_ONE},
};


};

CodeGen::CodeGen(std::string name) {
    ctx_ = std::make_unique<llvm::LLVMContext>();
    mod_ = std::make_unique<llvm::Module>(name, *ctx_);
    builder_ = std::unique_ptr<llvm::IRBuilder<>>(new llvm::IRBuilder<>(*ctx_));
}

std::string CodeGen::llvm_ir() const {
    std::string ir;
    llvm::raw_string_ostream os{ir};
    mod_->print(os, nullptr);
    return os.str();
}

void CodeGen::dump(const std::string &fname) const {
    std::ofstream outf(fname);
    outf << llvm_ir();
}

llvm::Value* CodeGen::emit(FuncDecl *fn) {
    llvm::Function *Fn = mod_->getFunction(llvm::StringRef(fn->nominal()));
    Fn = Fn ? Fn : emit_func_prototype(fn);
    llvm::BasicBlock *block = llvm::BasicBlock::Create(*ctx_, "entry", Fn);
    builder_->SetInsertPoint(block);
    llvm::Type *ty = lltypeof(fn->ty);
    if (!ty) {
        Fn->eraseFromParent(); return nullptr;
    }
    Defer defer([&]() { env_.enter(); }, [&]() { env_.leave(); });
    FunctionIR ir(Fn, llvm::BasicBlock::Create(*ctx_, "_ret", Fn));
    ir.retvar = builder_->CreateAlloca(lltypeof(fn->Type()), 0, fn->nominal() + "_retvar");
    env_.put_func(fn->nominal(), &ir);

    auto FArgs = fn->args();
    size_t idx = 0;
    // alloc args
    for (auto &arg : Fn->args()) {
        llvm::AllocaInst *inst = emit_block_alloca(&(Fn->getEntryBlock()), FArgs[idx++]);
        builder_->CreateStore(&arg, inst);
        env_.put_var(std::string(arg.getName()), inst);
    }
    for (auto &b : fn->body()) {
        if (b->is(Kind::VarDecl)) {
            llvm::AllocaInst *inst = emit_block_alloca(&(Fn->getEntryBlock()), b);
            env_.put_var(b->nominal(), inst);
        }
    }
    emit(fn->body_);
    if (ir.terminator) {
        builder_->SetInsertPoint(ir.retblock);
        builder_->CreateRet(builder_->CreateLoad(ir.retvar));
    }
    return nullptr;
}

llvm::AllocaInst* CodeGen::emit_block_alloca(llvm::BasicBlock *block, AstNodePtr var) {
    llvm::IRBuilder<> bbuilder(block, block->begin());
    return bbuilder.CreateAlloca(lltypeof(var->Type()), 0, var->nominal());
}

llvm::Value* CodeGen::emit(AssignStmt *assign) {
    llvm::Value* valV = emit(assign->val_);
    llvm::Value* varV = emit(assign->var_);
    if (!varV) {
        throw new CodeGenException(_f("{} not found variable", assign->loc()));
    }
    builder_->CreateStore(valV, varV);
    return valV;
}

llvm::Value* CodeGen::emit(Stmts *stmts) {
    if (!stmts) return nullptr;
    for (AstNodePtr p: *stmts) {
        emit(p);
    }
    return nullptr;
}

llvm::BasicBlock* CodeGen::currentbb() {
    return builder_->GetInsertBlock();
}

llvm::BasicBlock* CodeGen::insert_block_after(llvm::Function* function,
        llvm::BasicBlock *predecessor, const llvm::Twine &name) {
    auto bb = llvm::BasicBlock::Create(*ctx_, name,  function);
    bb->moveAfter(predecessor);
    return bb;
}

llvm::Value* CodeGen::emit(IfStmt *If) {
    llvm::Value* cond = emit(If->cond_);
    if (!cond) throw new CodeGenException(_f("{} null conditional", If->loc()));

    llvm::Function *pF = builder_->GetInsertBlock()->getParent();
    llvm::BasicBlock* _then = insert_block_after(pF, currentbb(), "_then");
    llvm::BasicBlock* _else = If->else_ ? insert_block_after(pF, _then, "_else") : nullptr;
    llvm::BasicBlock *predecessor = _else ? _else : _then;
    llvm::BasicBlock* _end = insert_block_after(pF, predecessor, "_end");
    if (!_else) _else = _end;

    builder_->CreateCondBr(cond, _then, _else);
    builder_->SetInsertPoint(_then);
    emit(If->then_);
    if (!currentbb()->getTerminator()) llvm::BranchInst::Create(_end, currentbb());

    if (If->else_) {
        builder_->SetInsertPoint(_else);
        emit(If->else_);
        if (!currentbb()->getTerminator()) llvm::BranchInst::Create(_end, currentbb());
    }
    builder_->SetInsertPoint(_end);
    return nullptr;
}

llvm::Value* CodeGen::emit(ReturnStmt *Return) {
    llvm::Function *pF = builder_->GetInsertBlock()->getParent();
    llvm::Value* val = emit(Return->stmt);
    // store retval
    if (!pF->getReturnType()->isVoidTy()) {
        FunctionIR *ir = env_.lookup_func(std::string(pF->getName()));
        builder_->CreateStore(val, ir->retvar);
        builder_->CreateBr(ir->retblock);
        ir->terminator = currentbb();
    }
    return val;
}

llvm::Value* CodeGen::emit_const_value(Val *v) {
    if (!v || !(v->is(Kind::Constant))) return nullptr;
    std::string num = v->raw_data;
    switch ((v->Type()).kind()) {
        case TypeID::Float: return llvm::ConstantFP::get(*ctx_, llvm::APFloat(std::stof(num)));
        case TypeID::Int: return llvm::ConstantInt::get(*ctx_, llvm::APInt(32, std::stoll(num)));
        case TypeID::Bool: return llvm::ConstantInt::get(*ctx_, llvm::APInt(8, std::stoi(num)));
        default: return nullptr;
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(Val *v) {
    if (!v) return nullptr;
    switch (v->kind) {
        case Kind::Constant: return emit_const_value(v);
        case Kind::VarRef: return env_.lookup_var(v->nominal());
        case Kind::Value: return builder_->CreateLoad(env_.lookup_var(v->nominal()));
        default: throw new CodeGenException(_f("{} emit unknown Val", v->loc()));
    }
    return nullptr;
}

llvm::Value* CodeGen::emit_binexpr(BinaryExpr *expr) {
    if (!expr || !expr->is(Kind::BinaryOperator)) return nullptr;
    llvm::Value *lhs = emit(expr->lhs);
    llvm::Value *rhs = emit(expr->rhs);
    if (!expr->lhs) {
        throw new CodeGenException(_f("{} invalid BinaryExpr", expr->loc()));
    }
    Ty ty = expr->lhs->ty;
    llvm::Type *lty = lltypeof(ty);
    switch (expr->op) {
        case OpKind::ADD:
            return ty.is(TypeID::Int) ? builder_->CreateAdd(lhs, rhs, "add")
                : builder_->CreateFAdd(lhs, rhs, "add");
        case OpKind::SUB:
            return ty.is(TypeID::Int) ? builder_->CreateSub(lhs, rhs, "add")
                : builder_->CreateFSub(lhs, rhs, "sub");
        default:
            Logging::error("emit unknown BinaryExpr {} {}\n", expr->loc(), expr->dump());
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(LetAssign *letA) {
    llvm::AllocaInst *inst = emit_block_alloca(currentbb(), letA->var);
    env_.put_var(letA->var->nominal(), inst);
    llvm::Value* val = emit(letA->val);
    builder_->CreateStore(val, inst);
    return nullptr;
}

llvm::Value* CodeGen::emit_bincmp(BinaryExpr *cmp) {
    if (!cmp || !cmp->is(Kind::BinaryCmp)) return nullptr;
    llvm::Value *lhs = emit(cmp->lhs), *rhs = emit(cmp->rhs);
    if (!cmp->lhs) {
        throw new CodeGenException(_f("{} invalid Compare", cmp->loc()));
    }
    Ty ty = cmp->lhs->ty;
    llvm::Type *lty = lltypeof(ty);
    llvm::CmpInst::Predicate pre = detail::CmpInstrMappings[std::make_pair(cmp->op, ty.id)];
    switch (ty.id) {
        case TypeID::Int: return builder_->CreateICmp(pre, lhs, rhs);
        case TypeID::Float: return builder_->CreateFCmp(pre, lhs, rhs);
        default: Logging::error("{} emit unknown BinaryCmp\n", cmp->loc());
    }
    return nullptr;
}


llvm::Value* CodeGen::emit(AstNodePtr n) {
    switch (n->kind) {
        case Kind::DeclList: return emit(static_cast<Decls*>(n.get()));
        case Kind::FuncDecl: return emit(static_cast<FuncDecl*>(n.get()));
        case Kind::CallFunc: return emit(static_cast<Call*>(n.get()));
        case Kind::Constant: return emit(static_cast<Val*>(n.get()));
        case Kind::ReturnStmt: return emit(static_cast<ReturnStmt*>(n.get()));
        case Kind::BinaryOperator: return emit_binexpr(static_cast<BinaryExpr*>(n.get()));
        case Kind::BinaryCmp: return emit_bincmp(static_cast<BinaryExpr*>(n.get()));
        case Kind::VarRef: return emit(static_cast<Val*>(n.get()));
        case Kind::Value: return emit(static_cast<Val*>(n.get()));
        case Kind::VarDecl: return nullptr;
        case Kind::Assign: return emit(static_cast<AssignStmt*>(n.get()));
        case Kind::LetAssign: return emit(static_cast<LetAssign*>(n.get()));
        case Kind::If: return emit(static_cast<IfStmt*>(n.get()));
        case Kind::For: return emit(static_cast<ForStmt*>(n.get()));
        case Kind::Nil: return nullptr;
        default:
            Logging::info("emit unknown AstNode {} {}\n", n->loc(), n->dump());
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(ForStmt *For) {
    llvm::Value *cond = emit(For->cond_stmt);
    llvm::Function *pF = builder_->GetInsertBlock()->getParent();
    llvm::BasicBlock *loopB = llvm::BasicBlock::Create(*ctx_, "_loop");
    llvm::BasicBlock *endB = llvm::BasicBlock::Create(*ctx_, "_loop_end");
    builder_->CreateCondBr(cond, loopB, endB);
    pF->getBasicBlockList().push_back(loopB);
    builder_->SetInsertPoint(loopB);

    emit(For->body);
    cond = emit(For->cond_stmt);
    loopB = builder_->GetInsertBlock();
    builder_->CreateCondBr(cond, loopB, endB);
    pF->getBasicBlockList().push_back(endB);
    builder_->SetInsertPoint(endB);

    return nullptr;
}

llvm::Value* CodeGen::emit(Decls *decls) {
    if (!decls) return nullptr;
    for (auto p: decls->decls) {
        emit(p);
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(Call *call) {
    if (!call) return nullptr;
    llvm::Function *F = mod_->getFunction(llvm::StringRef(call->nominal()));
    if (!F) {
        throw new CodeGenException(_f("Not found function {} {}",
                    call->loc(), call->nominal()));
    }
    llvm::FunctionType *FT = F->getFunctionType();
    std::vector<llvm::Value*> argVals;
    Args argList = call->args();
    for (size_t i=0; i < argList.size(); i++) {
        AstNodePtr arg = argList[i];
        llvm::Value *val = emit(arg);
        if (val == nullptr) {
            throw new CodeGenException(_f("Not found arg {} {} {}",
                        arg->loc(), arg->nominal(), int(arg->kind)));
        }
        llvm::Type *ty = FT->getParamType(i);
        llvm::Value *bitcast = builder_->CreateBitCast(val, ty);
        argVals.push_back(bitcast);
    }
    return builder_->CreateCall(F, argVals);
}

llvm::Function* CodeGen::emit_func_prototype(FuncDecl *fn) {
    std::vector<llvm::Type*> argsTy;
    auto args  = fn->args();
    for (AstNodePtr arg: args) {
        argsTy.push_back(lltypeof(arg->Type()));
    }
    llvm::Type *retTy = lltypeof(fn->Type());
    llvm::FunctionType *fnTy = llvm::FunctionType::get(retTy, argsTy, false);
    llvm::Function *F = llvm::Function::Create(fnTy,
            llvm::Function::ExternalLinkage, fn->nominal(), *mod_);
    unsigned idx = 0;
    for (auto &arg : F->args()) {
        arg.setName((args[idx++])->nominal());
    }
    return F;
}

llvm::Type* CodeGen::lltypeof(Ty ty) {
    if (ty.is(TypeID::Int)) return llvm::Type::getInt32Ty(*ctx_);
    switch(ty.kind()) {
        case TypeID::Int: return llvm::Type::getInt32Ty(*ctx_);
        case TypeID::Float: return llvm::Type::getFloatTy(*ctx_);
        case TypeID::Bool: return llvm::Type::getInt1Ty(*ctx_);
        case TypeID::Void: return llvm::Type::getVoidTy(*ctx_);
        case TypeID::Object: return mod_->getTypeByName(llvm::StringRef(ty.class_name))->getPointerTo();
        default: return nullptr;
    }
}



}
