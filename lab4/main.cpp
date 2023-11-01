#include <iostream>
#include <memory>

#include "Array.h"
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Functions.h"

#define pii std::pair<int,int>

int main(){
    Trapezoid<int> a(pii(1,1),pii(2,2),pii(3,3),pii(4,4));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    Array<Figure> arr;    
    arr.push_back(&a);
    arr.push_back(&b);
    arr.push_back(&c);

    for(int i{0}; i < arr.size(); ++i){
        Figure* f = arr[i];

        if (f == nullptr) {
            std::cout << "The figure has been deleted" << std::endl;
        } else if (typeid(Trapezoid<int>) == typeid(*f)) {
            get_center<Trapezoid<int>, int>(*(Trapezoid<int>*)f);
            print<Trapezoid<int>>(*(Trapezoid<int>*)f);
            std::cout << "Square Trapezoid = " << square<Trapezoid<int>, int>(*(Trapezoid<int>*)f) << std::endl;
        } else if (typeid(Rhombus<int>) == typeid(*f)) {
            get_center<Rhombus<int>, int>(*(Rhombus<int>*)f);
            print<Rhombus<int>>(*(Rhombus<int>*)f);
            std::cout << "Square Rhombus = " << square<Rhombus<int>, int>(*(Rhombus<int>*)f) << std::endl;
        } else if (typeid(Pentagon<int>) == typeid(*f)) {
            get_center<Pentagon<int>, int>(*(Pentagon<int>*)f);
            print<Pentagon<int>>(*(Pentagon<int>*)f);
            std::cout << "Square Pentagon = " << square<Pentagon<int>, int>(*(Pentagon<int>*)f) << std::endl;
        }
    }
}