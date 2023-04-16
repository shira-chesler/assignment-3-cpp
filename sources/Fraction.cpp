#include "Fraction.hpp"


namespace ariel{
void Fraction::find_divisors(char numer_or_deno){

}

bool Fraction::is_overflow(int first, int second) const{
    return false;
}


//Destructor and Constructors
Fraction::Fraction(int numerator, int denominator){

}

Fraction::Fraction(const Fraction &fract){

}

Fraction::Fraction(float flo){

}

Fraction::Fraction(Fraction&&) noexcept{
    
}

Fraction::~Fraction(){

}


// + operator:
Fraction Fraction::operator+(const Fraction &other) const{
    return other;
}

Fraction Fraction::operator+(float flo) const{
    return *this;
}

Fraction operator+(float flo, const Fraction &fract){
    return fract;
}

Fraction& Fraction::operator+=(const Fraction &other){
    return *this;
}

Fraction& Fraction::operator+=(float flo){
    return *this;
}


// - operator:
Fraction Fraction::operator-(const Fraction &other) const{
    return other;
}

Fraction Fraction::operator-(float flo) const{
    return *this;
}

Fraction Fraction::operator-(const Fraction &other){
    return *this;
}

Fraction operator-(float flo, const Fraction &fract){
    return fract;
}

Fraction& Fraction::operator-=(const Fraction &other){
    return *this;
}

Fraction& Fraction::operator-=(float flo){
    return *this;
}


// * operator:
Fraction Fraction::operator*(const Fraction &other) const{
    return *this;
}

Fraction Fraction::operator*(float flo) const{
    return *this;
}

Fraction operator*(float flo, const Fraction &fract){
    return Fraction(0,0);
}

Fraction& Fraction::operator*=(const Fraction &other){
    return *this;
}

Fraction& Fraction::operator*=(float flo){
    return *this;
}


// / operator:
Fraction Fraction::operator/(const Fraction &other) const{
    return other;
}

Fraction Fraction::operator/(float flo) const{
    return *this;
}

Fraction Fraction::operator/(const Fraction &other){
    return *this;
}

Fraction operator/(float flo, const Fraction &fract){
    return fract;
}

Fraction& Fraction::operator/=(const Fraction &other){
    return *this;
}

Fraction& Fraction::operator/=(float flo){
    return *this;
}


// ++ operator:
Fraction &Fraction::operator++(){
    return *this;
}


// operator ++:
const Fraction Fraction::operator++(int){
    return *this;
}


// -- operator:
Fraction &Fraction::operator--(){
    return *this;
}


// operator --:
const Fraction Fraction::operator--(int){
    return *this;
}


// operator =:
Fraction& Fraction::operator=(const Fraction &other){
    return *this;
}

Fraction& Fraction::operator=(float flo){
    return *this;
}

Fraction& Fraction::operator=(Fraction&&) noexcept{
    return *this;
}

// == operator:
bool Fraction::operator==(const Fraction &other) const{
    return false;
}

bool Fraction::operator==(float flo) const{
    return false;
}

bool operator==(float flo, const Fraction &fract){
    return false;
}


// != operator:
bool Fraction::operator!=(const Fraction &other) const{
    return false;
}

bool Fraction::operator!=(float flo) const{
    return false;
}

bool operator!=(float flo, const Fraction &fract){
    return false;
}


// < operator:
bool Fraction::operator<(const Fraction &other) const{
    return false;
}

bool Fraction::operator<(float flo) const{
    return false;
}

bool operator<(float flo, const Fraction &fract){
    return false;
}


// <= operator:
bool Fraction::operator<=(const Fraction &other) const{
    return false;
}

bool Fraction::operator<=(float flo) const{
    return false;
}

bool operator<=(float flo, const Fraction &fract){
    return false;
}


// > operator:
bool Fraction::operator>(const Fraction &other) const{
    return false;
}

bool Fraction::operator>(float flo) const{
    return false;
}

bool operator>(float flo, const Fraction &fract){
    return false;
}


// >= operator:
bool Fraction::operator>=(const Fraction &other) const{
    return false;
}

bool Fraction::operator>=(float flo) const{
    return false;
}

bool operator>=(float flo, const Fraction &fract){
    return false;
}


// >> operator:
std::istream &operator>>(std::istream &ins, Fraction &fract){
    return ins;
}


// << operator:
std::ostream &operator<<(std::ostream &outs,const Fraction &fract){
    return outs;
}
}