//#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include "../src/vector.h"


// TEST_CASE("Vector::constructor size", "[weight=1][part=1][valgrind]") {
//     Vector<int> vec;
//     for (int i = 0; i < 10; i++) vec.push_back(i);

//     REQUIRE(10 == vec.size());
// }

/*
Not sure how to make catch2 test cases work, since it doesn't like the fact that I have no main and also
is not happy with me using REQUIRE
As a workaround, I'll just put test cases in main along with assert statements and a comment explaining what I'm testing

I'll also use valgrind when running it.
*/

int main() {

    //vector insert correct size
    Vector<int> vec;
    for (int i = 0; i < 10; i++) vec.push_back(i);

    assert(10 == vec.size());

    //testing clear size but also just clearing the vector for future use.
    vec.clear();
    assert (0 == vec.size());
    vec.insert(0,1);


    //testing constructor & equals operator
    vec = Vector<int>(5, 10);
    assert (5 == vec.size());
    std::stringstream s;
    vec.print(s);
    assert("< 10 10 10 10 10 >" == s.str());
    s.str("");


    //testing pop_back
    vec.pop_back();
    assert (4 == vec.size());

    //explicitly testing copy constructor
    Vector<int> v(5, 0);
    v = vec;
    assert(v.size() == 4);
    assert(vec.size() == 4);

    
    //test insert
    vec.clear();
    assert(vec.size() == 0);
    for (int i = 0; i < 7; i++) vec.insert(0,i);
    vec.print(s);
    assert (s.str() == "< 6 5 4 3 2 1 0 >");

    //test copy constructor and == and !=
    Vector<int> other(vec);
    assert(other == vec);
    assert(!(other != vec));
    assert(other != Vector<int>(5,0));

    //test pop_back
    while (!other.empty()) {
        other.pop_back();
    }
    assert(other.size() == 0);

    //test []
    other = vec;
    other[0] = 1;
    s.str("");
    other.print(s);
    assert(s.str() == "< 1 5 4 3 2 1 0 >");

    //test removeAt
    other.removeAt(0);
    other.removeAt(other.size() - 1);
    s.str("");
    other.print(s);
    assert(s.str() == "< 5 4 3 2 1 >");

    //test indexOf methods
    other.insert(0, 0);
    other.insert(0,15);
    other.insert(other.size(), 0);
    other.push_back(4);
    assert(other.firstIndexOf(0) == 1);
    assert(other.lastIndexOf(0) == 7);


    //testing reverse
    other.reverse();

    assert(other[2] == 1);
    s.str("");
    other.print(s);
    assert(s.str() == "< 4 0 1 2 3 4 5 0 15 >");

    return 0;
}