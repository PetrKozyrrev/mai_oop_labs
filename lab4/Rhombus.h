#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

template <class T>
class Rhombus : public Figure<T>{

    using ptt = std::pair<T,T>;

    friend std::ostream& operator<<(std::ostream &out, const Rhombus<T> &rmb){
        out << "RHOMBUS:" << std::endl 
        << "1-я вершина: ( " << rmb._c1.first << ", " << rmb._c1.second << " )" << std::endl 
        << "2-я вершина: ( " << rmb._c2.first << ", " << rmb._c2.second << " )" << std::endl
        << "3-я вершина: ( " << rmb._c3.first << ", " << rmb._c3.second << " )" << std::endl
        << "4-я вершина: ( " << rmb._c4.first << ", " << rmb._c4.second << " )" << std::endl;

        return out;
    };

    friend std::istream& operator>>(std::istream &in, Rhombus<T> &rmb){
        std::cout << "Rhombus INPUT: " <<std::endl; 
        ptt a,b,c,d;
        in >> a.first >> a.second;
        in >> b.first >> b.second;
        in >> c.first >> c.second;
        in >> d.first >> d.second;

        rmb._c1 = a;
        rmb._c2 = b;
        rmb._c3 = c;
        rmb._c4 = d;

        return in;

    }

public:

    Rhombus() = default;
    Rhombus(ptt a, ptt b, ptt c, ptt d) : Figure<T>(a,b,c,d){};
    Rhombus(const Trapezoid<T> &other) : Figure<T>(other){};
    Rhombus(const Trapezoid<T> &&other) : Figure<T>(other){};
    ~Rhombus() = default;
};

#endif // RHOMBUS_H