# **Лабараторная работа №3**
## **Козырев Пётр Вариант №12**

## Тема: Наследование, полиморфизм

### Цель:
- Изучение механизмов работы с наследованием в С++;
- Изучение механизма перегрузки операций

### Задание:

Разработать классы согласно варианту задания, классы должны наследоваться от базового
класса Figure. Фигуры являются фигурами вращения.
Все классы должны поддерживать набор общих методов:
1. Вычисление геометрического центра фигуры вращения;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры через
перегрузку оператора << для std::ostream;
3. Чтение из стандартного потока данных фигур через перегрузку оператора >> для
std::istream
4. Вычисление площади фигуры через перегрузку оператора приведения к типу double;

Создать программу, которая позволяет:
- Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
- Сохранять созданные фигуры в динамический массив (по аналогии с предыдущей
лабораторной работой Array) указатели на фигуру (Figure*)
- Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и
сравнения (==)
- Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для
каждой фигуры в массиве геометрический центр и площадь.
- Необходимо уметь вычислять общую площадь фигур в массиве.
- Удалять из массива фигуру по индексу;

Вариант 12:
Фигура №1: Трапеция,
Фигура №2: Ромб,
Фигура №3: 5-угольник

### Решение:

main.cpp
```cpp

#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

int main(){
    
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    //Array arr{&a,&b,&c};

    Array arr;
    arr.push_back(new Trapezoid(0,0,0,10,10,10,0,10));
    arr.push_back(new Rhombus (0,0,0,10,10,10,10,0));
    arr.push_back(new Pentagon (0,0,-3,10,5,20,8,5,0,10));
    arr.push_back(&a);
    
    for(int i{0}; i < arr.len(); ++i){
        arr[i]->print();
        std::cout << arr[i]->square() << std::endl;
        arr[i]->get_center();
        std::cout << "-------------------------" << std::endl;
    }

     std::cout << "Общая площадь = " << arr.sum_square() << std::endl;

    arr.delete_elem(1);

    std::cout << "DELETE RHOMBUS" << std::endl;

    for(int i{0}; i < arr.len(); ++i){
        arr[i]->print();
        std::cout << arr[i]->square() << std::endl;
        arr[i]->get_center();
        std::cout << "-------------------------" << std::endl;
    }

    std::cout << "Общая площадь = " << arr.sum_square() << std::endl;

}

```

Figure.h
```cpp

#ifndef ARR_H
#define ARR_H
#include "Figure.h"

class Array{
public:

    Array();
    Array(const std::initializer_list<Figure*> &t);
    Array(const Array& other);
    ~Array();

    Figure* operator [] (const int index) const;    // Обращение к элементу по индексу

    void push_back(Figure* figure);                 // Добавить элемент в конец списка

    void delete_elem (const int index);             // Удалить элемент по индексу

    double sum_square () const;                     // Сумма всех площадей

    int len() const;                                // Длина массива

private:
    Figure** arr;
    int size;
};

#endif

```

