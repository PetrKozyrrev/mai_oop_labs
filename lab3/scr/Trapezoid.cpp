#include <algorithm>
#include "Trapezoid.h"

Trapezoid::Trapezoid(const Trapezoid& other): Figure(other._x1, other._y1, other._x2, other._y2, other._x3, other._y3, other._x4, other._y4){};

Trapezoid& Trapezoid::operator= (const Trapezoid& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

Trapezoid& Trapezoid::operator= (Trapezoid&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

bool Trapezoid::operator== (Trapezoid& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Trapezoid& tr){
    out << "TRAPEZOID:" << std::endl 
    << "1-я вершина: ( " << tr._x1 << ", " << tr._y1 << " )" << std::endl 
    << "2-я вершина: ( " << tr._x2 << ", " << tr._y2 << " )" << std::endl
    << "3-я вершина: ( " << tr._x3 << ", " << tr._y3 << " )" << std::endl
    << "4-я вершина: ( " << tr._x4 << ", " << tr._y4 << " )" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Trapezoid& tr){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "TRAPEZOID INPUT: " << std::endl;

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

    tr._x1 = x1;
    tr._x2 = x2;
    tr._x3 = x3;
    tr._x4 = x4;

    tr._y1 = y1;
    tr._y2 = y2;
    tr._y3 = y3;
    tr._y4 = y4;

    return in;
}

void Trapezoid::print() const{
    std::cout << "TRAPEZOID:" << std::endl 
    << "1-я вершина: ( " << _x1 << ", " << _y1 << " )" << std::endl 
    << "2-я вершина: ( " << _x2 << ", " << _y2 << " )" << std::endl
    << "3-я вершина: ( " << _x3 << ", " << _y3 << " )" << std::endl
    << "4-я вершина: ( " << _x4 << ", " << _y4 << " )" << std::endl;
}

double Trapezoid::square() const{
    double bottom_base = sqrt((_x4 - _x1) * (_x4 - _x1) + (_y4 - _y1) * (_y4 - _y1));
    double top_base = sqrt((_x3 - _x2) * (_x3 - _x2) + (_y3 - _y2) * (_y3 - _y2));
    double h = std::max(_y2 - _y1, _y3 - _y4);
    return 0.5 * (bottom_base + top_base) * h;
}

void Trapezoid::get_center() const{
    double bottom_center_x = 0.5 * (_x4 - _x1);
    double bottom_center_y = 0.5 * (_y4 - _y1);

    double top_center_x = 0.5 * (_x3 - _x2);
    double top_center_y = 0.5 * (_y3 - _y2);

    double len_bottom = sqrt(bottom_center_x * bottom_center_x + bottom_center_y * bottom_center_y);
    double len_top = sqrt(top_center_x * top_center_x + top_center_y * top_center_y);
    
    double k = len_bottom / len_top; // коэф подобия

    double res_x = 0.5 * abs(top_center_x - bottom_center_x);
    double res_y = bottom_center_y + (k * (top_center_y + top_center_y * k) / (k+1));

    std::cout << "Trapezoid center - ( " << res_x << ", " << res_y << " )" << std::endl;
}