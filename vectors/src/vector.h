#pragma once

#include <iostream>

template <typename T>
class Vector {
    public:
    Vector();

    Vector(const Vector<T>& other);

    Vector<T>& operator=(const Vector<T>& other);

    Vector(int numElements, T data);

    ~Vector();

    void print(std::ostream& os=std::cout) const;

    int size() const;

    void push_back(const T& data);

    T& operator[](int index);

    T& at(int index);

    void insert(int index, const T& elem);

    void removeAt(int index);

    int firstIndexOf(const T& data);

    int lastIndexOf(const T& data);

    void reverse();


    private:
    int capacity_;
    int size_;
    T* data_ = NULL;

    void checksize();
    void _copy(const Vector<T>& other);
    void _destroy();
    void _resize();

};

template <typename T>
void mergesort(Vector<T>& vect);

template <typename T>
void quicksort(Vector<T>& vect);

template <typename T>
int binarySearch(Vector<T>& vect, const T& target);

#include "vector.hpp"
#include "vector-utils.hpp"