#include "Figure.h"

Figure::Figure(): _x1(0.0),_y1(0.0),_x2(0.0),_y2(0.0),_x3(0.0),_y3(0.0),_x4(0.0),_y4(0.0){};

Figure::Figure(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4){
    _x1 = x1; _y1 = y1;
    _x2 = x2; _y2 = y2;
    _x3 = x3; _y3 = y3;
    _x4 = x4; _y4 = y4;
};

Figure::Figure(const Figure& other){
    _x1 = other._x1; _y1 = other._y1;
    _x2 = other._x2; _y2 = other._y2;
    _x3 = other._x3; _y3 = other._y3;
    _x4 = other._x4; _y4 = other._y4;
};

Figure& Figure::operator= (const Figure& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

Figure& Figure::operator= (Figure&& other){
    if(this != & other){
        _x1 = other._x1; _y1 = other._y1;
        _x2 = other._x2; _y2 = other._y2;
        _x3 = other._x3; _y3 = other._y3;
        _x4 = other._x4; _y4 = other._y4;
    }
    return *this;
}

bool Figure::operator== (Figure& other){
    if(_x1 == other._x1 and _y1 == other._y1 and 
       _x2 == other._x2 and _y2 == other._y2 and
       _x3 == other._x3 and _y3 == other._y3 and
       _x4 == other._x4 and _y4 == other._y4){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out,const Figure& fig){
    out << "FIGURE:" << std::endl 
    << "1-я вершина: ( " << fig._x1 << ", " << fig._y1 << " )" << std::endl 
    << "2-я вершина: ( " << fig._x2 << ", " << fig._y2 << " )" << std::endl
    << "3-я вершина: ( " << fig._x3 << ", " << fig._y3 << " )" << std::endl
    << "4-я вершина: ( " << fig._x4 << ", " << fig._y4 << " )" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Figure& fig){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    std::cout << "FIGURE INPUT: " << std::endl;

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

    fig._x1 = x1;
    fig._x2 = x2;
    fig._x3 = x3;
    fig._x4 = x4;

    fig._y1 = y1;
    fig._y2 = y2;
    fig._y3 = y3;
    fig._y4 = y4;

    return in;
}

Figure::~Figure(){};