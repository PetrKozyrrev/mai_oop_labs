#include <iostream>
#include <memory>
#include "Array.h"
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"


int main(){
    Trapezoid<int> a(std::pair(1,1),std::pair(2,2),std::pair(3,3),std::pair(4,4));
    Rhombus<int> b(std::pair(10,10),std::pair(20,20),std::pair(30,30),std::pair(40,40));
    Pentagon<int> c(std::pair(100,100),std::pair(200,200),std::pair(300,300),std::pair(400,400),std::pair(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(std::pair(1,1),std::pair(2,2),std::pair(3,3),std::pair(4,4));
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(std::pair(10,10),std::pair(20,20),std::pair(30,30),std::pair(40,40));
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(std::pair(100,100),std::pair(200,200),std::pair(300,300),std::pair(400,400),std::pair(500,500));

    Array<std::shared_ptr<Figure<int>>> arr{a_ptr,b_ptr,c_ptr};

    for(int i{0}; i< arr.size(); ++i){
        arr[i]->print();
        arr[i]->get_center();
        std::cout << arr[i]->square() << std::endl;
    }
}