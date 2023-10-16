#ifndef TRAP_H
#define TRAP_H
#include "Figure.h"

class Trapezoid: public Figure{

    friend std::ostream& operator<<(std::ostream& out, const Trapezoid& tr);
    friend std::istream& operator>>(std::istream& in, Trapezoid& tr);

public:
    Trapezoid();
    Trapezoid(double x, double y, double h, double r, double up_r);
    Trapezoid(double h, double r, double up_r);
    Trapezoid(const Trapezoid& other);
    ~Trapezoid();

    // площадь трапеции
    explicit operator double()const  override{
        return 0.5 * (_r + _up_r) * _h;
    }

    Trapezoid& operator= (const Trapezoid& other);

    Trapezoid& operator= (Trapezoid&& other);

    bool operator== (Trapezoid& other);

    void print() const override;

    double square() const override;

private:
    double _up_r{0.0};  // верхний радиус
};

inline std::ostream& operator<<(std::ostream& out, const Trapezoid& tr){
    out << "TRAPEZOID [ x: " << tr._x << ", y: " << tr._y << ", height: " << tr._h
    << ", base radius: " << tr._r << ", up radius: " << tr._up_r << " ];" << std::endl;

    return out;
}

inline std::istream& operator>>(std::istream& in, Trapezoid& tr){
    double x, y, h ,r, up_r;

    std::cout << "TRAPEZOID INPUT: " << std::endl;

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