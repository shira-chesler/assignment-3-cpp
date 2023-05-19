#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    ariel::Fraction a(1, 2);
    ariel::Fraction b(1, 4);
    ariel::Fraction c;

    //arithmetic operators
    c = a + b;
    assert(c.getNumerator() == 3 && c.getDenominator() == 4);

    c = a - b;
    assert(c.getNumerator() == 1 && c.getDenominator() == 4);

    c = a * b;
    assert(c.getNumerator() == 1 && c.getDenominator() == 8);

    c = a / b;
    assert(c.getNumerator() == 2 && c.getDenominator() == 1);

    //comparison operators
    assert(a == a);
    assert(a != b);
    assert(b < a);
    assert(a > b);
    assert(b <= a);
    assert(a <= a);
    assert(a >= b);
    assert(a >= a);

    //copy ctr
    ariel::Fraction d(a);
    assert(d.getNumerator() == a.getNumerator() && d.getDenominator() == a.getDenominator());
    //copy assignment
    ariel::Fraction e = b;
    assert(e.getNumerator() == b.getNumerator() && e.getDenominator() == b.getDenominator());

    //post a pre
    a++;
    assert(a.getNumerator() == 3 && a.getDenominator() == 2);
    b--;
    assert(b.getNumerator() == -3 && b.getDenominator() == 4);

    ariel::Fraction p(1, 2);
    ++p;
    assert(p.getNumerator() == 3 && p.getDenominator() == 2);

    bool caught = false;
    //errors
    try {
        ariel::Fraction f(1, 0);
    } catch (std::invalid_argument &e) {
        caught = true;
    }
    assert(caught);
    //reduced
    ariel::Fraction g(2, 4);
    g*=1;
    assert(g.getNumerator() == 1 && g.getDenominator() == 2);
    ariel::Fraction h(-1, -2);
    h*=1;
    assert(h.getNumerator() == 1 && h.getDenominator() == 2);
    ariel::Fraction i(0.5);
    i*=1;
    assert(i.getNumerator() == 1 && i.getDenominator() == 2);

    ariel::Fraction j(1, 2);
    j += ariel::Fraction(1, 2);
    assert(j.getNumerator() == 1 && j.getDenominator() == 1);

    ariel::Fraction k(3, 4);
    k -= ariel::Fraction(1, 4);
    assert(k.getNumerator() == 1 && k.getDenominator() == 2);

    ariel::Fraction l(1, 2);
    l *= ariel::Fraction(1, 2);
    assert(l.getNumerator() == 1 && l.getDenominator() == 4);

    ariel::Fraction m(1, 2);
    m /= ariel::Fraction(1, 2);
    assert(m.getNumerator() == 1 && m.getDenominator() == 1);

    std::stringstream ss;
    ss << ariel::Fraction(1, 2);
    assert(ss.str() == "1/2");

    ss.str(""); // clear the stringstream
    ss << ariel::Fraction(-1, 2);
    assert(ss.str() == "-1/2");

    ariel::Fraction n;
    ss.str("3 4");
    ss >> n;
    assert(n.getNumerator() == 3 && n.getDenominator() == 4);

    std::cout << "All tests passed." << std::endl;
    return 0;
}
