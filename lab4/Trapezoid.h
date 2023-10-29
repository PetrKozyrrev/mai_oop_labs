#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

template <class T>
class Trapezoid : public Figure<T>{

    using ptt = std::pair<T,T>;

    friend std::ostream& operator<<(std::ostream &out, const Trapezoid<T> &tr){
        out << "TRAPEZOID:" << std::endl 
        << "1-я вершина: ( " << tr._c1.first << ", " << tr._c1.second << " )" << std::endl 
        << "2-я вершина: ( " << tr._c2.first << ", " << tr._c2.second << " )" << std::endl
        << "3-я вершина: ( " << tr._c3.first << ", " << tr._c3.second << " )" << std::endl
        << "4-я вершина: ( " << tr._c4.first << ", " << tr._c4.second << " )" << std::endl;

        return out;
    };

    friend std::istream& operator>>(std::istream &in, Trapezoid<T> &tr){
        std::cout << "Trapezoid INPUT: " <<std::endl; 
        ptt a,b,c,d;
        in >> a.first >> a.second;
        in >> b.first >> b.second;
        in >> c.first >> c.second;
        in >> d.first >> d.second;

        tr._c1 = a;
        tr._c2 = b;
        tr._c3 = c;
        tr._c4 = d;

        return in;

    }

public:
    Trapezoid() = default;
    Trapezoid(ptt a, ptt b, ptt c, ptt d) : Figure<T>(a,b,c,d){};
    Trapezoid(const Trapezoid<T> &other) : Figure<T>(other){};
    Trapezoid(const Trapezoid<T> &&other) : Figure<T>(other){};
    ~Trapezoid() = default;
};

#endif // TRAPEZOID_H