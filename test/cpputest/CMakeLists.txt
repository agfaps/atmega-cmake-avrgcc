cmake_minimum_required(VERSION 3.15)
project(UnitTests C CXX)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../../include
)

# Add CppUTest framework
add_library(cpputest
    src/CppUTest/CommandLineArguments.cpp
    src/CppUTest/CommandLineTestRunner.cpp
    src/CppUTest/JUnitTestOutput.cpp
    src/CppUTest/MemoryLeakDetector.cpp
    src/CppUTest/MemoryLeakWarningPlugin.cpp
    src/CppUTest/SimpleMutex.cpp
    src/CppUTest/SimpleString.cpp
    src/CppUTest/SimpleStringInternalCache.cpp
    src/CppUTest/TeamCityTestOutput.cpp
    src/CppUTest/TestFailure.cpp
    src/CppUTest/TestFilter.cpp
    src/CppUTest/TestHarness_c.cpp
    src/CppUTest/TestMemoryAllocator.cpp
    src/CppUTest/TestOutput.cpp
    src/CppUTest/TestPlugin.cpp
    src/CppUTest/TestRegistry.cpp
    src/CppUTest/TestResult.cpp
    src/CppUTest/TestTestingFixture.cpp
    src/CppUTest/Utest.cpp
)

# # Add CppUTestExt framework
# add_library(cpputestext
#     src/CppUTestExt/CodeMemoryReportFormatter.cpp
#     src/CppUTestExt/GTest.cpp
#     src/CppUTestExt/IEEE754ExceptionsPlugin.cpp
#     src/CppUTestExt/MemoryReportAllocator.cpp
#     src/CppUTestExt/MemoryReporterPlugin.cpp
#     src/CppUTestExt/MemoryReportFormatter.cpp
#     src/CppUTestExt/MockActualCall.cpp
#     src/CppUTestExt/MockExpectedCall.cpp
#     src/CppUTestExt/MockExpectedCallsList.cpp
#     src/CppUTestExt/MockFailure.cpp
#     src/CppUTestExt/MockNamedValue.cpp
#     src/CppUTestExt/MockSupport.cpp
#     src/CppUTestExt/MockSupport_c.cpp
#     src/CppUTestExt/MockSupportPlugin.cpp
#     src/CppUTestExt/OrderedTest.cpp
# )

# Add specific platform (GCC)
add_library(platform
    src/Platforms/Gcc/UtestPlatform.cpp
)

# Add module/s to be tested
add_library(modules
    ../../src/mylib/mylib.c
)

set(CMAKE_CXX_FLAGS "-DCPPUTEST_USE_OWN_CONFIGURATION")

# Add test executable
add_executable(run_tests
    test_runner.cpp
    test_mylib.cpp
)

target_link_libraries(run_tests cpputest platform modules)