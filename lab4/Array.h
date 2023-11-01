#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>

template <class T>
class Array{
public:
    Array();

    Array(int size);

    Array(const Array &other);

    Array(Array &&other);

    ~Array();

    T* operator[](size_t index);

    size_t size() const;

    void delete_elem (int index);

    void push_back(T* elem);

private:
    size_t _size;
    size_t _capable;
    std::unique_ptr<T*> _array;
};

template <class T>
inline Array<T>::Array(){
    _capable = 10;
    _size = 0;
    _array.reset(new T*[_capable]);

    for (size_t i = 0; i < _capable; ++i)
        _array.get()[i] = nullptr;
}

template <class T>
inline Array<T>::Array(int size) {
    _capable = size * 2;
    _size = 0;
    _array.reset(new T*[_capable]);

    for (size_t i = 0; i != _capable; ++i)
        _array.get()[i] = nullptr;
}

template <class T>
inline Array<T>::Array(const Array &other){
    _capable = other._capable;
    _size = other._size;   
    _array.reset(new T*[_capable]);

    for (size_t i{0}; i < _size; ++i)
        _array.get()[i] = other._array.get()[i];
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
inline T* Array<T>::operator[](size_t index){
    return _array.get()[index];
}

template <class T>
inline size_t Array<T>::size() const{
    return _size;
}

template <class T>
inline void Array<T>::delete_elem(int index){
    for(int i{index}; i < _size - 1; ++i){
        _array.get()[i] = _array.get()[i + 1];
    }
    --_size;
}

template <class T>
inline void Array<T>::push_back(T* elem){
    _array.get()[_size++] = elem;
}

template <class T>
inline Array<T>::~Array(){
    //_array.release();
    _size = 0;
    _capable = 0;
}

#endif // ARRAY_H