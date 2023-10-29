#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>

template <class T>
class Array{
public:
    Array() : _size(0), _capable(10), _array{nullptr}{}

    Array(const std::initializer_list<T> &t){
        _capable = t.size() * 2;
        _array = std::shared_ptr<T[]>(new T[_capable]);
        _size = t.size();
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
    }

    Array(const Array &other){
        _capable = other._capable;
         _size = other._size;   
        _array = std::shared_ptr<T[]>(new T[_capable]);

        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array &&other){
        _capable = other._capable;
        _size = other._size;
        _array = other._array;

        other._capable = 0;
        other._size = 0;
        other._array = nullptr;
    }

    ~Array(){
        std::cout << "destructor:" << _array.use_count() << std::endl;
    }

    T& operator[](size_t index){
        return _array[index];
    }

    size_t size() const{
        return _size;
    }

    // void push_back(std::shared_ptr<T> elem){
    //     if(_size == _capable){
    //         _capable *= 2;
    //         std::shared_ptr<T[]> tmp = std::shared_ptr<T[]>(new T[_capable]);
    //         for(size_t i{0}; i < _size; ++i){
    //             tmp[i] = _array[i];
    //         }
    //         _array = std::shared_ptr<T[]>(new T[_capable]);
    //         _array = tmp;
    //     }
    //     _array[++_size] = elem;
    // }

    

private:
    size_t _size;
    size_t _capable;
    std::shared_ptr<T[]> _array;
};

#endif // ARRAY_H