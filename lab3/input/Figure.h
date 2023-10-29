#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>
#include <algorithm>

class Figure{

    friend std::ostream& operator << (std::ostream& out, const Figure& fig);
    friend std::istream& operator >> (std::istream& in, Figure& fig);

public:

    Figure();

    Figure(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4);

    Figure(const Figure& other);

    ~Figure();

    virtual explicit operator double()const = 0;     // Подсчет площади через перегрузку (double)

    Figure& operator= (const Figure& other);        // Перегрузка операции копирования

    Figure& operator= (Figure&& other);             // Перегрузка операции перемещения

    bool operator == (Figure& other);                // Перегрузка операции сравнения

    virtual void print() const = 0;                  // Печать фигуры

    virtual double square() const = 0;               // Площадь фигуры

    virtual void get_center() const = 0;             // Геометрический центр фигуры

protected:

    // Нижняя левая вершина
    double _x1{0.0};
    double _y1{0.0};

    // Верхняя левая вершина
    double _x2{0.0};
    double _y2{0.0};  

    // Верхняя правая вершина
    double _x3{0.0};
    double _y3{0.0};  

    // Нижняя правая вершина
    double _x4{0.0};
    double _y4{0.0};    
     
};

#endif