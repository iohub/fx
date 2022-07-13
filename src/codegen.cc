#include "codegen.h"
#include "exception.h"


namespace fx {

CodeGen::CodeGen(std::string name) {
    ctx_ = std::make_unique<llvm::LLVMContext>();
    mod_ = std::make_unique<llvm::Module>(name, *ctx_);
    builder_ = std::unique_ptr<llvm::IRBuilder<>>(new llvm::IRBuilder<>(*ctx_));
}

void CodeGen::print() const {
    std::string out;
    llvm::raw_string_ostream os{out};
    mod_->print(os, nullptr);
    Logging::info("llvm ir:\n{}\n", os.str());
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
    if (ty->isVoidTy()) {
        builder_->CreateRetVoid();
    } else {
        builder_->CreateRet(emit(fn->body_));
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(Stmts *stmts) {
    if (!stmts) return nullptr;
    for (AstNodePtr p: *stmts) {
        emit(p);
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(IfStmt *If) {
    return nullptr;
}

llvm::Value* CodeGen::emit(ReturnStmt *Return) {
    llvm::Value *val = emit(Return->stmt);
    return builder_->CreateRet(val);
}

llvm::Value* CodeGen::emit_const_value(Val *v) {
    if (!v || !(v->is(Kind::Constant))) return nullptr;
    std::string num = v->raw_data ? *(v->raw_data) : "0";
    switch ((v->Type()).kind()) {
        case TypeID::Float:
            return llvm::ConstantFP::get(*ctx_, llvm::APFloat(std::stof(num)));
        case TypeID::Int:
            return llvm::ConstantInt::get(*ctx_, llvm::APInt(32, std::stoll(num)));
        case TypeID::Bool:
            return llvm::ConstantInt::get(*ctx_, llvm::APInt(8, std::stoi(num)));
        default:
            return nullptr;
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(Val *v) {
    if (!v) return nullptr;
    llvm::Value *retval = nullptr;
    switch (v->kind) {
        case Kind::Constant:
            return emit_const_value(v);
        default:
            retval = nullptr;
    }
    return retval;
}

llvm::Value* CodeGen::emit(BinaryExpr *expr) {
    if (!expr || !expr->is(Kind::BinaryOperator)) return nullptr;
    llvm::Value *lhs = emit(expr->lhs);
    llvm::Value *rhs = emit(expr->rhs);
    switch (expr->op) {
        case OpKind::ADD:
            return builder_->CreateAdd(lhs, rhs, "add");
        case OpKind::SUB:
            return builder_->CreateSub(lhs, rhs, "sub");
        default:
            Logging::error("emit unknown BinaryExpr {} {}\n", expr->loc(), expr->dump());
    }
    return nullptr;
}

llvm::Value* CodeGen::emit(AstNodePtr n) {
    switch (n->kind) {
        case Kind::DeclList:
            return emit(dynamic_cast<Decls*>(n.get()));
        case Kind::FuncDecl:
            return emit(dynamic_cast<FuncDecl*>(n.get()));
        case Kind::CallFunc:
            return emit(dynamic_cast<Call*>(n.get()));
        case Kind::Constant:
            return emit(dynamic_cast<Val*>(n.get()));
        case Kind::ReturnStmt:
            return emit(dynamic_cast<ReturnStmt*>(n.get()));
        case Kind::BinaryOperator:
            return emit(dynamic_cast<BinaryExpr*>(n.get()));
        case Kind::VarRef:
            return emit(dynamic_cast<Val*>(n.get()));
        default:
            Logging::info("emit unknown AstNode {} {}\n", n->loc(), n->dump());
    }
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
        throw new CodeGenException(fmt::format("Not found Function {} {}",
                    call->loc(), call->nominal()));
    }
    llvm::FunctionType *FT = F->getFunctionType();
    std::vector<llvm::Value*> argVals;
    Args argList = call->args();
    for (size_t i=0; i < argList.size(); i++) {
        AstNodePtr arg = argList[i];
        llvm::Value *val = emit(arg);
        if (val == nullptr) {
            throw new CodeGenException(fmt::format("Not found arg {} {} {}", arg->loc(), arg->nominal(), int(arg->kind)));
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
    llvm::Function *F = llvm::Function::Create(fnTy, llvm::Function::ExternalLinkage, fn->nominal(), *mod_);
    unsigned idx = 0;
    for (auto &arg : F->args()) {
        arg.setName((args[idx++])->nominal());
    }
    return F;
}

llvm::Type* CodeGen::lltypeof(Ty ty) {
    if (ty.is(TypeID::Int)) {
        return llvm::Type::getInt32Ty(*ctx_);
    }
    switch(ty.kind()) {
        case TypeID::Int:
            return llvm::Type::getInt32Ty(*ctx_);
        case TypeID::Float:
            return llvm::Type::getFloatTy(*ctx_);
        case TypeID::Bool:
            return llvm::Type::getInt1Ty(*ctx_);
        case TypeID::Void:
            return llvm::Type::getVoidTy(*ctx_);
        case TypeID::Object:
            return mod_->getTypeByName(llvm::StringRef(ty.class_name))->getPointerTo();
        default: return nullptr;
    }
}



}
