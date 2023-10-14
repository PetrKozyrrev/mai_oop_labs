#include "Trapezoid.h"

Trapezoid::Trapezoid(double x, double y, double h, double r, double up_r): Figure(x,y,h,r), _up_r(up_r){};

Trapezoid::Trapezoid(double h, double r, double up_r): Figure(h,r), _up_r(up_r){};

Trapezoid::Trapezoid(const Trapezoid& other): Figure(other._x, other._y, other._h, other._r), _up_r(other._up_r) {};