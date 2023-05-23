#include <iostream>
#include "Fraction.hpp"

namespace ariel{
//checks if denominator is not 0 in the ctr or with / operator
void Fraction::check_denom_valid(int denominator, int construct_or_divide) const{
    if (denominator==0 && construct_or_divide==0)
    {
        throw std::invalid_argument("denominator can't be zero");
    }
    else if(denominator==0 && construct_or_divide==1)
    {
        throw std::runtime_error("can't divide by zero");
    }
}

//find gcd of the of 2 numbers
int Fraction::find_best_divisor(int first, int second) const{
    // Undefined gcd - Doesn't suppose to happen
    if (first == 0 && second == 0) {
        return 0;
    }
    else if (first == 0 || second == 0) {
        // returns the non-zero integer
        return std::max(first, second);
    }
    else if (first == second) {
        // Base case
        return first;
    }
    else {
        // Recursive case
        while (second != 0) {
            int temp = second;
            second = first % second;
            first = temp;
        }
        return first;
    }
}

//get the lcm of 2 numbers
int Fraction::find_lcm(int first, int second) const{
    int gcd = find_best_divisor(first, second);
    int mul = first*second;
    return mul/gcd;
}

//checks for overflow based on the operator between 2 numbers
void Fraction::check_overflow(int f_num, int s_num, char oper) const{
    long first = f_num;
    long second = s_num;
    if (oper=='+')
    {
        if(first+second != f_num+s_num)
        {
            throw std::overflow_error("add overflows");
        }
    }
    else if (oper=='-')
    {
        if(first-second != f_num-s_num)
        {
            throw std::overflow_error("sub overflows");
        }
    }
    else if (oper=='*')
    {
        if(first*second != f_num*s_num)
        {
            throw std::overflow_error("mul or div overflows");
        }
    }

}


//gets
int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}


//Destructor and Constructors
Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 1;
    this->can_bereduced_by = 1;
}

//default constructor
Fraction::Fraction(int numerator, int denominator){
    check_denom_valid(denominator, 0);
    this->numerator = numerator;
    this->denominator = denominator;
    this->can_bereduced_by = find_best_divisor(numerator,denominator);
}

//copy constructor
Fraction::Fraction(const Fraction &fract){
    check_denom_valid(fract.denominator, 0);
    this->numerator = fract.numerator;
    this->denominator = fract.denominator;
    this->can_bereduced_by = find_best_divisor(numerator,denominator);
}

//float constructor
Fraction::Fraction(float flo){
    this->numerator = (int) (flo*1000);
    this->denominator = 1000;
    this->can_bereduced_by = find_best_divisor(this->numerator,this->denominator);
}

//move constructor
Fraction::Fraction(Fraction&& other) noexcept{
    check_denom_valid(other.denominator, 0);
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->can_bereduced_by = other.can_bereduced_by;
}

//destructor
Fraction::~Fraction(){

}


//checks overflow for plus or minus
// let's assume that our fractions are thisnum/thisden and othnum/othden
// the parameters thisred and othred are the can_reduce_by parameter for each one of the fractions
// in order to add two fractions we need to find then a common denominator. how?
// we'll multiply both denominators in the number that would make them the lcm
// then, we'll multiply each one of the nuerators respectively in the number we multiplied its numerator so we won't change the fraction
// then we can add/ subtract
// before each multiplying operation, we'll check that it dosen't overflows 
Fraction Fraction::plus_mins_op(int thisnum, int thisden, int thisred, int othnum, int othden, int othred, int plus_minus) const{
    int lcm = find_lcm(thisden/thisred, othden/othred);
    check_overflow((thisnum/thisred), (lcm/(thisden/thisred)),'*');
    int f_num = (thisnum/thisred)*(lcm/(thisden/thisred));
    check_overflow((othnum/othred), (lcm/(othden/othred)),'*');
    int s_num = (othnum/othred)*(lcm/(othden/othred));
    Fraction tmp;
    if (plus_minus == 0)
    {
        check_overflow(f_num, s_num, '+');
        tmp = Fraction(f_num+s_num, lcm);
    }
    else if(plus_minus == 1)
    {
        check_overflow(f_num, s_num, '-');
        tmp = Fraction(f_num-s_num, lcm);
    }
    else{
        throw std::invalid_argument("invalid int that symbols the requiered operation");
    }
    int numerator = tmp.numerator/tmp.can_bereduced_by;
    int denominator = tmp.denominator/tmp.can_bereduced_by;
    return Fraction(numerator, denominator);
}

// + operator: frac+frac
Fraction Fraction::operator+(const Fraction &other) const{
    return plus_mins_op(this->numerator,this->denominator, this->can_bereduced_by, other.numerator,other.denominator,other.can_bereduced_by,0);
}

// + operator: frac+float
Fraction Fraction::operator+(float flo) const{
    return (*this)+Fraction(flo);
}

