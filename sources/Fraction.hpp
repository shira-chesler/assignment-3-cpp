#ifndef FRAC_HPP
#define FRAC_HPP

#include <cmath>
#include <vector>
#include <ostream>

namespace ariel{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        std::vector<int> divisors_of_numerator;
        std::vector<int> divisors_of_denominator;

        void find_divisors(char numer_or_deno);
        bool is_overflow(int first, int second) const;
    public:
        Fraction(int numerator, int denominator);
        Fraction(const Fraction &fract);
        Fraction(Fraction&&) noexcept;
        explicit Fraction(float flo);
        ~Fraction();

        // + operator:
        Fraction operator+(const Fraction &other) const;
        Fraction operator+(float flo) const;
        friend Fraction operator+(float flo, const Fraction &fract);
        Fraction& operator+=(const Fraction &other);
        Fraction& operator+=(float flo);

        // - operator:
        Fraction operator-(const Fraction &other) const;
        Fraction operator-(float flo) const;
        Fraction operator-(const Fraction &other);
        friend Fraction operator-(float flo, const Fraction &fract);
        Fraction& operator-=(const Fraction &other);
        Fraction& operator-=(float flo);
        
        // * operator:
        Fraction operator*(const Fraction &other) const;
        Fraction operator*(float flo) const;
        friend Fraction operator*(float flo, const Fraction &fract);
        Fraction& operator*=(const Fraction &other);
        Fraction& operator*=(float flo);

        // / operator:
        Fraction operator/(const Fraction &other) const;
        Fraction operator/(float flo) const;
        Fraction operator/(const Fraction &other);
        friend Fraction operator/(float flo, const Fraction &fract);
        Fraction& operator/=(const Fraction &other);
        Fraction& operator/=(float flo);

        // ++ operator:
        Fraction &operator++();

        // operator ++:
        const Fraction operator++(int);

        // -- operator:
        Fraction &operator--();

        // operator --:
        const Fraction operator--(int);

        // operator =:
        Fraction& operator=(const Fraction &other);
        Fraction& operator=(float flo);
        Fraction& operator=(Fraction&&) noexcept;
        // friend float operator=(float flo, const Fraction &fract);

        // == operator:
        bool operator==(const Fraction &other) const;
        bool operator==(float flo) const;
        friend bool operator==(float flo, const Fraction &fract);

        // != operator:
        bool operator!=(const Fraction &other) const;
        bool operator!=(float flo) const;
        friend bool operator!=(float flo, const Fraction &fract);

        // < operator:
        bool operator<(const Fraction &other) const;
        bool operator<(float flo) const;
        friend bool operator<(float flo, const Fraction &fract);

        // <= operator:
        bool operator<=(const Fraction &other) const;
        bool operator<=(float flo) const;
        friend bool operator<=(float flo, const Fraction &fract);

        // > operator:
        bool operator>(const Fraction &other) const;
        bool operator>(float flo) const;
        friend bool operator>(float flo, const Fraction &fract);

        // >= operator:
        bool operator>=(const Fraction &other) const;
        bool operator>=(float flo) const;
        friend bool operator>=(float flo, const Fraction &fract);

        // >> operator:
        friend std::istream &operator>>(std::istream &ins, Fraction &fract);

        // << operator:
        friend std::ostream &operator<<(std::ostream &outs, const Fraction &fract);
    };
}
#endif