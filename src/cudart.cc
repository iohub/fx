#include <fstream>
#include "cudart.h"
#include "exception.h"


namespace fx {

CudaRT::CudaRTResult CudaRT::Init() {
    CUresult cuResult;
    if ((cuResult = cuInit(0)) != CUDA_SUCCESS) {
        return CudaRTResult(cuResult);
    }
    if ((cuResult = cuDeviceGet(&dev_, 0)) != CUDA_SUCCESS) {
        return CudaRTResult(cuResult);
    }
    if ((cuResult = cuCtxCreate(&ctx_, CU_CTX_SCHED_BLOCKING_SYNC, dev_)) != CUDA_SUCCESS) {
        return CudaRTResult(cuResult);
    }
    return CudaRTResult::CuOk;
};

CudaRT::CudaRTResult CudaRT::Launch(const char *ptxFile, const char *kernelName,
                           int blocksX, int blocksY, int blocksZ,
                           int threadsX, int threadsY, int threadsZ,
                           int shared_mem_bytes,
                           size_t arg_sizes[],
                           void *args[]) {
    CUresult ret;
    CUmodule mod;
    if ((ret = cuModuleLoad(&mod, ptxFile)) != CUDA_SUCCESS) {
        return CudaRTResult(ret);
    }
    CUfunction fn;
    if ((ret = cuModuleGetFunction(&fn, mod, kernelName)) != CUDA_SUCCESS) {
        return CudaRTResult(ret);
    }
    ret = cuLaunchKernel(fn,
                   blocksX, blocksY, blocksZ,
                   threadsX, threadsY, threadsZ,
                   shared_mem_bytes,
                   nullptr, // stream
                   nullptr, // params
                   nullptr);

    if (ret != CUDA_SUCCESS) {
        return CudaRTResult(ret);
    }

    return CudaRTResult::CuOk;
}




}
