#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

template <class T>
class Trapezoid : public Figure{
public:

    using ptt = std::pair<T,T>;

    ptt _c1, _c2, _c3, _c4;

    Trapezoid() = default;
    Trapezoid(ptt a, ptt b, ptt c, ptt d) : _c1(a), _c2(b), _c3(c), _c4(d){};
    Trapezoid(const Trapezoid<T> &other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    Trapezoid(const Trapezoid<T> &&other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    ~Trapezoid() = default;

    Trapezoid<T>& operator= (const Trapezoid<T>& other);

    Trapezoid<T>& operator= (Trapezoid<T>&& other);

    bool operator== (Trapezoid<T>& other);

};

template <class T>
std::ostream& operator<<(std::ostream &out, const Trapezoid<T> &tr){
    out << "TRAPEZOID:" << std::endl 
    << "1-я вершина: ( " << tr._c1.first << ", " << tr._c1.second << " )" << std::endl 
    << "2-я вершина: ( " << tr._c2.first << ", " << tr._c2.second << " )" << std::endl
    << "3-я вершина: ( " << tr._c3.first << ", " << tr._c3.second << " )" << std::endl
    << "4-я вершина: ( " << tr._c4.first << ", " << tr._c4.second << " )" << std::endl;

    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, Trapezoid<T> &tr){
    using ptt = std::pair<T,T>;
    
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

template <class T>
inline Trapezoid<T>& Trapezoid<T>::operator= (const Trapezoid<T>& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline Trapezoid<T>& Trapezoid<T>::operator= (Trapezoid<T>&& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline bool Trapezoid<T>::operator== (Trapezoid<T>& other){
    if(_c1 == other._c1 and _c2 == other._c2 and _c3 == other._c3 and _c4 == other._c4){
        return true;
    }
    return false;
}

#endif // TRAPEZOID_H