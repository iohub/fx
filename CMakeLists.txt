cmake_minimum_required(VERSION 3.8)
project(fx LANGUAGES CXX C)

set(DEFAULT_CMAKE_BUILD_TYPE Debug)
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(Parser src/parser.y ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.cc)
FLEX_TARGET(Scanner src/lexer.l ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

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
    src/astnode.cc
    src/typecheck.cc
    src/main.cc
)


set_property(TARGET fx PROPERTY CXX_STANDARD 17)

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/fmt)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/CLI11)
include_directories(${CMAKE_SOURCE_DIR}/third_party/CLI11/include)

target_link_libraries(fx PUBLIC fmt)


