#include "Rhombus.h"

Rhombus::Rhombus(const Rhombus& other): Figure(other._x1, other._y1, other._x2, other._y2, other._x3, other._y3, other._x4, other._y4){};

Rhombus& Rhombus::operator= (const Rhombus& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

Rhombus& Rhombus::operator= (Rhombus&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

bool Rhombus::operator== (Rhombus& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Rhombus& rmb){
    out << "RHOMBUS:" << std::endl 
    << "1-я вершина: ( " << rmb._x1 << ", " << rmb._y1 << " )" << std::endl 
    << "2-я вершина: ( " << rmb._x2 << ", " << rmb._y2 << " )" << std::endl
    << "3-я вершина: ( " << rmb._x3 << ", " << rmb._y3 << " )" << std::endl
    << "4-я вершина: ( " << rmb._x4 << ", " << rmb._y4 << " )" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Rhombus& rmb){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "RHOMBUS INPUT: " << std::endl;

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

    rmb._x1 = x1;
    rmb._x2 = x2;
    rmb._x3 = x3;
    rmb._x4 = x4;

    rmb._y1 = y1;
    rmb._y2 = y2;
    rmb._y3 = y3;
    rmb._y4 = y4;

    return in;
}

void Rhombus::print() const{
    std::cout << "RHOMBUS:" << std::endl 
    << "1-я вершина: ( " << _x1 << ", " << _y1 << " )" << std::endl 
    << "2-я вершина: ( " << _x2 << ", " << _y2 << " )" << std::endl
    << "3-я вершина: ( " << _x3 << ", " << _y3 << " )" << std::endl
    << "4-я вершина: ( " << _x4 << ", " << _y4 << " )" << std::endl;
}

double Rhombus::square() const{
    double diag_1 = sqrt((_x3 - _x1) * (_x3 - _x1) + (_y3 - _y1) * (_y3 - _y1));
    double diag_2 = sqrt((_x4 - _x2) * (_x4 - _x2) + (_y4 - _y2) * (_y4 - _y2));
    
    return 0.5 * (diag_1 + diag_2);
}

void Rhombus::get_center() const{
    double center_x = 0.5 * (_x4 - _x1);
    double center_y = 0.5 * (_y2 - _y1);

    std::cout << "Rhombus center - ( " << center_x << ", " << center_y << " )" << std::endl;
}