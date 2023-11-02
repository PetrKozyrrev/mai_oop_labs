# **Лабараторная работа №4**
## **Козырев Пётр Вариант № 12**

## Тема: Основы метапрограммирования

### Цель:
- Изучение основ работы с шаблонами (template) в С++;
- Изучение шаблонов умных указателей

### Задание:

Разработать шаблоны классов согласно варианту задания. Параметром шаблона должен
являться скалярный тип данных задающий тип данных для оси координат. Классы должны иметь
только публичные поля. В классах не должно быть методов, только поля. Фигуры являются
фигурами вращения (равнобедренными), за исключением трапеции и прямоугольника. Для
хранения координат фигур необходимо использовать шаблон std::pair (или реализовать свой
шаблон template <class T> Point в качестве параметра шаблона должен быть тип для переменных
координат)

Разработать классы согласно варианту задания, классы должны наследоваться от базового
класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор
общих методов:
1. Вычисление геометрического центра фигуры вращения;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3. Вычисление площади фигуры;
Создать программу, которая позволяет:
• Запрещается использовать сырые указатели
• Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
• Сохранять созданные фигуры в динамический массив (переиспользовать от
предыдущей лабораторной работы) умных указатели на фигуру
(std::smart_ptr<Figure*>)

• Динамический массив должен быть сделан в виде шаблона (параметр шаблона – класс
для хранения в массиве template <class T> Array {...})
• Фигуры должны иметь переопределенные операции копирования, сравнения и
приведение к типу double (вычисление площади)
• Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для
каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
• Необходимо уметь вычислять общую площадь фигур в массиве.
• Удалять из массива фигуру по индексу;

Вариант 12:
Фигура №1: Трапеция,
Фигура №2: Ромб,
Фигура №3: 5-угольник

### Решение:

Figure.h
```cpp

#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure{
   public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual explicit operator double() const = 0;
};

#endif // FIGURE_H

```

Trapezoid.h
```cpp

#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <cmath>
#include "Figure.h"

template <class T>
class Trapezoid : public Figure{
public:

    using ptt = std::pair<T,T>;

    ptt _c1, _c2, _c3, _c4;

    Trapezoid() = default;
    Trapezoid(ptt a, ptt b, ptt c, ptt d) : _c1(a), _c2(b), _c3(c), _c4(d){};
    Trapezoid(const Trapezoid<T> &other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    Trapezoid(const Trapezoid<T> &&other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    ~Trapezoid() = default;

    Trapezoid<T>& operator=(const Trapezoid<T>& other);

    Trapezoid<T>& operator=(const Trapezoid<T>&& other);

    bool operator==(const Trapezoid<T>& other);

    explicit operator double() const override{
        T _x1 = this->_c1.first, _x2 = this->_c2.first,_x3 = this->_c3.first, _x4 = this->_c4.first;
        T _y1 = this->_c1.second, _y2 = this->_c2.second,_y3 = this->_c3.second, _y4 = this->_c4.second;
        double bottom_base { sqrt((_x4 - _x1) * (_x4 - _x1) + (_y4 - _y1) * (_y4 - _y1))};
        double top_base { sqrt((_x3 - _x2) * (_x3 - _x2) + (_y3 - _y2) * (_y3 - _y2))};

        T h {std::max(_y2 - _y1, _y3 - _y4)};

        return 0.5 * (bottom_base + top_base) * h;
    } 
};

template <class T>
std::ostream& operator<<(std::ostream &out, const Trapezoid<T> &tr){
    out << "TRAPEZOID:" << std::endl 
    << "1-я вершина: ( " << tr._c1.first << ", " << tr._c1.second << " )" << std::endl 
    << "2-я вершина: ( " << tr._c2.first << ", " << tr._c2.second << " )" << std::endl
    << "3-я вершина: ( " << tr._c3.first << ", " << tr._c3.second << " )" << std::endl
    << "4-я вершина: ( " << tr._c4.first << ", " << tr._c4.second << " )" << std::endl;

    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, Trapezoid<T> &tr){
    using ptt = std::pair<T,T>;
    
    std::cout << "Trapezoid INPUT: " <<std::endl; 
    ptt a,b,c,d;
    in >> a.first >> a.second;
    in >> b.first >> b.second;
    in >> c.first >> c.second;
    in >> d.first >> d.second;

    tr._c1 = a;
    tr._c2 = b;
    tr._c3 = c;
    tr._c4 = d;

    return in;
}

template <class T>
inline Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid<T>& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid<T>&& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline bool Trapezoid<T>::operator==(const Trapezoid<T>& other){
    if(_c1 == other._c1 and _c2 == other._c2 and _c3 == other._c3 and _c4 == other._c4){
        return true;
    }
    return false;
}

#endif // TRAPEZOID_H

```

