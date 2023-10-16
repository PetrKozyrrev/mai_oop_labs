#ifndef PENTG_H
#define PENTG_H
#include "Figure.h"

class Pentagon : public Figure{
    
    friend std::ostream& operator<< (std::ostream& out, const Pentagon& pnt);
    friend std::istream& operator>> (std::istream& in, Pentagon& pnt);

    using Figure::Figure;

public:

    Pentagon();
    Pentagon(double x, double y, double h, double r);
    Pentagon(double h, double r);
    Pentagon(const Pentagon& other);
    ~Pentagon();

    // площадь пятиугольника
    explicit operator double()const override{
        return 5 * (0.5 * (0.5 * _h) * (2 * _r));
    }

    Pentagon& operator= (const Pentagon& other);

    Pentagon& operator= (Pentagon&& other);

    bool operator== (Pentagon& other);

    void print() const override;

    double square() const override;
};

inline std::ostream& operator<<(std::ostream& out,const Pentagon& pnt){
    out << "PENTAGON [ x: " << pnt._x << ", y: " << pnt._y << " height: " << pnt._h << " base radius: " << pnt._r << " ];" << std::endl;
    return out;
}

inline std::istream& operator>>(std::istream& in, Pentagon& pnt){
    double x, y, h ,r;

    std::cout << "PENTAGON INPUT: " << std::endl;

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

    pnt._x = x;
    pnt._y = y;
    pnt._h = h;
    pnt._r = r;

    return in;
}

#endif