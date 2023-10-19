#ifndef ARR_H
#define ARR_H
#include <memory>
#include "Figure.h"

class Array{
public:
    Array();
    ~Array();

    Figure* operator [] (const int index) const;

    void push_back(Figure* figure);

    void delete_elem (const int index);

    double sum_square () const;

    int len() const;

private:
    Figure** arr;
    int size;
};

#endif