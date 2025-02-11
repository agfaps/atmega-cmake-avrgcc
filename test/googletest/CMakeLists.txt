cmake_minimum_required(VERSION 3.15)
project(atmega_gtest)

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../../include
)

# Add module/s to be tested
add_library(modules
    ../../src/mylib/mylib.c
)

# GoogleTest setup (assumes source is locally available)
add_library(gtest
    src/gtest-all.cc
)

add_library(gtest_main
    src/gtest_main.cc
)

include_directories(include/gtest)

# Unit Test executable
add_executable(run_tests test_mylib.cpp)

target_link_libraries(run_tests PRIVATE modules gtest gtest_main)

enable_testing()

add_test(NAME MyLibUnitTests COMMAND run_tests)