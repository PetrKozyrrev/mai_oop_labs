#ifndef RHOBMBUS_H
#define RHOBMBUS_H
#include "Figure.h"

class Rhombus : public Figure{

    friend std::ostream& operator << (std::ostream& out, const Rhombus& rmb);
    friend std::istream& operator >> (std::istream& in, Rhombus& rmb);

    using Figure::Figure;

public:

    Rhombus(const Rhombus& other);

    explicit operator double()const  override{
        return this->square();
    };

    Rhombus& operator = (const Rhombus& other);

    Rhombus& operator = (Rhombus&& other);

    bool operator == (Rhombus& other);

    void print() const override;

    double square() const override;

     void get_center() const ;
};

#endif