Figure.cpp
```cpp

#include "Figure.h"

Figure::Figure(): _x1(0.0),_y1(0.0),_x2(0.0),_y2(0.0),_x3(0.0),_y3(0.0),_x4(0.0),_y4(0.0){};

Figure::Figure(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4){
    _x1 = x1; _y1 = y1;
    _x2 = x2; _y2 = y2;
    _x3 = x3; _y3 = y3;
    _x4 = x4; _y4 = y4;
};

Figure::Figure(const Figure& other){
    _x1 = other._x1; _y1 = other._y1;
    _x2 = other._x2; _y2 = other._y2;
    _x3 = other._x3; _y3 = other._y3;
    _x4 = other._x4; _y4 = other._y4;
};

Figure& Figure::operator = (const Figure& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

Figure& Figure::operator = (Figure&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

bool Figure::operator == (Figure& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4){
        return true;
    }
    return false;
}

std::ostream& operator << (std::ostream& out,const Figure& fig){
    out << "FIGURE:" << std::endl 
    << "1-я вершина: ( " << fig._x1 << ", " << fig._y1 << " )" << std::endl 
    << "2-я вершина: ( " << fig._x2 << ", " << fig._y2 << " )" << std::endl
    << "3-я вершина: ( " << fig._x3 << ", " << fig._y3 << " )" << std::endl
    << "4-я вершина: ( " << fig._x4 << ", " << fig._y4 << " )" << std::endl;
    return out;
}

std::istream& operator >> (std::istream& in, Figure& fig){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "FIGURE INPUT: " << std::endl;

    std::cout << "Введите 1-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x1;
    std::cout << " y: ";
    in >> y1;
    std::cout << std::endl;

    std::cout << "Введите 2-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x2;
    std::cout << " y: ";
    in >> y2;
    std::cout << std::endl;
    
    std::cout << "Введите 3-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x3;
    std::cout << " y: ";
    in >> y3;
    std::cout << std::endl;

    std::cout << "Введите 4-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x4;
    std::cout << " y: ";
    in >> y4;
    std::cout << std::endl;

    fig._x1 = x1;
    fig._x2 = x2;
    fig._x3 = x3;
    fig._x4 = x4;

    fig._y1 = y1;
    fig._y2 = y2;
    fig._y3 = y3;
    fig._y4 = y4;

    return in;
}

Figure::~Figure(){};

```

Trapezoid.h
```cpp

#ifndef TRAP_H
#define TRAP_H
#include "Figure.h"

class Trapezoid: public Figure{

    friend std::ostream& operator << (std::ostream& out, const Trapezoid& tr);
    friend std::istream& operator >> (std::istream& in, Trapezoid& tr);

    using Figure::Figure;

public:

    Trapezoid(const Trapezoid& other);

    explicit operator double()const  override{
        return this->square();
    };

    Trapezoid& operator = (const Trapezoid& other);

    Trapezoid& operator = (Trapezoid&& other);

    bool operator == (Trapezoid& other);

    void print() const override;

    double square() const override;

    virtual void get_center() const override;

};

#endif

```

Trapezoid.cpp
```cpp

#include <algorithm>
#include "Trapezoid.h"

Trapezoid::Trapezoid(const Trapezoid& other)
    : Figure(other._x1, other._y1, other._x2, other._y2, other._x3, other._y3, other._x4, other._y4){};


Trapezoid& Trapezoid::operator = (const Trapezoid& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

Trapezoid& Trapezoid::operator = (Trapezoid&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

bool Trapezoid::operator == (Trapezoid& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4){
        return true;
    }
    return false;
}

std::ostream& operator << (std::ostream& out, const Trapezoid& tr){
    out << "TRAPEZOID:" << std::endl 
    << "1-я вершина: ( " << tr._x1 << ", " << tr._y1 << " )" << std::endl 
    << "2-я вершина: ( " << tr._x2 << ", " << tr._y2 << " )" << std::endl
    << "3-я вершина: ( " << tr._x3 << ", " << tr._y3 << " )" << std::endl
    << "4-я вершина: ( " << tr._x4 << ", " << tr._y4 << " )" << std::endl;
    return out;
}

std::istream& operator >> (std::istream& in, Trapezoid& tr){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "TRAPEZOID INPUT: " << std::endl;

    std::cout << "Введите 1-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x1;
    std::cout << " y: ";
    in >> y1;
    std::cout << std::endl;

    std::cout << "Введите 2-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x2;
    std::cout << " y: ";
    in >> y2;
    std::cout << std::endl;
    
    std::cout << "Введите 3-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x3;
    std::cout << " y: ";
    in >> y3;
    std::cout << std::endl;

    std::cout << "Введите 4-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x4;
    std::cout << " y: ";
    in >> y4;
    std::cout << std::endl;

    tr._x1 = x1;
    tr._x2 = x2;
    tr._x3 = x3;
    tr._x4 = x4;

    tr._y1 = y1;
    tr._y2 = y2;
    tr._y3 = y3;
    tr._y4 = y4;

    return in;
}

void Trapezoid::print() const{
    std::cout << "TRAPEZOID:" << std::endl 
    << "1-я вершина: ( " << _x1 << ", " << _y1 << " )" << std::endl 
    << "2-я вершина: ( " << _x2 << ", " << _y2 << " )" << std::endl
    << "3-я вершина: ( " << _x3 << ", " << _y3 << " )" << std::endl
    << "4-я вершина: ( " << _x4 << ", " << _y4 << " )" << std::endl;
}

double Trapezoid::square() const{

    // Нижнее основание трапеции
    double bottom_base { sqrt((_x4 - _x1) * (_x4 - _x1) + (_y4 - _y1) * (_y4 - _y1))};

    // Верхнее основание трапеции
    double top_base { sqrt((_x3 - _x2) * (_x3 - _x2) + (_y3 - _y2) * (_y3 - _y2))};

    // Высота трапеции
    double h { std::max(_y2 - _y1, _y3 - _y4)};

    // Площадь трапеции это полусумма оснований на высоту
    return 0.5 * (bottom_base + top_base) * h;
}

void Trapezoid::get_center() const{

    // Середина нижнего основания трапеции
    double bottom_center_x { 0.5 * (_x4 - _x1)};
    double bottom_center_y { 0.5 * (_y4 - _y1)};

    // Середина верхнего основания трапеции
    double top_center_x { 0.5 * (_x3 - _x2)};
    double top_center_y { 0.5 * (_y3 - _y2)};

    // Длина нижнего основания
    double len_bottom { sqrt(bottom_center_x * bottom_center_x + bottom_center_y * bottom_center_y)};

    // Длина верхнего основания
    double len_top = sqrt(top_center_x * top_center_x + top_center_y * top_center_y);
    
    // Диагонали трапеции разбивают ее на 2 подобных треугольника с коэфициентом подобия k
    double k { len_bottom / len_top};

    // Геометрический центр трапеции
    double res_x { 0.5 * abs(top_center_x - bottom_center_x)};
    double res_y { bottom_center_y + (k * (top_center_y + top_center_y * k) / (k+1))};

    std::cout << "Trapezoid center - ( " << res_x << ", " << res_y << " )" << std::endl;
}

```

