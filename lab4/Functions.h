#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <memory>
#include <utility>

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
    T _y1 = elem._c1.first, _y2 =elem._c2.first,_y3 = elem._c3.first, _y4 = elem._c4.first;
    double bottom_base { sqrt((_x4 - _x1) * (_x4 - _x1) + (_y4 - _y1) * (_y4 - _y1))};
    double top_base { sqrt((_x3 - _x2) * (_x3 - _x2) + (_y3 - _y2) * (_y3 - _y2))};

    T h {std::max(_y2 - _y1, _y3 - _y4)};

    return 0.5 * (bottom_base + top_base) * h;
}

#endif // FUNCTIONS_H