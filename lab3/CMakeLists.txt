cmake_minimum_required(VERSION 3.10)
project(oop3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


include_directories(input)
include_directories(scr)

set(SOURCES scr/Figure.cpp scr/Trapezoid.cpp scr/Rhombus.cpp scr/Pentagon.cpp scr/Array.cpp)

add_executable(app main.cpp ${SOURCES})

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp ${SOURCES})

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)