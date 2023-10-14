#ifndef RHOBM_H
#define RHOMB
#include "figure.h"

class Rhombus : public Figure{

    friend std::ostream& operator<<(std::ostream& out, const Rhombus& rmb);
    friend std::istream& operator>>(std::istream& in, Rhombus& rmb);

    using Figure::Figure;

public:

    Rhombus(const Rhombus& other);
    ~Rhombus() = default;

    Rhombus& operator= (const Rhombus& other){
        if(this != & other){
            _x = other._x;
            _y = other._y;
            _h = other._h;
            _r = other._r;
        }
        return *this;
    }

    Rhombus& operator= (Rhombus&& other){
        if(this != & other){
            _x = other._x;
            _y = other._y;
            _h = other._h;
            _r = other._r;
        }
        return *this;
    }

    bool operator== (Rhombus& other){
        if(_x == other._x and _y == other._y and _h == other._h and _r == other._r){
            return true;
        }
        return false;
    }
};


inline std::ostream& operator<<(std::ostream& out,const Rhombus& rmb){
    out << "Rhombus[ x:"<< rmb._x << ", y: " << rmb._y << " height: " << rmb._h << " base radius: " << rmb._r << " ];";
    return out;
}

inline std::istream& operator>>(std::istream& in, Rhombus& rmb){
    double x, y, h ,r;

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