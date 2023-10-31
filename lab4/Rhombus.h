#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <cmath>

template <class T>
class Rhombus : public Figure<T>{
public:

    using ptt = std::pair<T,T>;

    Rhombus() = default;
    Rhombus(ptt a, ptt b, ptt c, ptt d) : _c1(a), _c2(b), _c3(c), _c4(d){};
    Rhombus(const Rhombus<T> &other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    Rhombus(const Rhombus<T> &&other) : _c1(other._c1), _c2(other._c2), _c3(other._c3), _c4(other._c4){};
    ~Rhombus() = default;

    Rhombus<T>& operator= (const Rhombus<T>& other);

    Rhombus<T>& operator= (Rhombus<T>&& other);

    bool operator== (Rhombus<T>& other);

    operator double(){
        return this->square();
    };

    void print();

    void get_center();

    double square();

    ptt _c1, _c2, _c3, _c4;

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
Rhombus<T>& Rhombus<T>::operator= (const Rhombus<T>& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
Rhombus<T>& Rhombus<T>::operator= (Rhombus<T>&& other){
    if(this != &other){
        _c1 = other._c1;
        _c2 = other._c2;
        _c3 = other._c3;
        _c4 = other._c4;
    }
    return *this;
}

template <class T>
bool Rhombus<T>::operator== (Rhombus<T>& other){
    if(_c1 == other._c1 and _c2 == other._c2 and _c3 == other._c3 and _c4 == other._c4){
        return true;
    }
    return false;
}

template <class T>
void Rhombus<T>::print(){
    std::cout << "RHOMBUS:" << std::endl 
    << "1-я вершина: ( " << _c1.first << ", " << _c1.second << " )" << std::endl 
    << "2-я вершина: ( " << _c2.first << ", " << _c2.second << " )" << std::endl
    << "3-я вершина: ( " << _c3.first << ", " << _c3.second << " )" << std::endl
    << "4-я вершина: ( " << _c4.first << ", " << _c4.second << " )" << std::endl;
}

template <class T>
void Rhombus<T>::get_center(){
    std::pair<T,T> res;
    res.first = (_c3.first - _c2.first) / 2;
    res.second = (_c4.second - _c1.second) / 2;

    std::cout << "Center - (" << res.first << ", " << res.second << ")" << std::endl;
}

template <class T>
double Rhombus<T>::square(){
    T _x1 = _c1.first, _x2 = _c2.first,_x3 = _c3.first, _x4 = _c4.first;
    T _y1 = _c1.first, _y2 = _c2.first,_y3 = _c3.first, _y4 = _c4.first;
    double diag_1 { sqrt((_x3 - _x1) * (_x3 - _x1) + (_y3 - _y1) * (_y3 - _y1))};
    double diag_2 { sqrt((_x4 - _x2) * (_x4 - _x2) + (_y4 - _y2) * (_y4 - _y2))};

    return 0.5 * diag_1 * diag_2;
}

#endif // RHOMBUS_H