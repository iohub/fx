cmake_minimum_required(VERSION 3.11)

project(fx LANGUAGES CXX C)

include(FetchContent)
set(CMAKE_TLS_VERIFY true)
set(CMAKE_CXX_STANDARD 17)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

set(LLVM_PKG clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz)
set(LLVM_BUILT_URL https://releases.llvm.org/9.0.0/${LLVM_PKG})
set(JSONLIB_URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
set(ANTLR_URL https://www.antlr.org/download/antlr4-cpp-runtime-4.7.2-source.zip)

FetchContent_Declare(json URL ${JSONLIB_URL} URL_HASH MD5=4b67aba51ddf17c798e80361f527f50e)
FetchContent_MakeAvailable(json)

FetchContent_Declare(antlr URL ${ANTLR_URL} URL_HASH MD5=3a88c898579f78d8c84c583c5160986b)
FetchContent_MakeAvailable(antlr)

FetchContent_Declare(llvm URL ${LLVM_BUILT_URL} URL_HASH MD5=9d8044379e151029bb1df3663c2fb2c1)
FetchContent_MakeAvailable(llvm)

set(ANTLR_DIR ${CMAKE_CURRENT_BINARY_DIR}/_deps/antlr-src)
list(APPEND CMAKE_MODULE_PATH ${ANTLR_DIR}/cmake)

set(LLVM_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/_deps/llvm-src)
# set(LLVM_INSTALL_DIR /home/do/extdata/local/mlir)
find_package(LLVM CONFIG PATHS ${LLVM_INSTALL_DIR}/lib/cmake/llvm NO_DEFAULT_PATH)

if (NOT LLVM_FOUND)
  message(FATAL_ERROR "not found llvm in ${LLVM_INSTALL_DIR}")
else()
  message(STATUS "found LLVM ${LLVM_PACKAGE_VERSION}")
endif()

list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})
include(AddLLVM)

BISON_TARGET(Parser src/parser.y ${CMAKE_SOURCE_DIR}/src/parser.cc)
FLEX_TARGET(Scanner src/lexer.l ${CMAKE_SOURCE_DIR}/src/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

set(CMAKE_LLVM_CONFIG ${LLVM_INSTALL_DIR}/bin/llvm-config)
exec_program(${CMAKE_LLVM_CONFIG} ARGS --includedir OUTPUT_VARIABLE LLVM_INCDIR)
exec_program(${CMAKE_LLVM_CONFIG} ARGS --libdir OUTPUT_VARIABLE LLVM_LIBDIR)

# llvm library
if (EXISTS ${LLVM_INCDIR})
  message(STATUS "found llvm includedir:${LLVM_INCDIR}")
  message(STATUS "found llvm libdir:${LLVM_LIBDIR}")
else()
    message(STATUS "not found llvm:${LLVM_INCDIR}")
endif()

# fmt library
if(EXISTS ${CMAKE_SOURCE_DIR}/third_party/fmt/include)
  message(STATUS "found fmt library")
  set(Fmt_INCLUDE_DIR third_party/fmt/include)
else()
  message(STATUS "git submodule init && git submodule update")
  message(FATAL_ERROR "load fmt library failed")
endif()

# CLI11 library
if(EXISTS ${CMAKE_SOURCE_DIR}/third_party/CLI11/include)
  message(STATUS "found CLI11 library")
  set(CLI11_INCLUDE_DIR third_party/CLI11/include)
else()
  message(STATUS "git submodule init && git submodule update")
  message(FATAL_ERROR "load CLI11 library failed")
endif()

# antlr4
set(Antlr4Parser
    ${CMAKE_SOURCE_DIR}/src/antlr4/fxLexer.cpp
    ${CMAKE_SOURCE_DIR}/src/antlr4/fxParser.cpp
)

add_executable(fx
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
    ${Fmt_INCLUDE_DIR}
    ${CLI11_INCLUDE_DIR}
    src/type.cc
    src/ast.cc
    src/fxParserImpl.cc
    ${Antlr4Parser}
    src/typecheck.cc
    src/codegen.cc
    src/main.cc
)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/antlr4)
include_directories(${ANTLR_DIR}/runtime/src)
include_directories(${CMAKE_SOURCE_DIR}/third_party/CLI11/include)
include_directories(${LLVM_INCDIR})

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/fmt)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/CLI11)

target_link_libraries(fx PRIVATE fmt)
target_link_libraries(fx PRIVATE LLVMCore)
target_link_libraries(fx PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(fx PRIVATE antlr4_static)

