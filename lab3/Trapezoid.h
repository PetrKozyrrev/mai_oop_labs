#ifndef TRAP_H
#define TRAP_H
#include "figure.h"

class Trapezoid: public Figure{

    friend std::ostream& operator<<(std::ostream& out, const Trapezoid& tr);
    friend std::istream& operator>>(std::istream& in, Trapezoid& tr);

public:
    Trapezoid() = default;
    Trapezoid(double x, double y, double h, double r, double up_r);
    Trapezoid(double h, double r, double up_r);
    Trapezoid(const Trapezoid& other);
    ~Trapezoid() = default;

    // площадь трапеции
    virtual explicit operator double()const{
        return 0.5 * (_r + _up_r) * _h;
    }

    Trapezoid& operator= (const Trapezoid& other){
        if(this != & other){
            _x = other._x;
            _y = other._y;
            _h = other._h;
            _r = other._r;
            _up_r = other._up_r;
        }
        return *this;
    }

    Trapezoid& operator= (Trapezoid&& other){
        if(this != & other){
            _x = other._x;
            _y = other._y;
            _h = other._h;
            _r = other._r;
            _up_r = other._up_r;
        }
        return *this;
    }

    bool operator== (Trapezoid& other){
        if(_x == other._x and _y == other._y and _h == other._h and _r == other._r and _up_r == other._up_r){
            return true;
        }
        return false;
    }

private:
    double _up_r{0.0};  // верхний радиус
};

inline std::ostream& operator<<(std::ostream& out, const Trapezoid& tr){
    out << "Trapezoid[ x: " << tr._x << ", y: " << tr._y << ", height: " << tr._h
    << ", base radius: " << tr._r << ", up radius: " << tr._up_r << " ];" << std::endl;

    return out;
}

inline std::istream& operator>>(std::istream& in, Trapezoid& tr){
    double x, y, h ,r, up_r;

    std::cout << "Enter x coord: ";
    in >> x;
    std::cout << std::endl;

    std::cout << "Enter y coord: ";
    in >> y;
    std::cout << std::endl;

    std::cout << "Enter height: ";
    in >> h;
    std::cout << std::endl;

    std::cout << "Enter base radius: ";
    in >> r;
    std::cout << std::endl;

    std::cout << "Enter up radius: ";
    in >> up_r;
    std::cout << std::endl;

    tr._x = x;
    tr._y = y;
    tr._h = h;
    tr._r = r;
    tr._up_r = up_r;

    return in;
}

#endif