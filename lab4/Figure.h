#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

template <class T>
class Figure {

    using ptt = std::pair<T,T>;

    friend std::ostream& operator<<(std::ostream &out, const Figure<T> &fig){
        out << "FIGURE:" << std::endl 
        << "1-я вершина: ( " << fig._c1.first << ", " << fig._c1.second << " )" << std::endl 
        << "2-я вершина: ( " << fig._c2.first << ", " << fig._c2.second << " )" << std::endl
        << "3-я вершина: ( " << fig._c3.first << ", " << fig._c3.second << " )" << std::endl
        << "4-я вершина: ( " << fig._c4.first << ", " << fig._c4.second << " )" << std::endl;

        return out;
    };

    friend std::istream& operator>>(std::istream &in, Figure<T> &fig){
        std::cout << "Figure INPUT: " <<std::endl; 
        ptt a,b,c,d;
        in >> a.first >> a.second;
        in >> b.first >> b.second;
        in >> c.first >> c.second;
        in >> d.first >> d.second;

        fig._c1 = a;
        fig._c2 = b;
        fig._c3 = c;
        fig._c4 = d;

        return in;

    };

public:

    Figure() = default;
    Figure(ptt a,ptt b,ptt c,ptt d): _c1(a), _c2(b), _c3(c), _c4(d){};
    Figure(const Figure<T> &other): _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    Figure(const Figure<T> &&other): _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    ~Figure() = default;

    ptt _c1, _c2, _c3, _c4;
};

#endif // FIGURE_H