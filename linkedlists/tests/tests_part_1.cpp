#include <catch2/catch_test_macros.hpp>
#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "List.h"

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

int main() {
    test_insert_front();
    test_insert_back();
    test_insert();


    test_reverse_whole();
    test_reverse_partial();

    test_sort();
    
    return 0;
}

void test_insert_front() {
    List<int> l1;
    for (int i = 0; i < 10; i++) {
        l1.insertFront(i);
    }
    IS_TRUE(l1.size() == 10);
    std::stringstream s;
    l1.print(s);
    IS_TRUE(s.str() == "< 9 8 7 6 5 4 3 2 1 0 >");
}

void test_insert_back() {
    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.insertBack(i);
    }
    IS_TRUE(list.size() == 10);
    std::stringstream s;
    list.print(s);
    IS_TRUE(s.str() == "< 0 1 2 3 4 5 6 7 8 9 >");
}

void test_insert() {
    List<int> list;
    list.insertBack(3);
    list.insertBack(2);
    list.insertBack(1);
    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);

    std::stringstream s;
    list.print(s);

    IS_TRUE( s.str() == "< 1 2 3 3 2 1 >");
}

void test_reverse_whole() {

    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.insertBack(i);
    }

    list.reverse(0, list.size() - 1);
    std::stringstream s;
    list.print(s);
    IS_TRUE(s.str() == "< 9 8 7 6 5 4 3 2 1 0 >");

}

void test_reverse_partial() {
    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.insertBack(i);
    }

    list.reverse(2, 8);
    std::stringstream s;
    list.print(s);
    IS_TRUE(s.str() == "< 0 1 8 7 6 5 4 3 2 9 >");
}

void test_sort() {
    List<int> list;
    list.insertBack(5);
    list.insertBack(2);
    list.insertBack(4);
    list.insertBack(1);
    list.insertBack(8);
    list.insertBack(7);
    list.insertBack(6);

    list.sort();

    std::stringstream s;
    list.print(s);

    IS_TRUE(s.str() == "< 1 2 4 5 6 7 8 >");
}