Rhombus.h
```cpp

#ifndef RHOBM_H
#define RHOMB_H
#include "Figure.h"

class Rhombus : public Figure{

    friend std::ostream& operator << (std::ostream& out, const Rhombus& rmb);
    friend std::istream& operator >> (std::istream& in, Rhombus& rmb);

    using Figure::Figure;

public:

    Rhombus(const Rhombus& other);

    explicit operator double()const  override{
        return this->square();
    };

    Rhombus& operator = (const Rhombus& other);

    Rhombus& operator = (Rhombus&& other);

    bool operator == (Rhombus& other);

    void print() const override;

    double square() const override;

    virtual void get_center() const override;
};

#endif

```

Rhombus.cpp
```cpp

#include "Rhombus.h"

Rhombus::Rhombus(const Rhombus& other): Figure(other._x1, other._y1, other._x2, other._y2, other._x3, other._y3, other._x4, other._y4){};

Rhombus& Rhombus::operator = (const Rhombus& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

Rhombus& Rhombus::operator = (Rhombus&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

bool Rhombus::operator == (Rhombus& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4){
        return true;
    }
    return false;
}

std::ostream& operator << (std::ostream& out, const Rhombus& rmb){
    out << "RHOMBUS:" << std::endl 
    << "1-я вершина: ( " << rmb._x1 << ", " << rmb._y1 << " )" << std::endl 
    << "2-я вершина: ( " << rmb._x2 << ", " << rmb._y2 << " )" << std::endl
    << "3-я вершина: ( " << rmb._x3 << ", " << rmb._y3 << " )" << std::endl
    << "4-я вершина: ( " << rmb._x4 << ", " << rmb._y4 << " )" << std::endl;
    return out;
}

std::istream& operator >> (std::istream& in, Rhombus& rmb){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "RHOMBUS INPUT: " << std::endl;

    std::cout << "Введите 1-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x1;
    std::cout << " y: ";
    in >> y1;
    std::cout << std::endl;

    std::cout << "Введите 2-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x2;
    std::cout << " y: ";
    in >> y2;
    std::cout << std::endl;
    
    std::cout << "Введите 3-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x3;
    std::cout << " y: ";
    in >> y3;
    std::cout << std::endl;

    std::cout << "Введите 4-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x4;
    std::cout << " y: ";
    in >> y4;
    std::cout << std::endl;

    rmb._x1 = x1;
    rmb._x2 = x2;
    rmb._x3 = x3;
    rmb._x4 = x4;

    rmb._y1 = y1;
    rmb._y2 = y2;
    rmb._y3 = y3;
    rmb._y4 = y4;

    return in;
}

void Rhombus::print() const{
    std::cout << "RHOMBUS:" << std::endl 
    << "1-я вершина: ( " << _x1 << ", " << _y1 << " )" << std::endl 
    << "2-я вершина: ( " << _x2 << ", " << _y2 << " )" << std::endl
    << "3-я вершина: ( " << _x3 << ", " << _y3 << " )" << std::endl
    << "4-я вершина: ( " << _x4 << ", " << _y4 << " )" << std::endl;
}

double Rhombus::square() const{

    // Длина первой диагонали
    double diag_1 { sqrt((_x3 - _x1) * (_x3 - _x1) + (_y3 - _y1) * (_y3 - _y1))};

    // Длина второй диагонали
    double diag_2 { sqrt((_x4 - _x2) * (_x4 - _x2) + (_y4 - _y2) * (_y4 - _y2))};

    // Площадь ромба равна полупризведению диагоналей
    return 0.5 * diag_1 * diag_2;
}

void Rhombus::get_center() const{
    double center_x { 0.5 * (_x4 - _x2)};
    double center_y { 0.5 * (_y3 - _y1)};

    std::cout << "Rhombus center - ( " << center_x << ", " << center_y << " )" << std::endl;
}

```

