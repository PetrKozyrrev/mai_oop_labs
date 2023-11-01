#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

template <class T>
class Pentagon : public Figure{
public:

    using ptt = std::pair<T,T>;

    ptt _c1, _c2, _c3, _c4, _c5;

    Pentagon() = default;
    Pentagon(ptt a, ptt b, ptt c, ptt d,ptt e) : _c1(a), _c2(b), _c3(c), _c4(d), _c5(e){};
    Pentagon(const Pentagon<T> &other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4), _c5(other._c5){};
    Pentagon(const Pentagon<T> &&other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4), _c5(other._c5){};
    ~Pentagon() = default;

    Pentagon<T>& operator= (const Pentagon<T>& other);

    Pentagon<T>& operator= (Pentagon<T>&& other);

    bool operator== (Pentagon<T>& other);

};

template <class T>
std::ostream& operator<<(std::ostream &out, const Pentagon<T> &pnt){
    out << "PENTAGON:" << std::endl 
    << "1-я вершина: ( " << pnt._c1.first << ", " << pnt._c1.second << " )" << std::endl 
    << "2-я вершина: ( " << pnt._c2.first << ", " << pnt._c2.second << " )" << std::endl
    << "3-я вершина: ( " << pnt._c3.first << ", " << pnt._c3.second << " )" << std::endl
    << "4-я вершина: ( " << pnt._c4.first << ", " << pnt._c4.second << " )" << std::endl
    << "5-я вершина: ( " << pnt._c5.first << ", " << pnt._c5.second << " )" << std::endl;

    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, Pentagon<T> &pnt){
    using ptt = std::pair<T,T>;

    std::cout << "Pentagon INPUT: " <<std::endl; 
    ptt a, b, c, d, e;
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

template <class T>
inline Pentagon<T>& Pentagon<T>::operator= (const Pentagon<T>& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline Pentagon<T>& Pentagon<T>::operator= (Pentagon<T>&& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
inline bool Pentagon<T>::operator== (Pentagon<T>& other){
    if(_c1 == other._c1 and _c2 == other._c2 and _c3 == other._c3 and _c4 == other._c4){
        return true;
    }
    return false;
}

#endif // PENTAGON_H