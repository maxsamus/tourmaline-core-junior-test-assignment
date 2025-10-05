cmake_minimum_required(VERSION 3.10)
project(ChangeCalculatorTests)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_change_calculator
    src/change_calculator.cpp
    tests/test_change_calculator.cpp
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(test_change_calculator gtest gtest_main)