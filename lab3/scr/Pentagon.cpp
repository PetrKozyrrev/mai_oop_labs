#include <cmath>
#include "Pentagon.h"

const double PI = acos(-1);

Pentagon::Pentagon(): Figure(), _x5(0.0), _y5(0.0){};

Pentagon::Pentagon(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4,double x5, double y5)
    :Figure(x1,y1,x2,y2,x3,y3,x4,y4), _x5(x5), _y5(y5){};

Pentagon::Pentagon(const Pentagon& other)
    :Figure(other._x1, other._y1, other._x2, other._y2, other._x3, other._y3, other._x4, other._y4), _x5(other._x5), _y5(other._y5){};

Pentagon& Pentagon::operator= (const Pentagon& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
        _x5 = other._x5; _y5 = other._y5;
    }
    return *this;
}

Pentagon& Pentagon::operator= (Pentagon&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
        _x5 = other._x5; _y5 = other._y5;
    }
    return *this;
}

bool Pentagon::operator== (Pentagon& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4 and
       _x5 == other._x5 and _y5 == other._y5){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Pentagon& pnt){
    out << "PENTAGON:" << std::endl 
    << "1-я вершина: ( " << pnt._x1 << ", " << pnt._y1 << " )" << std::endl 
    << "2-я вершина: ( " << pnt._x2 << ", " << pnt._y2 << " )" << std::endl
    << "3-я вершина: ( " << pnt._x3 << ", " << pnt._y3 << " )" << std::endl
    << "4-я вершина: ( " << pnt._x4 << ", " << pnt._y4 << " )" << std::endl
    << "5-я вершина: ( " << pnt._x5 << ", " << pnt._y5 << " )" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Pentagon& pnt){
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

    std::cout << "PENTAGON INPUT: " << std::endl;

    std::cout << "Введите 1-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x1;
    std::cout << " y: ";
    in >> y1;
    std::cout << std::endl;

    std::cout << "Введите 2-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x2;
    std::cout << " y: ";
    in >> y2;
    std::cout << std::endl;
    
    std::cout << "Введите 3-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x3;
    std::cout << " y: ";
    in >> y3;
    std::cout << std::endl;

    std::cout << "Введите 4-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x4;
    std::cout << " y: ";
    in >> y4;
    std::cout << std::endl;

    std::cout << "Введите 5-ю вершину: " << std::endl;
    std::cout << " x: ";
    in >> x5;
    std::cout << " y: ";
    in >> y5;
    std::cout << std::endl;

    pnt._x1 = x1;
    pnt._x2 = x2;
    pnt._x3 = x3;
    pnt._x4 = x4;
    pnt._x5 = x5;

    pnt._y1 = y1;
    pnt._y2 = y2;
    pnt._y3 = y3;
    pnt._y4 = y4;
    pnt._y5 = y5;

    return in;
}

void Pentagon::print() const{
    std::cout << "PENTAGON:" << std::endl 
    << "1-я вершина: ( " << _x1 << ", " << _y1 << " )" << std::endl 
    << "2-я вершина: ( " << _x2 << ", " << _y2 << " )" << std::endl
    << "3-я вершина: ( " << _x3 << ", " << _y3 << " )" << std::endl
    << "4-я вершина: ( " << _x4 << ", " << _y4 << " )" << std::endl
    << "5-я вершина: ( " << _x5 << ", " << _y5 << " )" << std::endl;
}

double Pentagon::square() const{
    double size = sqrt((_x5 - _x1) * (_x5 - _x1) + (_y5 - _y1) * (_y5 - _y1));
    double h = (size * 0.5) / (tan(PI/5));
    return 5 * (0.5 * h * size);
}

void Pentagon::get_center() const{
    double center_x = (_x5 - _x1) * 0.5;
    double center_y = (_y3 - _y1) * 0.5;

    std::cout << "Pentagon center - ( " << center_x << ", " << center_y << " )" << std::endl;
}

Pentagon::~Pentagon(){};