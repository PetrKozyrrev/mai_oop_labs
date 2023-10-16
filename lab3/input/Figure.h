#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure{

    friend std::ostream& operator<<(std::ostream& out, const Figure& fig);
    friend std::istream& operator>>(std::istream& in, Figure& fig);

public:
    Figure();
    Figure(double x, double y,double h,double r);
    Figure(double h,double r);
    Figure(const Figure& other);
    ~Figure();

    virtual explicit operator double()const{
        return (_h * _r);
    }

    Figure& operator= (const Figure& other);

    Figure& operator= (Figure&& other);

    bool operator== (Figure& other);

    virtual void print() const = 0;

    virtual double square() const = 0;

    // getters
    virtual double get_x() const;
    virtual double get_y() const;

protected:
    double _x{0.0};  // x coord;
    double _y{0.0};  // y coord;
    double _h{0.0};  // height;
    double _r{0.0};  // based radius;
};

inline std::ostream& operator<<(std::ostream& out,const Figure& fig){
    out << "FIGURE [ x: "<< fig._x << ", y: " << fig._y << " height: " << fig._h << " base radius: " << fig._r << " ];" << std::endl;
    return out;
}

inline std::istream& operator>>(std::istream& in, Figure& fig){
    double x, y, h ,r;

    std::cout << "FIGURE INPUT: " << std::endl;

    std::cout << "Enter x coord: ";
    in >> x;
    std::cout << std::endl;

    std::cout << "Enter y coord: ";
    in >> y;
    std::cout << std::endl;

    std::cout << "Enter height: ";
    in >> h;
    std::cout << std::endl;

    std::cout << "Enter radius: ";
    in >> r;
    std::cout << std::endl;

    fig._x = x;
    fig._y = y;
    fig._h = h;
    fig._r = r;

    return in;
}

#endif