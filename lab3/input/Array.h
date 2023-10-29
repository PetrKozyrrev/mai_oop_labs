#ifndef ARRAY_H
#define ARRAY_H
#include "Figure.h"

class Array{
public:

    Array();
    Array(const std::initializer_list<Figure*> &t);
    Array(const Array& other);
    ~Array();

    Figure* operator [] (const int index) const;    // Обращение к элементу по индексу

    void push_back(Figure* figure);                 // Добавить элемент в конец списка

    void delete_elem (const int index);             // Удалить элемент по индексу

    double sum_square () const;                     // Сумма всех площадей

    int len() const;                                // Длина массива

private:
    Figure** arr;
    int size;
};

#endif