#include <catch2/catch_test_macros.hpp>
#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "List.h"

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

int main() {
    test_insert();

    
    return 0;
}

void test_insert() {
    List<int> l1;
    for (int i = 0; i < 10; i++) {
        l1.insertFront(i);
    }
    IS_TRUE(l1.size() == 10);
}