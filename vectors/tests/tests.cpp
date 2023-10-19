#include <catch2/catch_test_macros.hpp>

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

    return 0;
}