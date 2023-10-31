#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

#include <iostream>
#include <cmath>
#include <memory>

template <class T>
void get_center(Trapezoid<T> elem){
    T x_center = (elem._c4.first - elem._c1.first) / 2;
    T y_center = (elem._c3.second - elem._c1.second) / 2;

    std::cout << "Center - (" << x_center << ", " << y_center << ")" << std::endl;
}

template <class T>
void get_center(Rhombus<T> elem){
    T x_center = (elem._c3.first - elem._c2.first) / 2;
    T y_center = (elem._c4.second - elem._c1.second) / 2;

    std::cout << "Center - (" << x_center << ", " << y_center << ")" << std::endl;
}

template <class T>
void get_center(Pentagon<T> elem){
    T x_center = (elem._c5.first - elem._c1.first) / 2;
    T y_center = (elem._c3.second - elem._c1.second) /2;

    std::cout << "Center - (" << x_center << ", " << y_center << ")" << std::endl;
}

void get_center(Figure elem){
    std::cout << elem<< std::endl;
}

#endif // FUNCTIONS_H