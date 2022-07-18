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
#include "env.h"


namespace fx {


class CodeGen {

public:
    CodeGen(std::string name);
    llvm::Value* emit(AstNodePtr n);
    std::string llvm_ir() const;
    void dump(const std::string &fname) const;

private:
    llvm::BasicBlock* currentbb();
    llvm::BasicBlock* insert_block_after(llvm::Function *function,
            llvm::BasicBlock *predecessor, const llvm::Twine &name);
    llvm::Function *emit_func_prototype(FuncDecl *fn);
    llvm::AllocaInst* emit_block_alloca(llvm::BasicBlock &block, AstNodePtr var);
    llvm::Value *emit_const_value(Val *v);
    llvm::Value* emit_bincmp(BinaryExpr *BinExpr);
    llvm::Value* emit_binexpr(BinaryExpr *BinExpr);
    llvm::Type* lltypeof(Ty ty);

    llvm::Value* emit(FuncDecl *fn);
    llvm::Value* emit(Decls *decls);
    llvm::Value* emit(IfStmt *If);
    llvm::Value* emit(BinaryExpr *BinExpr);
    llvm::Value* emit(Val *v);
    llvm::Value* emit(Stmts *stmts);
    llvm::Value* emit(Call *call);
    llvm::Value* emit(ReturnStmt *Return);
    llvm::Value* emit(AssignStmt *assign);
    llvm::Value* emit(ForStmt *For);

private:
    std::unique_ptr<llvm::LLVMContext> ctx_;
    std::unique_ptr<llvm::Module> mod_;
    std::unique_ptr<llvm::IRBuilder<> > builder_;
    Env<llvm::Value*, llvm::Function*> env_;
};





};



#endif
