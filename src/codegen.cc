#include "codegen.h"


namespace fx {

CodeGen::CodeGen(std::string name) {
    ctx_ = std::make_unique<llvm::LLVMContext>();
    mod_ = std::make_unique<llvm::Module>(name, *ctx_);
}



}
