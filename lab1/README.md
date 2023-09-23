# **Лабараторная по ООП №1**
## **Козырев Пётр Вариант №12**

## Цель:
Изучение системы сборки на языке C++, изучение систем контроля версии.
Изучение работом с память в C++
Изучение работы с вводом/выводом в стандартный поток

## Задача:
Ваша компания, Timaty Pizza, является вторым по величине интернет-магазином замороженной
пиццы. Вы владеете несколькими международными складами, которые используются для
хранения замороженной пиццы, и вам необходимо определить, сколько ящиков пиццы вы можете
хранить на каждом из них.
Компания Timaty недавно стандартизировала свои контейнеры для хранения: все пиццы
помещаются в кубические ящики со стороной 16 дюймов. Ящики очень прочные, поэтому их
можно укладывать как угодно высоко.
Напишите функцию box_capacity(), которая определяет, сколько ящиков можно хранить на
данном складе. Функция должна принимать три аргумента: длину, ширину и высоту склада (в
футах) и возвращать целое число, представляющее количество ящиков, которые можно хранить
на этом пространстве.
Например: склад длиной 32 фута, шириной 64 фута и высотой 16 футов может вместить 13 824
ящика, поскольку в нем можно разместить 24 ящика в поперечнике, 48 ящиков в глубину и 12
ящиков в высоту, поэтому box_capacity(32, 64, 16) должна возвращать 13824.

## Решение:

main.cpp:
```
#include <iostream>
#include "solution.cpp"

int main(){
    int length, width, height;
    std::cout << "Input: \n";
    std::cin >> length >> width >> height;
    std::cout << box_capacity( length, width, height) << std::endl;
}
```

solution.cpp:
```
#include "solution.h"

int box_capacity( int length, int width, int height){
    int count_boxes_in_length_inch {(length*12)/16};
    int count_boxes_in_width_inch {(width*12)/16};
    int count_boxes_in_height_inch {(height*12)/16};
    return count_boxes_in_length_inch * count_boxes_in_width_inch * count_boxes_in_height_inch; 
}
```

CMakeLists:
```
cmake_minimum_required(VERSION 3.10)
project(oop1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)
```
