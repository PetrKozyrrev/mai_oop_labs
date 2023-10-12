#include "figure.h"

Figure::Figure(double x, double y, double h,double r): _x(x), _y(y), _h(h), _r(r) {};

Figure::Figure(const Figure& other): _x(other._x),_y(other._y),_h(other._h), _r(other._r) {};

double Figure::get_x(){
    return _x;
}

double Figure::get_y(){
    return _y;
}


