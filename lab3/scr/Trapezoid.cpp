#include "Trapezoid.h"

Trapezoid::Trapezoid(): Figure(), _up_r(0.0){};

Trapezoid::Trapezoid(double x, double y, double h, double r, double up_r): Figure(x,y,h,r), _up_r(up_r){};

Trapezoid::Trapezoid(double h, double r, double up_r): Figure(h,r), _up_r(up_r){};

Trapezoid::Trapezoid(const Trapezoid& other): Figure(other._x, other._y, other._h, other._r), _up_r(other._up_r) {};

Trapezoid& Trapezoid::operator= (const Trapezoid& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
        _up_r = other._up_r;
    }
    return *this;
}

Trapezoid& Trapezoid::operator= (Trapezoid&& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
        _up_r = other._up_r;
    }
    return *this;
}

bool Trapezoid::operator== (Trapezoid& other){
    if(_x == other._x and _y == other._y and _h == other._h and _r == other._r and _up_r == other._up_r){
        return true;
    }
    return false;
}

void Trapezoid::print() const{
    std::cout << "TRAPEZOID [ x: " << _x << ", y: " << _y << ", height: " << _h
    << ", base radius: " << _r << ", up radius: " << _up_r << " ];" << std::endl;
}

double Trapezoid::square() const{
    return 0.5 * (_r + _up_r) * _h;
}

Trapezoid::~Trapezoid(){};