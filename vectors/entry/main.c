#include <iostream>
#include "../src/vector.h"


int main() {

    Vector<int> v;
    for (int i = 0; i < 20; i++) {
        v.insert(v.size(),i);
    }
    std::cout << v << std::endl;
    v.at(0) = 10;
    std::cout << v << std::endl;
    return 0;
}