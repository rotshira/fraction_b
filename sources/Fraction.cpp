#include <stdio.h>
#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <string>
#include <cstdlib>
#include<limits>
#include <vector>
 

using namespace ariel;
using namespace std;
namespace ariel
{
int max = std::numeric_limits<int>::max(); // from test2
int min = std::numeric_limits<int>::min();


//constructor
Fraction::Fraction(int numerator_, int denominator_)
{
    int g =std::gcd(numerator_,denominator_);
    if (denominator_!= 0) 
    {
        if(denominator_ > 0 && numerator_ > 0)
        {
     this->numerator = numerator_/g;
     this->denominator = denominator_/g;
        }
        else if(denominator_ < 0 &&  numerator_ > 0 || denominator_ > 0 &&  numerator_ < 0 ) 
        {
        this->numerator = -(abs(numerator_))/g;
        this->denominator = abs(denominator_)/g;
    }
    else {
    this->numerator = abs(numerator_)/g;
    this->denominator = abs(denominator_)/g;
    }
    }
    else
    throw std::invalid_argument( "Division by zero" );

}

Fraction::Fraction(float number)
{
      Fraction f(number*1000,1000);
      this->numerator =f.numerator;
      this->denominator = f.denominator;
}

Fraction::Fraction()
    {
        this->numerator = 0;
        this->denominator = 1;
    }

// get
int Fraction::getNumerator() const 
{
return this->numerator ;
}

int Fraction::getDenominator() const
{
return this->denominator ;
}

//set
 void Fraction::setNumerator(int numnumerator_)
    {
        this->numerator = numnumerator_;
    }
void Fraction::setDenom(int denominator_)
    {
        this->denominator = denominator_;
    }
        
Fraction Fraction::reduce()
{
     int d =std::gcd(numerator,denominator);
     int x,y;
     x = numerator/d;
     y = denominator/d;
    Fraction f(x,y);
    return f;
}

//overflow
   int  Fraction::over(int numerator1, int denominator1, int numerator2, int denominator2) const
    {
        if((float)numerator1 * (float)numerator2 > max || (float)numerator1 * (float)numerator2 < min ||
        (float)denominator1 * (float)denominator2 > max || (float)denominator1 * (float)denominator2 < min)
        {
            return 1;  
        }
        return 0;
    }

//fraction to float
    float Fraction::To_Float( Fraction fraction) const 
    {
    int x = fraction.getNumerator() * 1000 / fraction.getDenominator();
    float t = static_cast<float>(x) / 1000.0f;
    return t;
}


 //add
 Fraction Fraction::operator+(  Fraction num)
        {
            int Numerator1 = this->numerator;
            int denominator1 = this->denominator;
            int numerator2 = num.getNumerator();
            int denominator2 = num.getDenominator();
            int f1 = Numerator1 * denominator2;
            int f2 = numerator2 * denominator1;
            int f3 = denominator1 * denominator2;
            Fraction ans(f1+f2,f3);
            ans.reduce();
            if(over(Numerator1,denominator1,numerator2,denominator2)==1)
            throw std::overflow_error("overflow");
            else
            return ans;
        }

        
        
 Fraction operator+(float other,Fraction frac)
        {
           return (frac + Fraction(other)).reduce(); 
        }

//         //subtract
        Fraction Fraction::operator-( Fraction num)
        {
            int Numerator1 = this->numerator;
            int denominator1 = this->denominator;
            int numerator2 = num.getNumerator();
            int denominator2 = num.getDenominator();
            int f1 = Numerator1 * denominator2;
            int f2 = numerator2 * denominator1;
            int f3 = denominator1 * denominator2;
            if(over(Numerator1,denominator1,numerator2,denominator2)==1)
            throw std::overflow_error("overflow");
            else
            return Fraction(f1-f2,f3).reduce();
        }
        
         Fraction operator-(float other, Fraction frac)
         {
            return ((-1)*(frac - Fraction(other))).reduce();
         }

//         //mult
        Fraction Fraction::operator*( Fraction num)
        {
           int f1 = num.getNumerator() * this->numerator;
           int f2 = num.getDenominator() * this->denominator;
           Fraction ans(f1,f2);
            if(over(this->numerator,this->denominator,num.getNumerator(),num.getDenominator())==1)
            throw std::overflow_error("overflow");
            else
           return Fraction(f1,f2).reduce();
        }


