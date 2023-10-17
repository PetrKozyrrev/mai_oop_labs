#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main(){
    Trapezoid a(0,0,0,10,10,10,0,10);
    Trapezoid r(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,0,10);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    if(a==r){
        std::cout << "TRUE\n";
    }
    else{
        std::cout << "False\n";
    }
    Figure* array[] {&a,&b,&c};

    double sm {0.0};

    for(int i=0;i<3;++i){
        array[i]->print();
        std::cout << array[i]->square() << std::endl;
        array[i]->get_center();
        std::cout << "-------------------------" << std::endl;

        sm += array[i]->square();
    }

    std::cout << "Общая площадь = " << sm << std::endl;

}