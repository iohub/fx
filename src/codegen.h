#ifndef FX_CODEGEN_H
#define FX_CODEGEN_H

#include <memory>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Metadata.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Verifier.h>

#include "astnode.h"


namespace fx {


class CodeGen {

public:
    CodeGen(std::string name);
    void emit(AstNodePtr n);
    void print() const;

    void emit(FuncDecl *fn);
    void emit(Decls *decls);
    void emit(IfStmt *If);
    void emit(BinaryExpr *BinExpr);

private:
    llvm::Function *emit_func_prototype(FuncDecl *fn);
    llvm::Type* lltypeof(Ty ty);

private:
    std::unique_ptr<llvm::LLVMContext> ctx_;
    std::unique_ptr<llvm::Module> mod_;
    std::unique_ptr<llvm::IRBuilder<> > builder_;

};





};



#endif
