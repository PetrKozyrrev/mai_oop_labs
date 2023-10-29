#ifndef PENTAGON_H
#define PENTAGON_H
#include "Figure.h"

class Pentagon : public Figure{
    
    friend std::ostream& operator << (std::ostream& out, const Pentagon& pnt);
    friend std::istream& operator >> (std::istream& in, Pentagon& pnt);

    using Figure::Figure;

public:

    Pentagon();

    Pentagon(double x1, double y1,double x2, double y2,double x3, double y3,double x4, double y4,double x5, double y5);

    Pentagon(const Pentagon& other);

    ~Pentagon();

    explicit operator double()const override{
        return this->square();
    }

    Pentagon& operator = (const Pentagon& other);

    Pentagon& operator = (Pentagon&& other);

    bool operator == (Pentagon& other);

    void print() const override;

    double square() const override;

    void get_center() const override;

private:

    // Пятая вершина
    double _x5{0.0};
    double _y5{0.0};
};

#endif