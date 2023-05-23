#include "doctest.h"
#include "sources/Fraction.hpp"

#include <iostream>
#include <stdexcept>
#include <stddef.h>
#include <limits>

using namespace ariel;

TEST_CASE("Can't create a fraction with zero at denominator"){
    CHECK_THROWS(Fraction(4,0));
}

TEST_CASE("Can't divide by zero"){
    Fraction a(4,3);
    CHECK_THROWS(a/=0);
}

TEST_CASE("Overflowing integer throws an exception"){
    int max_int = std::numeric_limits<int>::max();
    int half_max_int = max_int/2;
    Fraction big1(max_int,2);
    Fraction big2(half_max_int+5,1);
    CHECK_THROWS(big1+big2);
    
}

TEST_CASE("Rounding floats correct"){
    Fraction pi_rounded(3141,1000);
    CHECK(pi_rounded==M_PI);
}

TEST_CASE("== operator works correctly with float at left"){
    Fraction a(3,1);
    CHECK(3.0==a);
}

TEST_CASE("Reduced form done correctly"){
    Fraction sixth1(1,6);
    Fraction sixth2(1,6);
    Fraction third_twelve(3,12);
    Fraction two_24(2,24);
    CHECK((sixth1+sixth2) == (third_twelve+two_24));
    CHECK((sixth1-sixth2) == (Fraction(0, 6)));
    CHECK((sixth1*sixth2) == (Fraction(2, 72)));
    CHECK((sixth1/sixth2) == (Fraction(9, 9)));
}

TEST_CASE("Checking arithmetical operators works"){
    Fraction first(3, 4);
    Fraction second(1, 4);
    
    //operator *:
    CHECK(first*second == Fraction(3, 16));
    
    //operator /:
    CHECK(first/second == 3.0);

    //operator +:
    CHECK(first+second == 1.0);

    //operator -:
    CHECK(first-second == 1.0/2);
}

TEST_CASE("Checking relational operators works"){
    Fraction one(4,8);
    Fraction two(1,4);

    // > operator:
    CHECK(one > two);

    // < operator:
    CHECK(two < one);

    // >= operator:
    CHECK(one >= two);

    // <= operator:
    CHECK(two <= one);

    // != operator:
    CHECK(two != one);

}

TEST_CASE("Checking unary operators works"){
    Fraction frac(0,1);

    // ++ operator:
    CHECK(++frac == 1.0);

    // -- operator:
    CHECK(--frac == 0.0);

    // operator ++:
    CHECK(frac++ == 0.0);

    // operator --:
    CHECK(frac-- == 1.0);
}

TEST_CASE("Fraction against itself"){
    Fraction first(3,18);
    Fraction second(9, 15);

    CHECK(first-first == 0);
    CHECK(second/second == Fraction(1,1));
}

TEST_CASE("Check assignment operator"){
    Fraction first(3,18);
    Fraction one(4,8);
    Fraction two(1,4);
    first = one - two;
    CHECK(first == 0.25);
}