# **Лабараторная работа №2**
## **Козырев Пётр Вариант №12**

## Тема: Классы

### Цель:
1. Закрепление навыков работы с классами
2. Закрепление навыков работы с динамической памятью на «куче»
3. Закрепление навыков работы с массивами

### Задание:
Создать класс ***Money*** для работы с денежными суммами. Сумма должна быть представлена массивом из элементов типа *unsigned char*, каждый элемент которого – десятичная цифра. Младший индекс соответствует
младшей цифре денежной суммы. Младшие две цифры — копейки.

### Решение:

**money.h**
```
#pragma once

#include <iostream>
#include <string>

class Money
{
public:

    Money();
    Money(const std::initializer_list< unsigned char> &t);
    Money(const std::string &t);
    Money(const Money& other);
    Money(Money&& other) noexcept;
    
    Money add(const Money& other);
    Money remove(const Money& other);
    bool bigger(const Money& other);
    bool equals(const Money& other);
    void print();

    virtual ~Money() noexcept;

private:
    int _size;
    unsigned char *_array;
};
```

**money.cpp**
```
#include <cstring>
#include "money.h"

// Default Constructor
Money::Money(): _size(1)
{
    _array = new unsigned char [1];
    _array[0] = '0';
}

// Initializer list constructor
Money::Money(const std::initializer_list<unsigned char> &t)
{
    _array = new unsigned char[t.size()];
    int i{0};
    for (auto elem : t)
        _array[i++] = elem;
    _size = t.size();
}

// Copy string constructor
Money::Money(const std::string &t)
{
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(int i{0}; i<_size; ++i) _array[i] = t[i];
}

// Copy constructor
Money::Money(const Money &other)
{
    _size  = other._size;
    _array = new unsigned char[_size];

    for(int i{0};i<_size;++i) _array[i] = other._array[i];
}

// Move constructor
Money::Money(Money &&other) noexcept
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

// Равенство двух объектов
bool Money::equals(const Money &other){
    if (_size > other._size){
        return false;
    }
    else if(_size < other._size){
        return false;
    }
    else{
        for(int i{_size-1};i>=0;--i){
            if(_array[i] != other._array[i])
                return false;
        }
    }
    return true;
}

// Сравнение (true если данный объект больше)
bool Money::bigger(const Money &other){
    if (_size > other._size){
        return true;
    }
    else if(_size < other._size){
        return false;
    }
    else{
        for(int i{_size-1};i>=0;--i){
            if(_array[i] > other._array[i])
                return true;
        }
    }
    return false;
}

// Сложение
Money Money::add(const Money &other)
{
    // При сложении может меняться размерность массива
    _size = std::max(_size,other._size);
    unsigned char* _new_array = new unsigned char [_size];
    memcpy(_new_array,_array,_size);

    int tranf{0}; // Остаток

    for(int i{0}; i < _size; ++i){

        if( _new_array[i] < '0' or _new_array[i] > '9') { _new_array[i] = '0';}
        if( other._array[i] < '0' or other._array[i] > '9'){ other._array[i] = '0';}

        int s = (_new_array[i] - '0') + (other._array[i] - '0') + tranf;
        tranf = s/10;
        _new_array[i] = '0' + s%10;
    }

    if(tranf){
        // Если остался остаток, то у числа увелчится разряд
        _array = new unsigned char [_size+1];
        memcpy(_array,_new_array,_size);
        _size++;
        _array[_size-1] = '0' + tranf;
    }
    else{
        _array = new unsigned char [_size+1];
        memcpy(_array,_new_array,_size);
    }

    delete[] _new_array;

    return *this;
}

// Вычитание
Money Money::remove(const Money &other){
    if( this->equals(other)){
        _array[0] = '0';
        _size = 1;
    }
    else if(!this->bigger(other)){
        throw std::logic_error("negative balance");;
    }
    else{
        unsigned char* _new_array = new unsigned char [_size];
        memcpy(_new_array,other._array, other._size);
    
        for(int i{0}; i<_size; i++){

            if(_new_array[i] < '0' or _new_array[i] > '9') {_new_array[i] = '0';}
            
            if(_array[i] >= _new_array[i]){
                // Если уменьшаемое больше вычитаемого
                _array[i] = (_array[i] - _new_array[i]) + '0'; 
            }
            else{
                // Если уменьшаемое меньше вычитаемого
                int tmp_id {i+1};

                while(_array[tmp_id] == '0'){
                    tmp_id++;
                }

                _array[tmp_id] = '0' + (_array[tmp_id] - '1');
                --tmp_id;

                _array[i] = (((_array[i] - '0') - (_new_array[i] - '0')) + 10) + '0';

                while(tmp_id != i){
                    _array[tmp_id] = '9';
                    --tmp_id;
                }
            }
        }

        delete[] _new_array;
        
        while(_array[_size - 1] == '0' and _size > 0){
            --_size;
        }
    }
    return *this;
}

// Печать
void Money::print(){
    if(_size == 1){
        std::cout << "0.0" << _array[0];
    }
    else{
        for(int i{_size-1};i>=0; i--){
            if(i == 1){
                std::cout << '.';
            }
            std::cout<<_array[i];
        }
    }
    std::cout << std::endl;
}

// Деструктор
Money::~Money() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}
```

**tests.cpp**
```
#include <gtest/gtest.h>
#include "money.cpp"

// Constructor

TEST(constructor_test01, default_constructor)
{
    Money a = Money();

    EXPECT_EQ(a.get_size(), 1);
}

TEST(constructor_test02, initializer_list_constructor)
{
    Money a {'1','1','1','1','1'};

    EXPECT_EQ(a.get_size(), 5);
}

TEST(constructor_test03, string_constructor)
{
    std::string str = "11111";
    Money a = Money(str);

    EXPECT_EQ(a.get_size(), 5);
}

TEST(constructor_test04, copy_constructor)
{
    Money first {'1','1','1','1','1'};
    Money second = Money(first);

    EXPECT_EQ(second.get_size(), 5);
}

TEST(constructor_test05, rvalue_constructor)
{
    Money a = {"11111"};

    EXPECT_EQ(a.get_size(), 5);
}

// Operators testing
TEST(o_test01, basic_test_set)
{
    Money a {"001"};
    Money b {'1'};
    Money c {"101"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test02, basic_test_set)
{
    Money a {"00005"};
    Money b {"00005"};
    Money c {"000001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test03, basic_test_set)
{
    Money a {"1111"};
    Money b {"19"};
    Money c {"2021"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test04, basic_test_set)
{
    Money a {'0'};
    Money b {"12345"};
    Money c {"12345"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test05, basic_test_set)
{
    Money a {"990001"};
    Money b {'1'};
    Money c {"001001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test06, basic_test_set)
{
    Money a {"1"};
    Money b {"005"};
    try{
        a.remove(b);
    }catch(std::exception &ex){
        EXPECT_STREQ(ex.what(),"negative balance");
    }
}

TEST(o_test07, basic_test_set)
{
    Money a {"00511"};
    Money b {"0051"};
    Money c {"00001"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(o_test08, basic_test_set)
{
    Money a {"001"};
    Money b {'1'};
    Money c {"99"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(o_test09, basic_test_set)
{
    Money a {"123456"};
    Money b {"123456"};
    Money c {'0'};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(o_test10, basic_test_set)
{
    Money a {"000000001"};
    Money b {'1'};
    Money c {"99999999"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}
```

**CMakeLists.txt**
```
cmake_minimum_required(VERSION 3.10)
project(oop2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app main.cpp money.cpp)

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)

```
