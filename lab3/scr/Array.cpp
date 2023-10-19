#include <cstring>
#include <memory>
#include <algorithm>
#include "Array.h"

Array::Array(): size(0), arr(nullptr){};

void Array::push_back(Figure* figure) {
    Figure** temp = new Figure*[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    temp[size] = figure;
    
    delete[] arr;
    arr = temp;
    ++size;
}

Figure* Array::operator [] (const int index) const{
    return arr[index];
}

// Figure** Array::operator = (Figure** other){
//     Figure** temp = new Figure*[other.size()];

//     for(int i{0};i<other.size();++i){
//         temp[i] = other[i];
//     }

//     return temp;
// }

void Array::delete_elem (const int index){
    for (int i{index}; i<size-1; ++i){
        arr[i] = arr[i + 1];
    }
    --size;
}

double Array::sum_square () const{
    double sm{0.0};

    for(int i{0}; i < size; ++i){
        sm += arr[i]->square();
    }

    return sm;
}

int Array::len () const{
    return size;
}

Array::~Array(){
    if(size>0){
        size = 0;
        delete[] arr;
        arr = nullptr;
    }
}