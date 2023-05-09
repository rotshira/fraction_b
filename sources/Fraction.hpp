#pragma once
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
    
    public:
        Fraction(int numerator_, int denominator_);
        //float to fraction
        Fraction(float number); 
        //Empty constructor
        Fraction();
        
        //set
        void setNumerator(int numnumerator_);
        void setDenom(int denominator_);
        
        //get
        int getNumerator () const;
        int  getDenominator() const;

        //reduce the fraction
        Fraction reduce();

        //check over_flow
        int over(int aaa, int bbb , int ccc , int ddd)const;

        //frection to float and reduce to 3 digit 
        float To_Float( Fraction fraction)const;
       

        // implement the function (  (1)fraction to fraction  (2) float to fraction )   )
        
        //add
        Fraction operator+(  Fraction num) ;
        friend Fraction operator+(float other,  Fraction frac);

        //subtract
        Fraction operator-( Fraction num);
        friend Fraction operator-(float other, Fraction frac);

        //mult
        Fraction operator*(Fraction num);
        friend Fraction operator*(float other, Fraction frac);

        //divide
        Fraction operator/(  Fraction num);
        friend Fraction operator/(float other, Fraction frac);

        //equality
        bool operator==( Fraction num) const;
       
        friend bool operator==( float other, Fraction frac);

        //  > 
        bool operator>(Fraction num)const;
        friend bool operator>(float other, Fraction frac);

        //  <
        bool operator<( Fraction num)const;
        friend bool operator<( float other, Fraction frac);

        // >=
        bool operator>=(Fraction num)const;
        friend bool operator>=( float other,  Fraction frac);

        // <=
        bool operator<=( Fraction num)const;
        friend bool operator<=( float other,  Fraction frac);

       // prefix
        Fraction operator++();
        Fraction operator--();

        // postfix
        Fraction operator++(int);
        Fraction operator--(int);

        // <<
        friend std::ostream& operator<<(std::ostream& ostr, const Fraction& frac);
        
        // >>
       friend std::istream& operator>>( std::istream& input, Fraction& fraction) ;
       
       
    };

    };
    
















        



