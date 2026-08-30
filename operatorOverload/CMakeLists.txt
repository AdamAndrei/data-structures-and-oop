cmake_minimum_required(VERSION 3.16)
project(operatorOverload CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "${CMAKE_BINARY_DIR}/.*")

add_executable(operatorOverload ${SOURCES})
target_include_directories(operatorOverload PRIVATE ${CMAKE_SOURCE_DIR}/include)
# target_compile_options(operatorOverload PRIVATE -Wall -Wextra -pedantic-errors)