#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

template <class T>
class Rhombus : public Figure{
public:

    using ptt = std::pair<T,T>;

    ptt _c1, _c2, _c3, _c4;

    Rhombus() = default;
    Rhombus(ptt a, ptt b, ptt c, ptt d) : _c1(a), _c2(b), _c3(c), _c4(d){};
    Rhombus(const Rhombus<T> &other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    Rhombus(const Rhombus<T> &&other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    ~Rhombus() = default;

    Rhombus<T>& operator= (const Rhombus<T>& other);

    Rhombus<T>& operator= (Rhombus<T>&& other);

    bool operator== (Rhombus<T>& other);

};

template <class T>
std::ostream& operator<<(std::ostream &out, const Rhombus<T> &rmb){
    out << "RHOMBUS:" << std::endl 
    << "1-я вершина: ( " << rmb._c1.first << ", " << rmb._c1.second << " )" << std::endl 
    << "2-я вершина: ( " << rmb._c2.first << ", " << rmb._c2.second << " )" << std::endl
    << "3-я вершина: ( " << rmb._c3.first << ", " << rmb._c3.second << " )" << std::endl
    << "4-я вершина: ( " << rmb._c4.first << ", " << rmb._c4.second << " )" << std::endl;

    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, Rhombus<T> &rmb){
    using ptt = std::pair<T,T>;

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

template <class T>
inline Rhombus<T>& Rhombus<T>::operator= (const Rhombus<T>& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline Rhombus<T>& Rhombus<T>::operator= (Rhombus<T>&& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline bool Rhombus<T>::operator== (Rhombus<T>& other){
    if(_c1 == other._c1 and _c2 == other._c2 and _c3 == other._c3 and _c4 == other._c4){
        return true;
    }
    return false;
}

#endif // RHOMBUS_H