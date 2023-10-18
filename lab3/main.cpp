#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

int n{0};   // Размер массива

// Удаление элемента из массва по индексу
void index_delete(Figure* arr[], int id){
    for(int i{id};i<n-1;++i){
        arr[i] = arr[i+1];
    }
    --n;
}

int main(){
    
    Trapezoid a(0,0,0,10,10,10,0,10);
    Trapezoid r(0,0,0,10,10,10,0,10);
    Rhombus b(0,0,0,10,10,10,10,0);
    Pentagon c(0,0,-3,10,5,20,8,5,0,10);

    Figure* array[] {&a,&b,&c};
    n += 3;

    double sm {0.0};

    for(int i{0}; i < n; ++i){
        array[i]->print();
        std::cout << array[i]->square() << std::endl;
        array[i]->get_center();
        std::cout << "-------------------------" << std::endl;

        sm += array[i]->square();
    }

    std::cout << "Общая площадь = " << sm << std::endl;

    index_delete(array, 1);

    std::cout << "DELETE RHOMBUS" << std::endl;

    sm = 0;

    for(int i{0}; i < n; ++i){
        array[i]->print();
        std::cout << array[i]->square() << std::endl;
        array[i]->get_center();
        std::cout << "-------------------------" << std::endl;

        sm += array[i]->square();
    }

    std::cout << "Общая площадь = " << sm << std::endl;

}