cmake_minimum_required(VERSION 3.11)

project(fx LANGUAGES CXX C)

include(FetchContent)
include(ExternalProject)
set(CMAKE_TLS_VERIFY true)

set(DEFAULT_CMAKE_BUILD_TYPE Debug)
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

set(LLVM_PKG clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz)
set(LLVM_BUILT_URL https://releases.llvm.org/9.0.0/${LLVM_PKG})
set(JSONLIB_URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)

ExternalProject_Add(llvm_built
    URL ${LLVM_BUILT_URL}
    PREFIX ${CMAKE_SOURCE_DIR}/llvm_built
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

set(LLVM_INSTALL_DIR ${CMAKE_SOURCE_DIR}/llvm_built/src/llvm_built)
find_package(LLVM 9.0.0 CONFIG PATHS "${LLVM_INSTALL_DIR}/lib/cmake/llvm" NO_DEFAULT_PATH)
if (NOT LLVM_FOUND)
  message(FATAL_ERROR "not found llvm")
else()
  message(STATUS "found LLVM ${LLVM_PACKAGE_VERSION}")
endif()

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

FetchContent_Declare(json URL ${JSONLIB_URL} URL_HASH MD5=4b67aba51ddf17c798e80361f527f50e)
FetchContent_MakeAvailable(json)

BISON_TARGET(Parser src/parser.y ${CMAKE_SOURCE_DIR}/src/parser.cc)
FLEX_TARGET(Scanner src/lexer.l ${CMAKE_SOURCE_DIR}/src/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

set(CMAKE_LLVM_CONFIG ${LLVM_INSTALL_DIR}/bin/llvm-config)
exec_program(${CMAKE_LLVM_CONFIG} ARGS --includedir OUTPUT_VARIABLE LLVM_INCDIR)
exec_program(${CMAKE_LLVM_CONFIG} ARGS --libdir OUTPUT_VARIABLE LLVM_LIBDIR)

# llvm library
if (EXISTS "${LLVM_INCDIR}")
  message(STATUS "found llvm includedir:${LLVM_INCDIR}")
  message(STATUS "found llvm libdir:${LLVM_LIBDIR}")
else()
  message(FATAL_ERROR "not found llvm:${LLVM_INCDIR}")
endif()

# fmt library
if(EXISTS "${CMAKE_SOURCE_DIR}/third_party/fmt/include")
  message(STATUS "found fmt library")
  set(Fmt_INCLUDE_DIR third_party/fmt/include)
else()
  message(STATUS "git submodule init && git submodule update")
  message(FATAL_ERROR "load fmt library failed")
endif()

# CLI11 library
if(EXISTS "${CMAKE_SOURCE_DIR}/third_party/CLI11/include")
  message(STATUS "found CLI11 library")
  set(CLI11_INCLUDE_DIR third_party/CLI11/include)
else()
  message(STATUS "git submodule init && git submodule update")
  message(FATAL_ERROR "load CLI11 library failed")
endif()

add_executable(fx
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
    ${Fmt_INCLUDE_DIR}
    ${CLI11_INCLUDE_DIR}
    ${JSON_INCLUDE_DIR}
    src/type.cc
    src/astnode.cc
    src/typecheck.cc
    src/codegen.cc
    src/main.cc
)

set_property(TARGET fx PROPERTY CXX_STANDARD 17)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/fmt)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/CLI11)
include_directories(${CMAKE_SOURCE_DIR}/third_party/CLI11/include)
include_directories(${LLVM_INCDIR})

target_link_libraries(fx PRIVATE fmt)
target_link_libraries(fx PRIVATE LLVMCore)
target_link_libraries(fx PRIVATE nlohmann_json::nlohmann_json)


