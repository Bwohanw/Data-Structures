//#include <catch2/catch_test_macros.hpp>
#include "tests_part_1.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../src/List.h"

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

int main() {
    test_insert_front();
    test_insert_back();
    test_insert();


    test_reverse_whole();
    test_reverse_partial();

    test_sort();
    sort_empty();
    sort_one();


    test_insert_at();


    test_failures();

    
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

    list.reverse();
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

    std::cout << s.str() << std::endl;

    IS_TRUE(s.str() == "< 1 2 4 5 6 7 8 >");
}

void sort_empty() {
    List<int> list;
    list.sort();
    std::stringstream s;
    list.print(s);
    IS_TRUE(s.str() == "< >");
}

void sort_one() {
    List<int> list;
    list.insertBack(1);
    list.sort();
    std::stringstream s;
    list.print(s);
    IS_TRUE(s.str() == "< 1 >");
}


void test_insert_at() {
    List<std::string> list;
    list.insertBack("bello");
    list.insertFront("world");
    list.insertFront("hello");
    list.insertAt(0, "zero");
    list.insertAt(1, "one");
    list.insertAt(5,"last");
    std::stringstream s;
    list.print(s);

    IS_TRUE(s.str() == "< zero one hello world bello last >");

    list.reverse();

    s = std::stringstream();
    list.print(s);
    IS_TRUE(s.str() == "< last bello world hello one zero >");
}

void test_failures() {
    List<std::string> list;
    list.insertBack("hello");
    list.insertBack("world");
    list.insertFront("goodbye");
    try {
        list.insertAt(-1, "bello");
    } catch (std::out_of_range e) {}
    catch (...) {IS_TRUE(false);}

    try {
        list.insertAt(4, "bello");
    } catch (std::out_of_range e) {}
    catch (...) {IS_TRUE(false);}
    

    try {
        list.removeAt(-1);
    } catch (std::out_of_range e) {}
    catch (...) {IS_TRUE(false);}

    try {
        list.removeAt(3);
    } catch (std::out_of_range e) {}
    catch (...) {IS_TRUE(false);}

    try {
        list.reverse(-1, 2);
    } catch (std::out_of_range e) {}
    catch (...) {IS_TRUE(false);}

    try {
        list.reverse(0, 3);
    } catch (std::out_of_range e) {}
    catch (...) {IS_TRUE(false);}
}