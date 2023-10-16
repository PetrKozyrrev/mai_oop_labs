#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main(){
    Trapezoid a(1,1,5,9,10);
    Rhombus b(6,6,10,4);
    Pentagon c(10,10,100,100);
    
    Figure* array[] {&a,&b,&c};

    for(int i=0;i<3;++i){
        array[i]->print();
        std::cout << "Square = " << array[i]->square() <<std::endl;
    }

}