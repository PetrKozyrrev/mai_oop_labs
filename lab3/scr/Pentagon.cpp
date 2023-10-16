#include "Pentagon.h"

Pentagon::Pentagon(): Figure(){};

Pentagon::Pentagon(double x, double y, double h, double r): Figure(x,y,h,r){};

Pentagon::Pentagon(double h, double r): Figure(h,r){};

Pentagon::Pentagon(const Pentagon& other): Figure(other._x, other._y, other._h, other._r) {};

Pentagon& Pentagon::operator= (const Pentagon& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
    }
    return *this;
}

Pentagon& Pentagon::operator= (Pentagon&& other){
    if(this != & other){
        _x = other._x;
        _y = other._y;
        _h = other._h;
        _r = other._r;
    }
    return *this;
}

bool Pentagon::operator== (Pentagon& other){
    if(_x == other._x and _y == other._y and _h == other._h and _r == other._r){
        return true;
    }
    return false;
}

void Pentagon::print() const{
    std::cout << "PENTAGON [ x: "<< _x << ", y: " << _y << " height: " << _h << " base radius: " << _r << " ];" << std::endl;
}

double Pentagon::square() const{
    return 5 * (0.5 * (0.5 * _h) * (2 * _r));
}

Pentagon::~Pentagon(){};