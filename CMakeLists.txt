# cmake_minimum_required(VERSION <specify CMake version here>)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test main.cpp shudu.cpp common.cpp testCpp.cpp snow.cpp calc24.cpp ChangeInfixToSuffix.cpp calcExp.cpp CreateFullPermutation.cpp)

add_executable(Test snowJunyi.cpp)