Array.h
```cpp

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>

#include "Functions.h"

template <class T>
class Array{
public:
    Array();

    Array(int size);

    Array(const std::initializer_list<T> &t);

    Array(const Array &other);

    Array(Array &&other);

    ~Array();

    T& operator[](size_t index);

    Array<T>& operator=(Array<T>& other);

    Array<T>& operator=(Array<T>&& other);

    bool operator==(Array<T>&other);

    size_t size() const;

    void delete_elem(int index);

    void push_back(const T& elem);

    double sum() const;

private:
    size_t _size;
    size_t _capable;
    std::shared_ptr<T[]> _array;
};

template <class T>
inline Array<T>::Array(){
    _capable = 10;
    _size = 0;
    _array = std::shared_ptr<T[]>(new T[_capable]);

    for (size_t i{0}; i < _capable; ++i)
        _array[i] = nullptr;
}

template <class T>
inline Array<T>::Array(int size) {
    _capable = size * 2;
    _size = 0;
    _array = std::shared_ptr<T[]>(new T[_capable]);

    for (size_t i = 0; i != _capable; ++i)
        _array[i] = nullptr;
}

template <class T>
inline Array<T>::Array(const std::initializer_list<T> &t){
    _size = t.size();
    _capable = _size * 2;
    _array = std::shared_ptr<T[]>(new T[_capable]);
    size_t i{0};
    for (auto &c : t)
        _array[i++] = c;
    
    for (size_t i{_size}; i < _capable; ++i){
        _array[i++] = nullptr;
    }
}

template <class T>
inline Array<T>::Array(const Array &other){
    _capable = other._capable;
    _size = other._size;   
    _array = std::shared_ptr<T[]>(new T[_capable]);

    for (size_t i{0}; i < _size; ++i)
        _array[i] = other._array[i];
}

template <class T>
inline Array<T>::Array(Array &&other){
    _capable = other._capable;
    _size = other._size;
    _array = other._array;

    other._capable = 0;
    other._size = 0;
    other._array = nullptr;
}

template <class T>
inline T& Array<T>::operator[](size_t index){
    if (index >= _size)
        throw std::invalid_argument("The array index is out of range");
    return _array[index];
}

template <class T>
inline Array<T>& Array<T>::operator=(Array<T>& other){
    _capable = other._capable;
    _size = other._size;
    for(size_t i{0}; i < _size; ++i){
        _array[i] = other._array[i];
    }
    for(size_t i{_size}; i < _capable; ++i){
        _array[i] = nullptr;
    }

    return *this;
}

template <class T>
inline Array<T>& Array<T>::operator=(Array<T>&& other){
    _capable = other._capable;
    _size = other._size;
    for(size_t i{0}; i < _size; ++i){
        _array[i] = other._array[i];
    }
    for(size_t i{_size}; i < _capable; ++i){
        _array[i] = nullptr;
    }

    other.~Array();

    return *this;
}

template <class T>
inline bool Array<T>::operator==(Array<T>& other){
    if(_size == other._size){
        for(size_t i{0}; i < _size; ++i){
            if(_array[i] != other._array[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class T>
inline size_t Array<T>::size() const{
    return _size;
}

template <class T>
inline void Array<T>::delete_elem(int index){
    for(int i{index}; i < _size - 1; ++i){
        _array[i] = _array[i + 1];
    }
    _array[_size - 1] = nullptr;
    --_size;
}

template <class T>
inline void Array<T>::push_back(const T& elem){
    if(_size == _capable){
        _capable *= 2;
        std::shared_ptr<T[]> tmp = std::shared_ptr<T[]>(new T[_capable]);
        for(size_t i{0}; i < _size; ++i){
            tmp[i] = _array[i];
        }
        for(size_t i{_size}; i < _capable; ++i){
            tmp[i] = nullptr;
        }
        _array = tmp;
        _array[_size++] = elem;
    }
    else{
        _array[_size++] = elem;
    }
}

template <class T>
inline double Array<T>::sum() const{
    double sm{0.0};

    for(size_t i{0}; i < _size; ++i){
        sm += (double)(*_array[i]);
    }

    return sm;
}

template <class T>
inline Array<T>::~Array(){
    _size = 0;
    _capable = 0;
}

#endif // ARRAY_H

```

