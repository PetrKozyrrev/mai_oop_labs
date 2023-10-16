#include "Rhombus.h"

Rhombus::Rhombus(): Figure(){};

Rhombus::Rhombus(const Rhombus& other): Figure(other._x, other._y, other._h, other._r){};

Rhombus& Rhombus::operator= (const Rhombus& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
    }
    return *this;
}

Rhombus& Rhombus::operator= (Rhombus&& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
    }
    return *this;
}

void Rhombus::print() const{
    std::cout << "rhombus [ x: "<< _x << ", y: " << _y << " height: " << _h << " base radius: " << _r << " ];" << std::endl;
}

double Rhombus::square() const{
    return _h * _r;
}

Rhombus::~Rhombus(){};