// + operator: float+frac
Fraction operator+(float flo, const Fraction &fract){
    return fract+Fraction(flo);
}

//+= operator: frac+=frac
Fraction& Fraction::operator+=(const Fraction &other){
    (*this) = (*this) + other;
    this->can_bereduced_by = find_best_divisor(this->numerator, this->denominator);
    return *this;
}

//+= operator: frac+=float
Fraction& Fraction::operator+=(float flo){
    (*this)+=Fraction(flo);
    return *this;
}


// - operator: frac-frac
Fraction Fraction::operator-(const Fraction &other) const{
    return plus_mins_op(this->numerator,this->denominator, this->can_bereduced_by, other.numerator,other.denominator,other.can_bereduced_by,1);
}

//- operator: frac-float
Fraction Fraction::operator-(float flo) const{
    return (*this)-Fraction(flo);
}

//- operator: -frac
Fraction Fraction::operator-() const{
    return Fraction(-this->numerator, this->denominator);
}

//- operator: float-frac
Fraction operator-(float flo, const Fraction &fract){
    return -(fract-flo);
}

//-= operator: frac-=frac
Fraction& Fraction::operator-=(const Fraction &other){
    (*this) = (*this)-other;
    this->can_bereduced_by = find_best_divisor(this->numerator, this->denominator);
    return *this;
}

//-= operator: frac-=float
Fraction& Fraction::operator-=(float flo){
    (*this)-=Fraction(flo);
    return *this;
}


//checks for overflow based on the operator * (multiply and divide)
// assume we have two fractions: first=(fup/fdown) and second=(sup/sdown)
// when multiplying two fractions, the two fractions are indeed first and second
// when dividing two fractions - one=a/b and two=c/d: a/b/c/d = a*d/b*c = (a/b) * (d/c) -
// which means that given the correct parameters, we need to compute here multyplying two fractions, as well
// before each multiply, we chack that it doesn't overflow
Fraction Fraction::mul_div_op(int fup, int sup, int fdown, int sdown, int fred, int sred) const{
    check_overflow((fup/fred), (sup/sred), '*');
    check_overflow((fdown/fred), (sdown/sred), '*');
    int num = (fup/fred)*(sup/sred);
    int den = (fdown/fred)*(sdown/sred);
    int reduce_by = find_best_divisor(num, den);
    den /= reduce_by;
    num /= reduce_by;
    return Fraction(num, den);
}

// * operator: frac*frac
Fraction Fraction::operator*(const Fraction &other) const{
    if(this->numerator == 0 || other.numerator == 0){
        return Fraction(0,1);
    }
    return mul_div_op(this->numerator, other.numerator,this->denominator,other.denominator,this->can_bereduced_by,other.can_bereduced_by);
}

// * operator: frac*float
Fraction Fraction::operator*(float flo) const{
    return (*this)*Fraction(flo);
}

// * operator: float*frac
Fraction operator*(float flo, const Fraction &fract){
    return fract*flo;
}

// *= operator: frac*=frac
Fraction& Fraction::operator*=(const Fraction &other){
    (*this) = (*this)*other;
    this->can_bereduced_by = find_best_divisor(this->numerator, this->denominator);
    return *this;
}

// *= operator: frac*=float
Fraction& Fraction::operator*=(float flo){
    (*this)*=Fraction(flo);
    return *this;
}


// / operator: frac/frac
Fraction Fraction::operator/(const Fraction &other) const{
    check_denom_valid(other.numerator, 1);
    return mul_div_op(this->numerator,other.denominator,this->denominator,other.numerator,this->can_bereduced_by,other.can_bereduced_by);
}

// / operator: frac/float
Fraction Fraction::operator/(float flo) const{
    return (*this)/Fraction(flo);
}

// / operator: float/frac
Fraction operator/(float flo, const Fraction &fract){
    return Fraction(flo)/fract;
}

// /= operator: frac/=frac
Fraction& Fraction::operator/=(const Fraction &other){
    (*this) = (*this)/other;
    this->can_bereduced_by = find_best_divisor(this->numerator, this->denominator);
    return *this;
}

// /= operator: frac/=float
Fraction& Fraction::operator/=(float flo){
    (*this)/=Fraction(flo);
    return *this;
}


//reduce frac for f++ ++f f-- --f
void Fraction::Unary_operator_chng(Fraction& fract){
    fract.can_bereduced_by = find_best_divisor(fract.numerator, fract.denominator);
    fract.numerator/=fract.can_bereduced_by;
    fract.denominator/=fract.can_bereduced_by;
    fract.can_bereduced_by = find_best_divisor(fract.numerator, fract.denominator);
}

// ++ operator:
Fraction &Fraction::operator++(){
    this->numerator+=this->denominator;
    Unary_operator_chng(*this);
    return *this;
}


