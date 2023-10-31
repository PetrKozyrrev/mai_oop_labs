#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

template <class T>
class Figure {
public:
    
    Figure() = default;
    ~Figure() = default;

    virtual operator double() = 0;

    virtual void print() = 0;

    virtual void get_center() = 0;

    virtual double square() = 0;
};

template <class T>
std::ostream& operator<<(std::ostream &out, const Figure<T> &fig){
    out << "FIGURE:" << std::endl;
    
    return out;
};

#endif // FIGURE_H