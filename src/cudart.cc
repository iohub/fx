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

CudaRT::CudaRTResult CudaRT::Launch(const std::string &ptxFile) {
    CUresult ret;
    CUmodule mod;
    if ((ret = cuModuleLoad(&mod, ptxFile.c_str())) != CUDA_SUCCESS) {
        return CudaRTResult(ret);
    }
    CUfunction fn;

    return CudaRTResult::CuOk;
}


}
