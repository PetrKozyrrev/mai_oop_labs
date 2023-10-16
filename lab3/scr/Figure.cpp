#include "Figure.h"

Figure::Figure(): _x(0.0), _y(0.0), _h(0.0), _r(0.0) {};

Figure::Figure(double x, double y, double h,double r): _x(x), _y(y), _h(h), _r(r) {};

Figure::Figure(double h,double r): _x(0.0), _y(0.0), _h(h), _r(r) {};

Figure::Figure(const Figure& other): _x(other._x),_y(other._y),_h(other._h), _r(other._r) {};

double Figure::get_x() const{
    return _x;
}

double Figure::get_y() const{
    return _y;
}

Figure& Figure::operator= (const Figure& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
    }
    return *this;
}

Figure& Figure::operator= (Figure&& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
    }
    return *this;
}

bool Figure::operator== (Figure& other){
    if(_x == other._x and _y == other._y and _h == other._h and _r == other._r){
        return true;
    }
    return false;
}

Figure::~Figure(){};