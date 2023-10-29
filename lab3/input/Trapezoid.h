#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "Figure.h"

class Trapezoid: public Figure{

    friend std::ostream& operator << (std::ostream& out, const Trapezoid& tr);
    friend std::istream& operator >> (std::istream& in, Trapezoid& tr);

    using Figure::Figure;

public:

    Trapezoid(const Trapezoid& other);

    explicit operator double()const  override{
        return this->square();
    };

    Trapezoid& operator = (const Trapezoid& other);

    Trapezoid& operator = (Trapezoid&& other);

    bool operator == (Trapezoid& other);

    void print() const override;

    double square() const override;

     void get_center() const ;

};

#endif