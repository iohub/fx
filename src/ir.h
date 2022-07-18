#ifndef FXIR_H
#define FXIR_H

#include <llvm/IR/Function.h>
#include <memory>

namespace fx {

struct HIR {
    ~HIR() {};
};

typedef std::shared_ptr<HIR> HIRPtr;

struct FunctionIR : HIR {

    FunctionIR(llvm::Function *function, llvm::BasicBlock *ReturnB)
        : fn(function), retblock(ReturnB) {}

    llvm::Function *fn = nullptr;
    llvm::BasicBlock *retblock = nullptr;
    llvm::BasicBlock *terminator = nullptr;
    llvm::Value *retvar = nullptr;
};



};

#endif