// operator ++:
const Fraction Fraction::operator++(int){
    Fraction cpy(*this);
    this->numerator+=this->denominator;
    Unary_operator_chng(*this);
    return cpy;
}


// -- operator:
Fraction &Fraction::operator--(){
    this->numerator-=this->denominator;
    Unary_operator_chng(*this);
    return *this;
}


// operator --:
const Fraction Fraction::operator--(int){
    Fraction cpy(*this);
    this->numerator-=this->denominator;
    Unary_operator_chng(*this);
    return cpy;
}


// operator =: frac=frac
Fraction& Fraction::operator=(const Fraction &other){
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->can_bereduced_by = other.can_bereduced_by;
    return *this;
}

// operator =: frac=float
Fraction& Fraction::operator=(float flo){
    (*this) = Fraction(flo);
    return *this;
}

//move operator
Fraction& Fraction::operator=(Fraction&& fract) noexcept{
    (*this) = fract;
    fract.denominator = 1;
    fract.numerator = 0;
    fract.can_bereduced_by = 1;
    return *this;
}


// == operator: compare frac==frac
bool Fraction::operator==(const Fraction &other) const{
    float ths = static_cast<float>(this->numerator)/static_cast<float>(this->denominator);
    float othr = static_cast<float>(other.numerator)/static_cast<float>(other.denominator);
    if (std::abs(ths-othr)<0.001)
    {
        return true;
    }

    return (*this)>=other && (*this)<=other;
}

// == operator: compare frac==float
bool Fraction::operator==(float flo) const{
    return (*this)==Fraction(flo);
}

// == operator: compare float==frac
bool operator==(float flo, const Fraction &fract){
    return fract==flo;
}


// != operator:compare frac!=frac
bool Fraction::operator!=(const Fraction &other) const{
    return !((*this)==other);
}

// != operator:compare frac!=float
bool Fraction::operator!=(float flo) const{
    return (*this)!=Fraction(flo);
}

// != operator:compare float!=frac
bool operator!=(float flo, const Fraction &fract){
    return fract!=flo;
}


// < operator: frac<frac
bool Fraction::operator<(const Fraction &other) const{
    int thisnum = this->numerator;
    int thisden = this->denominator;
    int othnum = other.numerator;
    int othden = other.denominator;
    
    //multyplying will change sign - we want to make the other fraction positive
    if (thisnum<0 && othden<0){
        othden = -othden;
        othnum = -othnum;
    }
    //multyplying will change sign - we want to make this fraction positive
    if(thisden<0 && othnum<0){
        thisden = -thisden;
        thisnum = -thisnum;
    }
    return thisnum*othden<thisden*othnum;
}

// < operator: frac<float
bool Fraction::operator<(float flo) const{
    return (*this)<Fraction(flo);
}

// < operator: float<frac
bool operator<(float flo, const Fraction &fract){
    return fract>flo;
}


// <= operator: frac<=frac
bool Fraction::operator<=(const Fraction &other) const{
    return !((*this)>other);
}

// <= operator: frac<=float
bool Fraction::operator<=(float flo) const{
    return (*this)<=Fraction(flo);;
}

// <= operator: float<=frac
bool operator<=(float flo, const Fraction &fract){
    return !(fract<flo);
}


// > operator: frac>frac
bool Fraction::operator>(const Fraction &other) const{
    return other<(*this);
}

// > operator: frac>float
bool Fraction::operator>(float flo) const{
    return (*this)>Fraction(flo);;
}

// > operator: float>frac
bool operator>(float flo, const Fraction &fract){
    return fract<flo;
}


// >= operator:frac>=frac
bool Fraction::operator>=(const Fraction &other) const{
    return !((*this)<other);
}

// >= operator:frac>=float
bool Fraction::operator>=(float flo) const{
    return (*this)>=Fraction(flo);
}

// >= operator:float>=frac
bool operator>=(float flo, const Fraction &fract){
    return fract<=flo;
}


// >> operator: input from user seperated by space
std::istream &operator>>(std::istream &ins, Fraction &fract){
    int num, den;
    bool created = false;
    if(ins >> num)
    {
        if(ins >> den)
        {
            if(den==0)
            {
                throw std::runtime_error("denominator can't be zero");
            }
            fract = Fraction(num, den);
            created = true;
        }
    }
    if(!created)
    {
        throw std::runtime_error("arguments problem");
    }
    return ins;
}


// << operator: output the fraction nume/deno
std::ostream &operator<<(std::ostream &outs,const Fraction &fract){
    // printing reduced fraction
    int fracden = fract.denominator/fract.can_bereduced_by;
    int fracnum = fract.numerator/fract.can_bereduced_by;
    
    // the minus is below the fraction bar
    if (fracden<0)
    {
        fracden = - fracden;
        fracnum = - fracnum;
    }

    outs << fracnum << "/" << fracden;
    return outs;
}
}