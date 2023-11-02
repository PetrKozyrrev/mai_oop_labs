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
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    Pentagon<int> d(pii(0,0),pii(0,0),pii(0,0),pii(0,0),pii(0,0));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);
    std::shared_ptr<Pentagon<int>> d_ptr = std::make_shared<Pentagon<int>>(Pentagon<int>(pii(0,0),pii(0,0),pii(0,0),pii(0,0),pii(0,0)));

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};    

    arr.push_back(d_ptr);

    for(int i{0}; i < arr.size(); ++i){

        Figure* el = arr[i].get();

        if (el == nullptr) {
            std::cout << "The figure has been deleted" << std::endl;
        } 
        else if (typeid(Trapezoid<int>) == typeid(*el)) {
            get_center<Trapezoid<int>, int>(*(Trapezoid<int>*)el);

            print<Trapezoid<int>>(*(Trapezoid<int>*)el);

            std::cout << "Square Trapezoid = " << square<Trapezoid<int>, int>(*(Trapezoid<int>*)el) << std::endl;

        } 
        else if (typeid(Rhombus<int>) == typeid(*el)) {
            get_center<Rhombus<int>, int>(*(Rhombus<int>*)el);

            print<Rhombus<int>>(*(Rhombus<int>*)el);

            std::cout << "Square Rhombus = " << square<Rhombus<int>, int>(*(Rhombus<int>*)el) << std::endl;
        } 
        else if (typeid(Pentagon<int>) == typeid(*el)) {
            get_center<Pentagon<int>, int>(*(Pentagon<int>*)el);

            print<Pentagon<int>>(*(Pentagon<int>*)el);

            std::cout << "Square Pentagon = " << square<Pentagon<int>, int>(*(Pentagon<int>*)el) << std::endl;
        }
    }

    std::cout << "Common Square = " << arr.sum() << std::endl;
}