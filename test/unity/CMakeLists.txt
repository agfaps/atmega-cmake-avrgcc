cmake_minimum_required(VERSION 3.15)
project(UnitTests C)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/unity
    ${CMAKE_SOURCE_DIR}/../../include
)

# Add Unity framework
add_library(unity unity/unity.c)

set(SOURCE_FILES ../../src/mylib/mylib.c)

# Add test executable
add_executable(run_tests test_mylib.c ${SOURCE_FILES})

target_link_libraries(run_tests unity)
