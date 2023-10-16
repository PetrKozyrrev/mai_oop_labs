#ifndef RHOBM_H
#define RHOMB_H
#include "Figure.h"

class Rhombus : public Figure{

    friend std::ostream& operator<<(std::ostream& out, const Rhombus& rmb);
    friend std::istream& operator>>(std::istream& in, Rhombus& rmb);

    using Figure::Figure;

public:
    Rhombus();
    Rhombus(const Rhombus& other);
    ~Rhombus();

    Rhombus& operator= (const Rhombus& other);

    Rhombus& operator= (Rhombus&& other);

    bool operator== (Rhombus& other);

    void print() const override;

    double square() const override;
};

inline std::ostream& operator<<(std::ostream& out,const Rhombus& rmb){
    out << "RHOMBUS [ x: "<< rmb._x << ", y: " << rmb._y << " height: " << rmb._h << " base radius: " << rmb._r << " ];" << std::endl;
    return out;
}

inline std::istream& operator>>(std::istream& in, Rhombus& rmb){
    double x, y, h ,r;

    std::cout << "RHOMBUS INPUT: " << std::endl;

    std::cout << "Enter x coord: ";
    in >> x;
    std::cout << std::endl;

    std::cout << "Enter y coord: ";
    in >> y;
    std::cout << std::endl;

    std::cout << "Enter height: ";
    in >> h;
    std::cout << std::endl;

    std::cout << "Enter radius: ";
    in >> r;
    std::cout << std::endl;

    rmb._x = x;
    rmb._y = y;
    rmb._h = h;
    rmb._r = r;

    return in;
}

#endif