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
    mergesort(v);
    std::cout << v << std::endl;
    // v.at(0) = 10;
    // std::cout << v << std::endl;
    return 0;
}