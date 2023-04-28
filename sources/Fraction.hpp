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
        int can_bereduced_by=1;

        void check_overflow(int f_num, int s_num, char op) const;
        void check_denom_valid(int denominator, int construct_or_divide) const;
        void Unary_operator_chng(Fraction& fract);
        int find_best_divisor(int first, int second) const;
        int find_lcm(int first, int second) const;
        Fraction plus_mins_op(int thisnum, int thisdesn, int thisred, int othnum, int othdesn, int othred, int plus_minus) const;
        Fraction mul_div_op(int fup, int sup, int fdown, int sdown, int fred, int sred) const;

    public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(const Fraction &fract);
        Fraction(Fraction&&) noexcept;
        explicit Fraction(float flo);
        ~Fraction();

        //gets
        int getNumerator() const;
        int getDenominator() const;

        // + operator:
        Fraction operator+(const Fraction &other) const;
        Fraction operator+(float flo) const;
        friend Fraction operator+(float flo, const Fraction &fract);
        Fraction& operator+=(const Fraction &other);
        Fraction& operator+=(float flo);

        // - operator:
        Fraction operator-(const Fraction &other) const;
        Fraction operator-(float flo) const;
        // Fraction operator-(const Fraction &other);
        Fraction operator-() const;
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
        // Fraction operator/(const Fraction &other);
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