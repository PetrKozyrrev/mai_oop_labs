#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

template <class T>
class Pentagon : public Figure<T>{

    using ptt = std::pair<T,T>;

    friend std::ostream& operator<<(std::ostream &out, const Pentagon<T> &pnt){
        out << "RHOMBUS:" << std::endl 
        << "1-я вершина: ( " << pnt._c1.first << ", " << pnt._c1.second << " )" << std::endl 
        << "2-я вершина: ( " << pnt._c2.first << ", " << pnt._c2.second << " )" << std::endl
        << "3-я вершина: ( " << pnt._c3.first << ", " << pnt._c3.second << " )" << std::endl
        << "4-я вершина: ( " << pnt._c4.first << ", " << pnt._c4.second << " )" << std::endl
        << "5-я вершина: ( " << pnt._c5.first << ", " << pnt._c5.second << " )" << std::endl;

        return out;
    };

    friend std::istream& operator>>(std::istream &in, Pentagon<T> &pnt){
        std::cout << "Pentagon INPUT: " <<std::endl; 
        ptt a,b,c,d,e;
        in >> a.first >> a.second;
        in >> b.first >> b.second;
        in >> c.first >> c.second;
        in >> d.first >> d.second;
        in >> e.first >> e.second;

        pnt._c1 = a;
        pnt._c2 = b;
        pnt._c3 = c;
        pnt._c4 = d;
        pnt._c5 = e;

        return in;

    }

public:

    Pentagon() = default;
    Pentagon(ptt a, ptt b, ptt c, ptt d,ptt e) : Figure<T>(a,b,c,d), _c5(e){};
    Pentagon(const Pentagon<T> &other) : Figure<T>(other), _c5(other._c5){};
    Pentagon(const Pentagon<T> &&other) : Figure<T>(other), _c5(other._c5){};
    ~Pentagon() = default;

    ptt _c5;
};

#endif // PENTAGON_H