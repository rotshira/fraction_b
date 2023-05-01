#pragma once
#include <stdio.h>
#include <iostream>
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
        Fraction(float N); 

        //set
        //void setNumerator(int numnumerator_);
        //void setDenom(int denominator_);
        
        //get
        int getNumerator() ;
        int  getDenominator() ;

        //reduce the fraction
        Fraction reduce();

        
        // implement the function (  (1)fraction to fraction  (2) float to fraction )    )
        
        //add
        Fraction operator+(Fraction num);
        friend Fraction operator+(float other, Fraction frac);

        //subtract
        Fraction operator-(Fraction num);
        friend Fraction operator-(float other, Fraction frac);

        //mult
        Fraction operator*(Fraction num);
        friend Fraction operator*(float other, Fraction frac);

        //divide
        Fraction operator/(Fraction num);
        friend Fraction operator/(float other, Fraction frac);

        //equality
        bool operator==(Fraction num);
        friend bool operator==(float other, Fraction frac);

        //  > 
        bool operator>(Fraction num);
        friend bool operator>(float other, Fraction frac);

        //  <
        bool operator<(Fraction num);
        friend bool operator<(float other, Fraction frac);

        //  >=
        bool operator>=(Fraction num);
        friend bool operator>=(float other, Fraction frac);

        // <=
        bool operator<=(Fraction num);
        friend bool operator<=(float other, Fraction frac);

       // prefix
        Fraction operator++();
        Fraction operator--();

        // postfix
        Fraction operator++(int);
        Fraction operator--(int);

        // <<
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fr);
        
        // >>
        friend std::ostream& operator>>(std::ostream& os, const Fraction& fr);

    };
}















        



