#include "doctest.h"
#include "sources/Fraction.hpp"

#include <stdexcept>
#include <stddef.h>
#include <limits>

TEST_CASE("Can't create a fraction with zero at denominator"){
    CHECK_THROWS(ariel::Fraction(4,0));
}

TEST_CASE("Can't divide by zero"){
    ariel::Fraction a(4,3);
    CHECK_THROWS(a/=0);
}

TEST_CASE("Overflowing integer throws an exception"){
    int max_int = std::numeric_limits<int>::max();
    int half_max_int = max_int/2;
    ariel::Fraction big1(max_int,2);
    ariel::Fraction big2(half_max_int+5,1);
    CHECK_THROWS(big1+big2);
    
}

TEST_CASE("Rounding floats correct"){
    ariel::Fraction pi_rounded(3141,1000);
    CHECK(pi_rounded==M_PI);
}

TEST_CASE("== operator works correctly with float at left"){
    ariel::Fraction a(3,1);
    CHECK(3.0==a);
}

TEST_CASE("Reduced form done correctly"){
    ariel::Fraction sixth1(1,6);
    ariel::Fraction sixth2(1,6);
    ariel::Fraction third_twelve(3,12);
    ariel::Fraction two_24(2,24);
    CHECK(sixth1+sixth2 == third_twelve+two_24);
    CHECK(sixth1-sixth2 == ariel::Fraction(3, 0));
    CHECK(sixth1*sixth2 == ariel::Fraction(2, 72));
    CHECK(sixth1/sixth2 == ariel::Fraction(9, 9));
}

TEST_CASE("Checking arithmetical operators works"){
    ariel::Fraction first(3, 4);
    ariel::Fraction second(1, 4);
    
    //operator *:
    CHECK(first*second == ariel::Fraction(3, 16));
    
    //operator /:
    CHECK(first/second == 3.0);

    //operator +:
    CHECK(first+second == 1.0);

    //operator -:
    CHECK(first-second == 0.5);
}

TEST_CASE("Checking relational operators works"){
    ariel::Fraction one(4,8);
    ariel::Fraction two(1,4);

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
    ariel::Fraction frac(0,1);

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
    ariel::Fraction first(3,18);
    ariel::Fraction second(9, 15);

    CHECK(first-first == 0);
    CHECK(second/second == ariel::Fraction(1,1));
}

TEST_CASE("Check assignment operator"){
    ariel::Fraction first(3,18);
    ariel::Fraction one(4,8);
    ariel::Fraction two(1,4);
    first = one - two;
    CHECK(first == 0.25);
}