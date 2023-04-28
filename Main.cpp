#include "sources/Fraction.hpp"
#include <iostream>
int main()
{
    ariel::Fraction sixth1(1,6);
    ariel::Fraction sixth2(1,6);
    ariel::Fraction third_twelve(3,12);
    ariel::Fraction two_24(2,24);
    std::cout << (sixth1+sixth2) << std::endl;
    std::cout << (third_twelve+two_24) << std::endl;
    std::cout << (sixth1-sixth2) << std::endl;
    std::cout << (ariel::Fraction(1, 6)) << std::endl;

    ariel::Fraction pos(-6,-3);
    std::cout << pos << std::endl;

    std::cout << ariel::Fraction(0,6) << std::endl;

    ariel::Fraction first(3, 4);
    ariel::Fraction second(1, 4);
    std::cout << (first-0.5) << std::endl;
    std::cout << first-second-0.5 << std::endl;

    ariel::Fraction d(4, 5);
    float e = 0.4;
    ariel::Fraction f = e - d; 
    std::cout << f << std::endl;

    ariel::Fraction g(4, 5);
    float h = 0.4;
    ariel::Fraction i = h / g;
    std::cout << i << std::endl;

    std::cout << ariel::Fraction{0, 1} * ariel::Fraction{-4, 7} << std::endl;

}