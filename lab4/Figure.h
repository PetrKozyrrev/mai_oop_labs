#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure{
   public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual explicit operator double() const = 0;
};

#endif // FIGURE_H