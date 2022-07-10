#ifndef FX_CODEGEN_H
#define FX_CODEGEN_H

#include <memory>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include "astnode.h"


namespace fx {


class CodeGen {

public:
    CodeGen(std::string name);

private:
    std::unique_ptr<llvm::LLVMContext> ctx_;
    std::unique_ptr<llvm::Module> mod_;

};





};



#endif
