cmake_minimum_required(VERSION 3.10)
project(oop3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(input)
include_directories(scr)

add_executable(app main.cpp scr/Figure.cpp scr/Trapezoid.cpp scr/Rhombus.cpp scr/Pentagon.cpp scr/Array.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp scr/Figure.cpp scr/Trapezoid.cpp scr/Rhombus.cpp scr/Pentagon.cpp scr/Array.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)