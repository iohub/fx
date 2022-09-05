#ifndef FX_CUDA_H
#define FX_CUDA_H

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

// cuda
#include <cuda.h>
#include <cuda_runtime.h>

#include "util.h"

namespace fx {


class CudaRT {

public:
    enum class CudaRTResult : uint8_t {
        CuOk = 0,
    };

    CudaRTResult Init();
    CudaRTResult Launch(const char *ptxFile, const char *kernelName,
                           int blocksX, int blocksY, int blocksZ,
                           int threadsX, int threadsY, int threadsZ,
                           int shared_mem_bytes,
                           size_t arg_sizes[],
                           void *args[]);

private:
    CUdevice dev_;
    CUcontext ctx_;

};





};



#endif
