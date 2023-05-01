#include <stdio.h>
#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <algorithm>

// using namespace ariel;
using namespace std;
namespace ariel
{

//constructor
Fraction::Fraction(int numerator_, int denominator_)
{
    if (denominator_!= 0) 
    {
    // int d = __gcd(numerator_,denominator_);
    // this->numerator = numerator_/d;
    // this->denominator = denominator_/d;
    this->numerator = numerator_;
    this->denominator = denominator_;

    }

}

Fraction::Fraction(float N)
{
      Fraction f(N*1000,1000);
      this->numerator =f.numerator;
      this->denominator = f.denominator;
}

//set
// void Fraction::setNumerator(int numerator_)
// {
//     this->numerator = numerator_;
// }

// void Fraction::setDenom(int denominator_)
// {
//     // if(denominator_ == 0)
//     // {
//     //     ;
//     // }
//     this->denominator = denominator_;
// }

// get
int Fraction::getNumerator() 
{
return this->numerator ;
}

int Fraction::getDenominator() 
{
return this->denominator ;
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


 //add
 Fraction Fraction::operator+(Fraction num)
        {
            int Numerator1 = this->numerator;
            int denominator1 = this->denominator;
            int numerator2 = num.getNumerator();
            int denominator2 = num.getDenominator();
            int f1 = Numerator1 * denominator2;
            int f2 = numerator2 * denominator1;
            int f3 = denominator1 * denominator2;
            Fraction ans(f1+f2,f3 );
            return Fraction(f1+f2,f3).reduce();
        }
        
 Fraction operator+(float other, Fraction frac)
        {
           return (frac + Fraction(other)).reduce(); 
        }

//         //subtract
        Fraction Fraction::operator-(Fraction num)
        {
            int Numerator1 = this->numerator;
            int denominator1 = this->denominator;
            int numerator2 = num.getNumerator();
            int denominator2 = num.getDenominator();
            int f1 = Numerator1 * denominator2;
            int f2 = numerator2 * denominator1;
            int f3 = denominator1 * denominator2;
            return Fraction(f1-f2,f3).reduce();
        }
        
         Fraction operator-(float other, Fraction frac)
         {
            return ((-1)*(frac - Fraction(other))).reduce();
         }

//         //mult
        Fraction Fraction::operator*(Fraction num)
        {
           int f1 = num.getNumerator() * this->numerator;
           int f2 = num.getDenominator() * this->denominator;
           Fraction ans(f1,f2);
           return Fraction(f1,f2).reduce();
        }


        Fraction operator*(float other, Fraction frac)
         {
            return (Fraction(other)*frac).reduce();
         }

//         //divide
        Fraction Fraction::operator/(Fraction num)
        {
           int f1 = this->numerator * num.getDenominator();
           int f2 = this->denominator * num.getNumerator();
           return Fraction(f1,f2).reduce();
        }

        Fraction operator/(float other, Fraction frac)
         {
            return (Fraction(other)/frac).reduce();
         }



//         //equality
        bool Fraction::operator==(Fraction num)
        {
            int n1 = this->numerator;
            int d1 = this->denominator;
            int n2 = num.getNumerator();
            int d2 = num.getDenominator();
            if (n1 == n2 && d1 == d2)
            return true;
            else return false;
        }
//         

         bool operator==(float other, Fraction frac)
         {
                 return ((frac == Fraction(other)));
         }

         //  > 
        bool Fraction::operator>(Fraction num)
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

        bool operator>(float other, Fraction frac)
         {
                return (Fraction(other)> frac);   
         }

//         //  <
         bool Fraction::operator<(Fraction num)
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

        bool operator<(float other, Fraction frac)
         {

                 return (Fraction(other)> frac);  
         }
      
      //  >=
         bool Fraction::operator>=(Fraction num)
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

         bool operator>=(float other, Fraction frac)
         {
                 return (Fraction(other)>= frac);
         }

//         // <=
        bool Fraction::operator<=(Fraction num)
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

         bool operator<=(float other, Fraction frac)
         {
                  return (Fraction(other)<= frac);;
         }

        Fraction Fraction::operator++() // prefix
        {
        //    int n1 = this->numerator;
        //    int d1 = this->denominator;
        //    Fraction f1(n1,d1);
        //    Fraction f2(1,1);
        //    Fraction ans = (f1+f2);
        //    ans.reduce();
        //    return ans;
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
            
        //    int n1 = this->numerator;
        //    int d1 = this->denominator;
        //    Fraction f1(n1,d1);
        //    return f1;
        //    Fraction f2(1,1);
        //    Fraction ans = (f1+f2);
        //     ans.reduce();

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
        // <<
       std::ostream& operator<<(std::ostream& os, const Fraction& fr)
    {
        // write obj to stream
        return (os << fr.numerator << '/' << fr.denominator << endl);
        
    }

        // >>
        std::ostream& operator>>(std::ostream& os, const Fraction& fr)
    {
        // write obj to stream
        return os;
    }
}




















