//#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include "../src/vector.h"


int main() {
    Vector<int> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(25);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(-2);
    vec.push_back(15);

    Vector<int> cpy(vec);

    std::string sorted = "< -2 3 4 5 6 7 8 9 10 15 25 >";

    mergesort(vec);
    quicksort(cpy);

    std::stringstream s;
    vec.print(s);
    assert(s.str() == sorted);

    s.str("");
    cpy.print(s);
    assert(s.str() == sorted);

    assert(binarySearch(vec, -2) == 0);
    assert(binarySearch(vec, 9) == 7);
    assert(binarySearch(vec, -1) == -1);
    assert(binarySearch(vec, 100) == -1);
    assert(binarySearch(vec, 15) == vec.size() - 2);

    return 0;
}