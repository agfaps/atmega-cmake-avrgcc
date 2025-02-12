cmake_minimum_required(VERSION 3.15)
project(atmega_catch2)

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src/catch2)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/../../include
)

# Add module/s to be tested
add_library(modules
    ../../src/mylib/mylib.c
)

# Add Catch2 (assuming Catch2 v3 source is in src)
add_subdirectory(src)

# Unit test target
add_executable(run_tests test_mylib.cpp)
target_link_libraries(run_tests PRIVATE Catch2::Catch2WithMain modules)