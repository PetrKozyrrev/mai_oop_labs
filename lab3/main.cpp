#include<iostream>
#include "figure.h"

int main(){
    Figure a(1,1,5,5);
    std::cout << a << std::endl;

    double s = (double)a;
    std::cout << s << std::endl;

    Figure b;
    std::cin >> b;

    std::cout << b << std::endl;

    if(a==b){
        std::cout << "TRUE" << std::endl;
    }
    else{
        std::cout << "FALSE" << std::endl; 
    }
}