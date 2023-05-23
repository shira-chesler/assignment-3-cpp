#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(1, 2), b(1, 4);
    Fraction c;

    std::cout<< "------2 OUT OF THE 3-------" << std::endl;
    Fraction d(a);
    if(d.getNumerator() == a.getNumerator() && d.getDenominator() == a.getDenominator()){
        std::cout<< "copy constructor works" << std::endl;
    } else throw std::runtime_error("copy constructor dosen't work");
    Fraction e = b;
    if(e.getNumerator() == b.getNumerator() && e.getDenominator() == b.getDenominator()){
        std::cout<< "assignment operator works" << std::endl;
    } else throw std::runtime_error("assignment opertaor dosen't work");

    std::cout<< "" << std::endl;
    std::cout<< "------COMPARISON OPERATORS-------" << std::endl;
    if(a == a){
         std::cout<< "operator == works" << std::endl;
    } else throw std::runtime_error("operator == dosen't work");
    if(a != b){
         std::cout<< "operator != works" << std::endl;
    } else throw std::runtime_error("operator != dosen't work");
    if(b < a){
         std::cout<< "operator < works" << std::endl;
    } else throw std::runtime_error("operator < dosen't work");
    if(a > b){
         std::cout<< "operator > works" << std::endl;
    } else throw std::runtime_error("operator > dosen't work");
    if(b <= a){
         std::cout<< "operator <= works" << std::endl;
    } else throw std::runtime_error("operator <= dosen't work");
    if(a <= a){
         std::cout<< "operator <= works (for self as well)" << std::endl;
    } else throw std::runtime_error("operator <= dosen't work (for self)");
    if(a >= b){
         std::cout<< "operator >= works" << std::endl;
    } else throw std::runtime_error("operator >= dosen't work");
    if(a >= a){
         std::cout<< "operator >= works (for self as well)" << std::endl;
    } else throw std::runtime_error("operator >= dosen't work (for self)");

    std::cout<< "" << std::endl;
    std::cout<< "------ARITHMETIC OPERATORS-------" << std::endl;
    c = a + b;
    if(c.getNumerator() == 3 && c.getDenominator() == 4){
        std::cout<< "operator + works" << std::endl;
    } else throw std::runtime_error("operator + dosen't work");

    c = a - b;
    if(c.getNumerator() == 1 && c.getDenominator() == 4){
        std::cout<< "operator - works" << std::endl;
    } else throw std::runtime_error("operator - dosen't work");

    c = a * b;
    if(c.getNumerator() == 1 && c.getDenominator() == 8){
        std::cout<< "operator * works" << std::endl;
    } else throw std::runtime_error("operator * dosen't work");

    c = a / b;
    if(c.getNumerator() == 2 && c.getDenominator() == 1){
        std::cout<< "operator / works" << std::endl;
    } else throw std::runtime_error("operator / dosen't work");

    std::cout<< "" << std::endl;
    std::cout<< "------CHAINING OPERATORS-------" << std::endl;
    Fraction f(1, 2);
    f += Fraction(1, 2);
    if(f.getNumerator() == 1 && f.getDenominator() == 1){
        std::cout<< "operator += works" << std::endl;
    } else throw std::runtime_error("operator += dosen't work");

    Fraction g(3, 4);
    g -= Fraction(1, 4);
    if(g.getNumerator() == 1 && g.getDenominator() == 2){
        std::cout<< "operator -= works" << std::endl;
    } else throw std::runtime_error("operator -= dosen't work");

    Fraction h(1, 2);
    h *= Fraction(1, 2);
    if(h.getNumerator() == 1 && h.getDenominator() == 4){
        std::cout<< "operator *= works" << std::endl;
    } else throw std::runtime_error("operator *= dosen't work");

    Fraction i(1, 2);
    i /= Fraction(1, 2);
    if(i.getNumerator() == 1 && i.getDenominator() == 1){
        std::cout<< "operator /= works" << std::endl;
    } else throw std::runtime_error("operator /= dosen't work");
    
    std::cout<< "" << std::endl;
    std::cout<< "------PREFIX AND POSTFIX OPERATORS-------" << std::endl;
    a++;
    if(a.getNumerator() == 3 && a.getDenominator() == 2){
        std::cout<< "postfix ++ operator works" << std::endl;
    } else throw std::runtime_error("postfix ++ operatot dosen't work");
    b--;
    if(b.getNumerator() == -3 && b.getDenominator() == 4){
        std::cout<< "postfix -- operator works" << std::endl;
    } else throw std::runtime_error("postfix -- operatot dosen't work");
    Fraction p(1, 2);
    ++p;
    if(p.getNumerator() == 3 && p.getDenominator() == 2){
        std::cout<< "prefix ++ operator works" << std::endl;
    } else throw std::runtime_error("prefix ++ operatot dosen't work");
    
    
    std::cout<< "" << std::endl;
    std::cout<< "------REDUCED FORM-------" << std::endl;
    Fraction k(2, 4);
    k*=1;
    if(k.getNumerator() == 1 && k.getDenominator() == 2){
        std::cout<< "reduced the fraction correctly" << std::endl;
    } else throw std::runtime_error("didn't reduced the fraction correctly");
    Fraction l(-1, -2);
    l*=1;
    if(l.getNumerator() == 1 && l.getDenominator() == 2){
        std::cout<< "reduced the fraction correctly (got rid of - up and down)" << std::endl;
    } else throw std::runtime_error("didn't reduced the fraction correctly (needed to get rid of - up and down)");
    Fraction m(0.5);
    m*=1;
    if(m.getNumerator() == 1 && m.getDenominator() == 2){
        std::cout<< "reduced the fraction correctly (reduced from constructor of float)" << std::endl;
    } else throw std::runtime_error("didn't reduced the fraction correctly (needed to reduce from constructor of float)");

    std::cout<< "" << std::endl;
    std::cout<< "------INPUT OUTPUT STREAM-------" << std::endl;
    std::stringstream ss;
    ss << Fraction(1, 2);
    if(ss.str() == "1/2"){
        std::cout<< "output stream works" << std::endl;
    } else throw std::runtime_error("output stream dosen't work");

    ss.str(""); // clear the stringstream
    ss << Fraction(-1, 2);
    if(ss.str() == "-1/2"){
        std::cout<< "output stream works with negatives as well" << std::endl;
    } else throw std::runtime_error("output stream dosen't work (with negatives)");

    Fraction n;
    ss.str("3 4");
    ss >> n;
    if(n.getNumerator() == 3 && n.getDenominator() == 4){
        std::cout<< "input stream works" << std::endl;
    } else throw std::runtime_error("input stream dosen't work");

    std::cout<< "" << std::endl;
    std::cout<< "------CATCH ERROR-------" << std::endl;
    bool caught = false;
    try {
        Fraction o(1, 0);
    } catch (std::invalid_argument &e) {
        caught = true;
    }
    if(caught){
       std::cout<< "caught creating a non-valid fraction successfully" << std::endl;
    } else throw std::runtime_error("didn't caught creating a non-valid fraction");
    caught = false;
    try {
        ss.str("3");
        ss >> n;
    } catch (std::runtime_error &e) {
        caught = true;
    }
    if(caught){
       std::cout<< "caught creating giving input stream invalid arguments" << std::endl;
    } else throw std::runtime_error("didn't caught giving input stream invalid arguments");

    std::cout << "" << std::endl;
    std::cout << "------THE END-------" << std::endl;
    return 0;
}