        Fraction operator*(float other, Fraction frac)
         {
            return (Fraction(other)*frac).reduce();
         }

//         //divide
        Fraction Fraction::operator/(Fraction num)
        {
            if(num.getNumerator()!=0){
           int f1 = this->numerator * num.getDenominator();
           int f2 = this->denominator * num.getNumerator();
            if(over(this->numerator,this->denominator,num.getNumerator(),num.getDenominator())==1)
            throw std::overflow_error("overflow");
            else
           return Fraction(f1,f2).reduce();
            }
            throw std::runtime_error( "Division by zero" );
        }

        Fraction operator/(float other, Fraction frac)
         {
            return (Fraction(other)/frac).reduce();
         }



//         //equality
        bool Fraction::operator==( Fraction num)const
        {
            int n1 = this->numerator;
            int d1 = this->denominator;
            int n2 = num.getNumerator();
            int d2 = num.getDenominator();
            Fraction x(n1*d2 , d1*d2);
            Fraction y(n2*d1,d2*d1);
           Fraction temp(n1,d1); 
        if(To_Float(temp) == To_Float(num))
        {
            return true;
        }
            else return false;
        }


         bool operator==( float other, Fraction frac)
         {
                 return ((frac == Fraction(other)));
         }

         //  > 
        bool Fraction::operator>( Fraction num)const
        {
            int n1 = this->numerator;
            int n2 = num.getNumerator();
            int d1 = this->denominator;
            int d2 = num.getDenominator();
            int ans1 = n1*d2;
            int ans2 = n2*d1;
            if(ans1 > ans2)
            return true;
            else return false;

        }

        bool operator>( float other, Fraction frac)
         {
                return ( frac < Fraction(other));   
         }

//         //  <
         bool Fraction::operator<( Fraction num)const
        {
            int n1 = this->numerator;
            int n2 = num.getNumerator();
            int d1 = this->denominator;
            int d2 = num.getDenominator();
            int ans1 = n1*d2;
            int ans2 = n2*d1;
            if(ans1 < ans2)
            return true;
            else return false;
        }

        bool operator<( float other, Fraction frac)
         {

                 return (frac > Fraction(other));  
         }
      
      //  >=
         bool Fraction::operator>=( Fraction num)const
        {
             int n1 = this->numerator;
            int n2 = num.getNumerator();
            int d1 = this->denominator;
            int d2 = num.getDenominator();
            int ans1 = n1*d2;
            int ans2 = n2*d1;
            if(ans1 >= ans2)
            return true;
            else return false;
        }

         bool operator>=( float other, Fraction frac)
         {
                 return (frac <=Fraction(other));
         }

//         // <=
        bool Fraction::operator<=( Fraction num)const
        {
            int n1 = this->numerator;
            int n2 = num.getNumerator();
            int d1 = this->denominator;
            int d2 = num.getDenominator();
            int ans1 = n1*d2;
            int ans2 = n2*d1;
            if(ans1 <= ans2)
            return true;
            else return false;
        }

         bool operator<=( float other, Fraction frac)
         {
                  return (frac >=Fraction(other));
         }

        Fraction Fraction::operator++() // prefix
        {
           *this = *this+Fraction(1,1);
            return *this;
        }
        
        Fraction Fraction:: operator--()
        {
            *this = *this-Fraction(1,1);
            return *this;
        }

        // postfix
        Fraction Fraction:: operator++(int) //postfix
        {
            Fraction temp = *this;
            ++*this;
            return temp;
        }
        Fraction Fraction:: operator--(int)
        {
            Fraction temp = *this;
             --*this;
             return temp;
        }
        // <<  // output
       std::ostream& operator<<(std::ostream& os, const Fraction& frac)
    {
        return (os << frac.numerator << '/' << frac.denominator);
    }
 
std::istream& operator>>(std::istream& input, Fraction& fraction) {
    int numerator = 0, denominator = 0;

    // Read the numerator
    input >> numerator;
    if(input.fail()) {
        throw std::runtime_error("Invalid input. Numerator must be an integer.");
    }

    // Read the denominator
    input >> denominator;
    if(input.fail()) {
        throw std::runtime_error("Invalid input. Denominator must be an integer.");
    }
    else if(denominator == 0) {
        throw std::runtime_error("Invalid input. Denominator cannot be zero.");
    }

    // Set the fraction's numerator and denominator
    fraction = Fraction(numerator, denominator);

    // Return the input stream
    return input;
}

}

