Pentagon.h
```cpp

#ifndef PENTG_H
#define PENTG_H
#include "Figure.h"

class Pentagon : public Figure{
    
    friend std::ostream& operator << (std::ostream& out, const Pentagon& pnt);
    friend std::istream& operator >> (std::istream& in, Pentagon& pnt);

    using Figure::Figure;

public:

    Pentagon();

    Pentagon(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4,double x5, double y5);

    Pentagon(const Pentagon& other);

    ~Pentagon();

    explicit operator double()const override{
        return this->square();
    }

    Pentagon& operator = (const Pentagon& other);

    Pentagon& operator = (Pentagon&& other);

    bool operator == (Pentagon& other);

    void print() const override;

    double square() const override;

    virtual void get_center() const override;

private:

    // Пятая вершина
    double _x5{0.0};
    double _y5{0.0};
};

#endif

```

Pentagon.cpp

```cpp

#include <cmath>
#include "Pentagon.h"

// Константа числа пи
const double PI = acos(-1);

Pentagon::Pentagon(): Figure(), _x5(0.0), _y5(0.0){};

Pentagon::Pentagon(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4,double x5, double y5)
    :Figure(x1, y1, x2, y2, x3, y3, x4, y4), _x5(x5), _y5(y5){};

Pentagon::Pentagon(const Pentagon& other)
    :Figure(other._x1, other._y1, other._x2, other._y2, other._x3, other._y3, other._x4, other._y4), _x5(other._x5), _y5(other._y5){};

Pentagon& Pentagon::operator = (const Pentagon& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
        _x5 = other._x5; _y5 = other._y5;
    }
    return *this;
}

Pentagon& Pentagon::operator = (Pentagon&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
        _x5 = other._x5; _y5 = other._y5;
    }
    return *this;
}

bool Pentagon::operator == (Pentagon& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4 and
       _x5 == other._x5 and _y5 == other._y5){
        return true;
    }
    return false;
}

std::ostream& operator <<(std::ostream& out, const Pentagon& pnt){
    out << "PENTAGON:" << std::endl 
    << "1-я вершина: ( " << pnt._x1 << ", " << pnt._y1 << " )" << std::endl 
    << "2-я вершина: ( " << pnt._x2 << ", " << pnt._y2 << " )" << std::endl
    << "3-я вершина: ( " << pnt._x3 << ", " << pnt._y3 << " )" << std::endl
    << "4-я вершина: ( " << pnt._x4 << ", " << pnt._y4 << " )" << std::endl
    << "5-я вершина: ( " << pnt._x5 << ", " << pnt._y5 << " )" << std::endl;
    return out;
}

std::istream& operator >>(std::istream& in, Pentagon& pnt){
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

    std::cout << "PENTAGON INPUT: " << std::endl;

    std::cout << "Введите 1-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x1;
    std::cout << " y: ";
    in >> y1;
    std::cout << std::endl;

    std::cout << "Введите 2-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x2;
    std::cout << " y: ";
    in >> y2;
    std::cout << std::endl;
    
    std::cout << "Введите 3-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x3;
    std::cout << " y: ";
    in >> y3;
    std::cout << std::endl;

    std::cout << "Введите 4-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x4;
    std::cout << " y: ";
    in >> y4;
    std::cout << std::endl;

    std::cout << "Введите 5-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x5;
    std::cout << " y: ";
    in >> y5;
    std::cout << std::endl;

    pnt._x1 = x1;
    pnt._x2 = x2;
    pnt._x3 = x3;
    pnt._x4 = x4;
    pnt._x5 = x5;

    pnt._y1 = y1;
    pnt._y2 = y2;
    pnt._y3 = y3;
    pnt._y4 = y4;
    pnt._y5 = y5;

    return in;
}

void Pentagon::print() const{
    std::cout << "PENTAGON:" << std::endl 
    << "1-я вершина: ( " << _x1 << ", " << _y1 << " )" << std::endl 
    << "2-я вершина: ( " << _x2 << ", " << _y2 << " )" << std::endl
    << "3-я вершина: ( " << _x3 << ", " << _y3 << " )" << std::endl
    << "4-я вершина: ( " << _x4 << ", " << _y4 << " )" << std::endl
    << "5-я вершина: ( " << _x5 << ", " << _y5 << " )" << std::endl;
}

double Pentagon::square() const{

    /*
        Площадь правильного пятиугольника это сумма площадей пяти треугольников
        с основанием равным стороне пятицгольника. Если провести в нем высоту,
        то получится угол в 36 градусов. Через тангенс угла легко найти высоту и площадь.
    */

    // Сторона правильного пятиугольника
    double size { sqrt((_x5 - _x1) * (_x5 - _x1) + (_y5 - _y1) * (_y5 - _y1))};

    // Высота треугольнка
    double h { (size * 0.5) / (tan(PI/5))};

    return 5 * (0.5 * h * size);
}

void Pentagon::get_center() const{
    double center_x { (_x5 - _x1) * 0.5};
    double center_y { (_y3 - _y1) * 0.5};

    std::cout << "Pentagon center - ( " << center_x << ", " << center_y << " )" << std::endl;
}

Pentagon::~Pentagon(){};

```

