cmake_minimum_required(VERSION 3.10)
project(oop6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES src/observer.cpp src/princess.cpp src/dragon.cpp src/knight.cpp src/npc.cpp)

add_executable(app main.cpp ${SOURCES})

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp ${SOURCES})

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)