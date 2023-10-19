#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

int main(){
    
    Trapezoid a(0,0,0,10,10,10,0,10);
    Trapezoid r(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Array arr;
    arr.push_back(new Trapezoid(0,0,0,10,10,10,0,10));
    arr.push_back(new Rhombus (0,0,0,10,10,10,10,0));
    arr.push_back(new Pentagon (0,0,-3,10,5,20,8,5,0,10));
    arr.push_back(&a);
    
    for(int i{0}; i < arr.len(); ++i){
        arr[i]->print();
        std::cout << arr[i]->square() << std::endl;
        arr[i]->get_center();
        std::cout << "-------------------------" << std::endl;
    }

     std::cout << "Общая площадь = " << arr.sum_square() << std::endl;

    arr.delete_elem(1);

    std::cout << "DELETE RHOMBUS" << std::endl;

    for(int i{0}; i < arr.len(); ++i){
        arr[i]->print();
        std::cout << arr[i]->square() << std::endl;
        arr[i]->get_center();
        std::cout << "-------------------------" << std::endl;
    }

    std::cout << "Общая площадь = " << arr.sum_square() << std::endl;

}