cmake_minimum_required(VERSION 3.10)
project(oop4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(app main.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)