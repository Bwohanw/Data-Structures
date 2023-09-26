#include <iostream>

template <typename T>
class Vector {
    public:
    Vector();


    Vector(const Vector<T>& other);

    Vector<T>& operator=(const Vector<T>& other);

    ~Vector();


    private:
    int length_;
    T* data_;

};

#include "vector.hpp"