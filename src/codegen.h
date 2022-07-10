#ifndef FX_CODEGEN_H
#define FX_CODEGEN_H

#include <llvm/IR/LLVMContext.h>

#include "astnode.h"


namespace fx {

using namespace llvm;

class CodeGen {

public:
    CodeGen();

private:
    LLVMContext ctx;

};





};



#endif