Functions.h
```cpp

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <memory>
#include <algorithm>

#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

template <class C, class T>
void get_center(C& elem){

    T x_center = (elem._c4.first - elem._c1.first) / 2;
    T y_center = (elem._c3.second - elem._c1.second) / 2;

    std::cout << "Center - (" << x_center << ", " << y_center << ")" << std::endl;
}

template<> void get_center<Pentagon<int>,int>(Pentagon<int>& elem){

    int x_center = (elem._c5.first - elem._c1.first) / 2;
    int y_center = (elem._c3.second - elem._c1.second) / 2;

    std::cout << "Center PENT int - (" << x_center << ", " << y_center << ")" << std::endl;
}

template<> void get_center<Pentagon<double>,double>(Pentagon<double>& elem){

    double x_center = (elem._c5.first - elem._c1.first) / 2;
    double y_center = (elem._c3.second - elem._c1.second) / 2;

    std::cout << "Center PENT double - (" << x_center << ", " << y_center << ")" << std::endl;
}

template <class T>
void print(T& elem){
    std::cout << elem << std::endl;
}

template <class C, class T>
double square(C& elem){
    T _x1 = elem._c1.first, _x2 = elem._c2.first,_x3 = elem._c3.first, _x4 = elem._c4.first;
    T _y1 = elem._c1.second, _y2 = elem._c2.second,_y3 = elem._c3.second, _y4 = elem._c4.second;
    double bottom_base { sqrt((_x4 - _x1) * (_x4 - _x1) + (_y4 - _y1) * (_y4 - _y1))};
    double top_base { sqrt((_x3 - _x2) * (_x3 - _x2) + (_y3 - _y2) * (_y3 - _y2))};

    T h {std::max(_y2 - _y1, _y3 - _y4)};

    return 0.5 * (bottom_base + top_base) * h;
}

#endif // FUNCTIONS_H

```

main.cpp
```cpp

#include <iostream>
#include <memory>

#include "Array.h"
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Functions.h"

#define pii std::pair<int,int>

int main(){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    Pentagon<int> d(pii(0,0),pii(0,0),pii(0,0),pii(0,0),pii(0,0));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);
    std::shared_ptr<Pentagon<int>> d_ptr = std::make_shared<Pentagon<int>>(Pentagon<int>(pii(0,0),pii(0,0),pii(0,0),pii(0,0),pii(0,0)));

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};    

    arr.push_back(d_ptr);

    for(int i{0}; i < arr.size(); ++i){

        Figure* el = arr[i].get();

        if (el == nullptr) {
            std::cout << "The figure has been deleted" << std::endl;
        } 
        else if (typeid(Trapezoid<int>) == typeid(*el)) {
            get_center<Trapezoid<int>, int>(*(Trapezoid<int>*)el);

            print<Trapezoid<int>>(*(Trapezoid<int>*)el);

            std::cout << "Square Trapezoid = " << square<Trapezoid<int>, int>(*(Trapezoid<int>*)el) << std::endl;

        } 
        else if (typeid(Rhombus<int>) == typeid(*el)) {
            get_center<Rhombus<int>, int>(*(Rhombus<int>*)el);

            print<Rhombus<int>>(*(Rhombus<int>*)el);

            std::cout << "Square Rhombus = " << square<Rhombus<int>, int>(*(Rhombus<int>*)el) << std::endl;
        } 
        else if (typeid(Pentagon<int>) == typeid(*el)) {
            get_center<Pentagon<int>, int>(*(Pentagon<int>*)el);

            print<Pentagon<int>>(*(Pentagon<int>*)el);

            std::cout << "Square Pentagon = " << square<Pentagon<int>, int>(*(Pentagon<int>*)el) << std::endl;
        }
    }

    std::cout << "Common Square = " << arr.sum() << std::endl;
}

```

