#include <iostream>
#include "../src/vector.h"


int main() {

    Vector<int> v;
    v.reverse();
    std::cout << v << std::endl;
    v.push_back(0);
    v.reverse();
    std::cout << v << std::endl;
    v.removeAt(0);
    for (int i = 20; i > 0; i--) {
        v.insert(0,i);
    }
    v[0] = 19;
    v.reverse();
    std::cout << v << " " << v.firstIndexOf(19) << std::endl;
    Vector<int> v2 = v;
    std::cout << v2 << std::endl;
    quicksort(v);
    std::cout << v << std::endl;

    Vector<int> arr;
    arr.push_back(10);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(5);
    quicksort(arr);
    std::cout << arr << std::endl;
    //std::cout << binarySearch(arr, 8) << " " << binarySearch(arr, 10) << " " << binarySearch(arr, 1) << " " << binarySearch(arr,0) << std::endl;
    // v.at(0) = 10;
    // std::cout << v << std::endl;
    arr.pop_back();
    return 0;
}