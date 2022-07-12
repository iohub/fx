#include "codegen.h"


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

void CodeGen::emit(FuncDecl *fn) {
    llvm::Function *Fn = mod_->getFunction(llvm::StringRef(fn->nominal()));
    Fn = Fn ? Fn : emit_func_prototype(fn);
    llvm::BasicBlock *block = llvm::BasicBlock::Create(*ctx_, "entry", Fn);
    builder_->SetInsertPoint(block);
    llvm::Type *ty = lltypeof(fn->ty);
    if (!ty) {
        Fn->eraseFromParent(); return;
    }
    if (ty->isVoidTy()) {
        builder_->CreateRetVoid();
    }
}

void CodeGen::emit(AstNodePtr n) {
    switch (n->kind) {
        case Kind::DeclList:
            emit(dynamic_cast<Decls*>(n.get())); break;
        case Kind::FuncDecl:
            emit(dynamic_cast<FuncDecl*>(n.get())); break;
        default:
            Logging::info("emit unknown AstNode {}{}", n->loc(), n->dump());
    }
}

void CodeGen::emit(Decls *decls) {
    if (!decls) return;
    for (auto p: decls->decls) {
        emit(p);
    }
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
            return mod_->getTypeByName(llvm::StringRef("nil"))->getPointerTo();
        default: return nullptr;
    }
}



}
