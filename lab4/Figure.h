#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure{
   public:
    Figure() = default;
    virtual ~Figure() = default;
};

std::ostream& operator<<(std::ostream &out, const Figure &fig){
    out << "FIGURE:" << std::endl;
    
    return out;
};

#endif // FIGURE_H