Array.h
```cpp

#ifndef ARR_H
#define ARR_H
#include "Figure.h"

class Array{
public:

    Array();
    Array(const std::initializer_list<Figure*> &t);
    Array(const Array& other);
    ~Array();

    Figure* operator [] (const int index) const;    // Обращение к элементу по индексу

    void push_back(Figure* figure);                 // Добавить элемент в конец списка

    void delete_elem (const int index);             // Удалить элемент по индексу

    double sum_square () const;                     // Сумма всех площадей

    int len() const;                                // Длина массива

private:
    Figure** arr;
    int size;
};

#endif

```

Array.cpp
```cpp

#include <cstring>
#include <memory>
#include <algorithm>
#include "Array.h"

Array::Array(): size(0), arr(nullptr){};

Array::Array(const std::initializer_list<Figure*> &t){
    arr = new Figure*[t.size()];
    int i{0};
    for (auto elem : t){
        arr[i++] = elem;
    }
    size = t.size();
};

Array::Array(const Array& other){
    size = other.size;
    arr = new Figure* [size];

    for(int i{0}; i < size; ++i){
        arr[i] = other.arr[i];
    }
}

void Array::push_back(Figure* figure) {
    Figure** temp = new Figure*[size + 1];
    for (int i{0}; i < size; ++i) {
        temp[i] = arr[i];
    }
    temp[size] = figure;
    
    delete[] arr;
    arr = temp;
    ++size;
}

Figure* Array::operator [] (const int index) const{
    return arr[index];
}

void Array::delete_elem (const int index){
    for (int i{index}; i< size-1; ++i){
        arr[i] = arr[i + 1];
    }
    --size;
}

double Array::sum_square () const{
    double sm{0.0};

    for(int i{0}; i < size; ++i){
        sm += arr[i]->square();
    }

    return sm;
}

int Array::len () const{
    return size;
}

Array::~Array(){
    if(size > 0){
        size = 0;
        delete[] arr;
        arr = nullptr;
    }
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

// Trapezoid
TEST(trapezoid_test01, based_test)
{
    Trapezoid a;
    Trapezoid b(0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(trapezoid_test02, based_test)
{
    Trapezoid a(0,0,0,10,10,10,10,0);
    Trapezoid b(a);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(100,a.square());
    EXPECT_EQ(100,b.square());
}

TEST(trapezoid_test03, based_test)
{
    Trapezoid a(0,0,3,8,10,8,17,0);

    EXPECT_EQ(96,a.square());
}

TEST(trapezoid_test04, based_test)
{
    Trapezoid a(1,1,2,2,5,2,7,0);
    Trapezoid b;

    b = a;

    EXPECT_TRUE(a == b);
}

// Rhombus
TEST(rhombus_test01, based_test)
{
    Rhombus a;
    Rhombus b(0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(rhombus_test02, based_test)
{
    Rhombus a(0,0,-5,10,0,20,5,10);

    EXPECT_EQ(100,a.square());
}

// Pentagon
TEST(pentagon_test01, based_test)
{
    Pentagon a;
    Pentagon b(0,0,0,0,0,0,0,0,0,0);

    EXPECT_TRUE(a == b);
    EXPECT_EQ(0,a.square());
    EXPECT_EQ(0,b.square());
}

TEST(pentagon_test02, based_test)
{
    Pentagon a(0,0,-2.16,6.66,3.5,10.77,9.16,6.66,7,0);

    EXPECT_TRUE(a.square() >= 84 and a.square()<85);
}


// Array

TEST(array_test01, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr{&a,&b,&c};

    EXPECT_TRUE(arr.sum_square() >= 372 and arr.sum_square() < 373);
}

TEST(array_test02, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr{&a,&b,&c};

    EXPECT_EQ(3, arr.len());
}

TEST(array_test03, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr{&a,&b,&c};

    EXPECT_TRUE(&a == arr[0]);
}

TEST(array_test04, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr;

    arr.push_back(&a);
    arr.push_back(&b);
    arr.push_back(&c);

    EXPECT_TRUE(arr.sum_square() >= 372 and arr.sum_square() < 373);
}

TEST(array_test05, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr;

    arr.push_back(&a);
    arr.push_back(&b);
    arr.push_back(&c);

    EXPECT_EQ(3, arr.len());
}

TEST(array_test06, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr;

    arr.push_back(&a);
    arr.push_back(&b);
    arr.push_back(&c);

    EXPECT_TRUE(&a == arr[0]);
}

TEST(array_test07, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);

    Array arr;

    arr.push_back(&a);
    arr.push_back(&b);

    arr.delete_elem(1);

    EXPECT_EQ(1, arr.len());
}

TEST(array_test08, based_test)
{
    Trapezoid a(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);

    Array arr;

    arr.push_back(&a);
    arr.push_back(&b);

    arr.delete_elem(1);

    EXPECT_EQ(100, arr.sum_square());
}

```

CMakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
project(oop3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(input)
include_directories(scr)

set(SOURCES scr/Figure.cpp scr/Trapezoid.cpp scr/Rhombus.cpp scr/Pentagon.cpp scr/Array.cpp)

add_executable(app main.cpp ${SOURCES})

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp ${SOURCES})

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)

```