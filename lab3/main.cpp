#include <iostream>
#include "figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"

int main(){
    Trapezoid a(1,1,5,9,10);
    Rhombus b(6,6,10,4);
    
    Figure array[] {a,b};

    for(int i=0;i<2;++i){
        std::cout << (double)array[i] << std::endl;
    }
}