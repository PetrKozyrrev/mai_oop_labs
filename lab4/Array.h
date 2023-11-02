#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>

#include "Functions.h"

template <class T>
class Array{
public:
    Array();

    Array(int size);

    Array(const std::initializer_list<T> &t);

    Array(const Array &other);

    Array(Array &&other);

    ~Array();

    T& operator[](size_t index);

    Array<T>& operator=(Array<T>& other);

    Array<T>& operator=(Array<T>&& other);

    bool operator==(Array<T>&other);

    size_t size() const;

    void delete_elem(int index);

    void push_back(const T& elem);

    double sum() const;

private:
    size_t _size;
    size_t _capable;
    std::shared_ptr<T[]> _array;
};

template <class T>
inline Array<T>::Array(){
    _capable = 10;
    _size = 0;
    _array = std::shared_ptr<T[]>(new T[_capable]);

    for (size_t i{0}; i < _capable; ++i)
        _array[i] = nullptr;
}

template <class T>
inline Array<T>::Array(int size) {
    _capable = size * 2;
    _size = 0;
    _array = std::shared_ptr<T[]>(new T[_capable]);

    for (size_t i = 0; i != _capable; ++i)
        _array[i] = nullptr;
}

template <class T>
inline Array<T>::Array(const std::initializer_list<T> &t){
    _size = t.size();
    _capable = _size * 2;
    _array = std::shared_ptr<T[]>(new T[_capable]);
    size_t i{0};
    for (auto &c : t)
        _array[i++] = c;
    
    for (size_t i{_size}; i < _capable; ++i){
        _array[i++] = nullptr;
    }
}

template <class T>
inline Array<T>::Array(const Array &other){
    _capable = other._capable;
    _size = other._size;   
    _array = std::shared_ptr<T[]>(new T[_capable]);

    for (size_t i{0}; i < _size; ++i)
        _array[i] = other._array[i];
}

template <class T>
inline Array<T>::Array(Array &&other){
    _capable = other._capable;
    _size = other._size;
    _array = other._array;

    other._capable = 0;
    other._size = 0;
    other._array = nullptr;
}

template <class T>
inline T& Array<T>::operator[](size_t index){
    if (index >= _size)
        throw std::invalid_argument("The array index is out of range");
    return _array[index];
}

template <class T>
inline Array<T>& Array<T>::operator=(Array<T>& other){
    _capable = other._capable;
    _size = other._size;
    for(size_t i{0}; i < _size; ++i){
        _array[i] = other._array[i];
    }
    for(size_t i{_size}; i < _capable; ++i){
        _array[i] = nullptr;
    }

    return *this;
}

template <class T>
inline Array<T>& Array<T>::operator=(Array<T>&& other){
    _capable = other._capable;
    _size = other._size;
    for(size_t i{0}; i < _size; ++i){
        _array[i] = other._array[i];
    }
    for(size_t i{_size}; i < _capable; ++i){
        _array[i] = nullptr;
    }

    other.~Array();

    return *this;
}

template <class T>
inline bool Array<T>::operator==(Array<T>& other){
    if(_size == other._size){
        for(size_t i{0}; i < _size; ++i){
            if(_array[i] != other._array[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class T>
inline size_t Array<T>::size() const{
    return _size;
}

template <class T>
inline void Array<T>::delete_elem(int index){
    for(int i{index}; i < _size - 1; ++i){
        _array[i] = _array[i + 1];
    }
    _array[_size - 1] = nullptr;
    --_size;
}

template <class T>
inline void Array<T>::push_back(const T& elem){
    if(_size == _capable){
        _capable *= 2;
        std::shared_ptr<T[]> tmp = std::shared_ptr<T[]>(new T[_capable]);
        for(size_t i{0}; i < _size; ++i){
            tmp[i] = _array[i];
        }
        for(size_t i{_size}; i < _capable; ++i){
            tmp[i] = nullptr;
        }
        _array = tmp;
        _array[_size++] = elem;
    }
    else{
        _array[_size++] = elem;
    }
}

template <class T>
inline double Array<T>::sum() const{
    double sm{0.0};

    for(size_t i{0}; i < _size; ++i){
        sm += (double)(*_array[i]);
    }

    return sm;
}

template <class T>
inline Array<T>::~Array(){
    _size = 0;
    _capable = 0;
}

#endif // ARRAY_H