tests.cpp
```cpp

#include <gtest/gtest.h>

#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"
#include "Functions.h"

#define pii std::pair<int,int>
#define pdd std::pair<double,double>

// Trapezoid

TEST(trapezoid_test01, empty_constructor_int){
    Trapezoid<int> a;

    double sm = square<Trapezoid<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(trapezoid_test02, four_points_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    double sm = square<Trapezoid<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(trapezoid_test03, copy_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Trapezoid<int> b(a);

    double sm = square<Trapezoid<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test04, move_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Trapezoid<int> b(std::move(a));

    double sm = square<Trapezoid<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test05, copy_int){
    Trapezoid<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Trapezoid<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(trapezoid_test06, move_copy_int){
    Trapezoid<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Trapezoid<int> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

TEST(trapezoid_test07, empty_constructor_double){
    Trapezoid<double> a;

    double sm = square<Trapezoid<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(trapezoid_test08, four_points_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));

    double sm = square<Trapezoid<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(trapezoid_test09, copy_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Trapezoid<double> b(a);

    double sm = square<Trapezoid<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test10, move_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Trapezoid<double> b(std::move(a));

    double sm = square<Trapezoid<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(trapezoid_test11, copy_double){
    Trapezoid<double> a(pdd(1.0,1.0),pii(2.0,2.0),pii(3.0,3.0),pii(4.0,4.0));
    Trapezoid<double> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(trapezoid_test12, move_copy_double){
    Trapezoid<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0));
    Trapezoid<double> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

// Rhombus

TEST(rhombus_test01, empty_constructor_int){
    Rhombus<int> a;

    double sm = square<Rhombus<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(Rhombus_test02, four_points_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    double sm = square<Rhombus<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Rhombus_test03, copy_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(a);

    double sm = square<Rhombus<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test04, move_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(std::move(a));

    double sm = square<Rhombus<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test05, copy_int){
    Rhombus<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Rhombus<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Rhombus_test06, move_copy_int){
    Rhombus<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Rhombus<int> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

TEST(Rhombus_test07, empty_constructor_double){
    Rhombus<double> a;

    double sm = square<Rhombus<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(Rhombus_test08, four_points_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));

    double sm = square<Rhombus<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Rhombus_test09, copy_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Rhombus<double> b(a);

    double sm = square<Rhombus<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test10, move_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));
    Rhombus<double> b(std::move(a));

    double sm = square<Rhombus<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Rhombus_test11, copy_double){
    Rhombus<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0));
    Rhombus<double> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Rhombus_test12, move_copy_double){
    Rhombus<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0));
    Rhombus<double> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

// Pentagon

TEST(Pentagon_test01, empty_constructor_int){
    Pentagon<int> a;

    double sm = square<Pentagon<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(Pentagon_test02, four_points_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));

    double sm = square<Pentagon<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Pentagon_test03, copy_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));
    Pentagon<int> b(a);

    double sm = square<Pentagon<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test04, move_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));
    Pentagon<int> b(std::move(a));

    double sm = square<Pentagon<int>,int>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test05, copy_int){
    Pentagon<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4),pii(0,0));
    Pentagon<int> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Pentagon_test06, move_copy_int){
    Pentagon<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4),pii(0,0));
    Pentagon<int> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

TEST(Pentagon_test07, empty_constructor_double){
    Pentagon<double> a;

    double sm = square<Pentagon<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(Pentagon_test08, four_points_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));

    double sm = square<Pentagon<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(Pentagon_test09, copy_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));
    Pentagon<double> b(a);

    double sm = square<Pentagon<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test10, move_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));
    Pentagon<double> b(std::move(a));

    double sm = square<Pentagon<double>,double>(b);

    EXPECT_TRUE(b == a);
    EXPECT_EQ(sm,100);
}

TEST(Pentagon_test11, copy_double){
    Pentagon<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0),pdd(0.0,0.0));
    Pentagon<double> b;

    b = a;
    EXPECT_TRUE(a == b);
}

TEST(Pentagon_test12, move_copy_double){
    Pentagon<double> a(pdd(1.0,1.0),pdd(2.0,2.0),pdd(3.0,3.0),pdd(4.0,4.0),pdd(0.0,0.0));
    Pentagon<double> b;

    b = std::move(a);
    EXPECT_TRUE(a == b);
}

// Array

TEST(array_test01, empty_constructor){
    Array<std::shared_ptr<Figure>> arr;

    EXPECT_EQ(arr.size(), 0);
}

TEST(array_test02, size_constructor){
    Array<std::shared_ptr<Figure>> arr(2);

    EXPECT_EQ(arr.size(), 0);

    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);

    arr.push_back(a_ptr);

    EXPECT_EQ(arr.size(), 1);
}

TEST(array_test03, list_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_EQ(arr.size(), 3);
}

TEST(array_test04, copy_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

   Array<std::shared_ptr<Figure>> brr(arr);

    EXPECT_EQ(brr.size(), 3);
    EXPECT_TRUE(arr == brr);
}

TEST(array_test05, move_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

   Array<std::shared_ptr<Figure>> brr(std::move(arr));

    EXPECT_EQ(brr.size(), 3);
}

TEST(array_test06, sum_array){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_TRUE(arr.sum() <= 28668 and arr.sum() >= 28667);
}

TEST(array_test07, empty_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_EQ(arr.size(), 3);

    arr.delete_elem(0);

    EXPECT_EQ(arr.size(), 2);

    arr.delete_elem(0);

    EXPECT_EQ(arr.size(), 1);
}


```