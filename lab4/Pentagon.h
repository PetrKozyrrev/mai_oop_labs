#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <cmath>

template <class T>
class Pentagon : public Figure<T>{
public:

    using ptt = std::pair<T,T>;

    Pentagon() = default;
    Pentagon(ptt a, ptt b, ptt c, ptt d,ptt e) : _c1(a), _c2(b), _c3(c), _c4(d), _c5(e){};
    Pentagon(const Pentagon<T> &other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4), _c5(other._c5){};
    Pentagon(const Pentagon<T> &&other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4), _c5(other._c5){};
    ~Pentagon() = default;

    Pentagon<T>& operator= (const Pentagon<T>& other);

    Pentagon<T>& operator= (Pentagon<T>&& other);

    bool operator== (Pentagon<T>& other);

    operator double(){
        return this->square();
    };

    void print();

    void get_center();

    double square();

    ptt _c1, _c2, _c3, _c4, _c5;
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
Pentagon<T>& Pentagon<T>::operator= (const Pentagon<T>& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
Pentagon<T>& Pentagon<T>::operator= (Pentagon<T>&& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
bool Pentagon<T>::operator== (Pentagon<T>& other){
    if(_c1 == other._c1 and _c2 == other._c2 and _c3 == other._c3 and _c4 == other._c4){
        return true;
    }
    return false;
}

template <class T>
void Pentagon<T>::print(){
    std::cout << "PENTAGON:" << std::endl 
    << "1-я вершина: ( " << _c1.first << ", " << _c1.second << " )" << std::endl 
    << "2-я вершина: ( " << _c2.first << ", " << _c2.second << " )" << std::endl
    << "3-я вершина: ( " << _c3.first << ", " << _c3.second << " )" << std::endl
    << "4-я вершина: ( " << _c4.first << ", " << _c4.second << " )" << std::endl
    << "5-я вершина: ( " << _c5.first << ", " << _c5.second << " )" << std::endl;
}

template <class T>
void Pentagon<T>::get_center(){
    std::pair<T,T> res;
    res.first = (_c5.first - _c1.first) / 2;
    res.second = (_c3.second - _c1.second) / 2;

    std::cout << "Center - (" << res.first << ", " << res.second << ")" << std::endl;
}

template <class T>
double Pentagon<T>::square(){
    double PI = acos(-1);
    T _x1 = _c1.first, _x5 = _c5.first;
    T _y1 = _c1.first, _y5 = _c5.first;
    double size { sqrt((_x5 - _x1) * (_x5 - _x1) + (_y5 - _y1) * (_y5 - _y1))};
    double h { (size * 0.5) / (tan(PI/5))};

    return 5 * (0.5 * h * size);
}

#endif // PENTAGON_H