#include <iostream>
#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"
using namespace ariel;
#include "doctest.h"
using namespace doctest;

//add
TEST_CASE("+ (add) test")
{
    Fraction a(1,4), b(1,4) ,c(1,2);
    CHECK(a+b == c);
}

// TEST_CASE("+ (add) test")
// {
//     Fraction a(1,0), b(1,2) ;
//      throw std::invalid_argument("Division by zero");
// }
//////////////////////////////////////////
TEST_CASE("+ (add) test")
{
    Fraction b(1,4),c(1,2);
    float a = 0.25;
    CHECK(a+b == c);
    CHECK(b+a == c);
}
///////////////////////////////////////

//subtract
TEST_CASE("- (subtract) test")
{
    Fraction a(1,4), b(1,2) ,c(-1,4);
    CHECK(a-b == c);
}

TEST_CASE("- (subtract) test")
{
    Fraction a(4,5), b(1,5) ,c(3,5);
    CHECK(a-b == c);
}

//////////////////////////////////////////
TEST_CASE("-  test")
{
    Fraction b(1,4),c(1,4), d(-1,4);
    float a = 0.50;
    CHECK(a-b == c);
    CHECK(b-a == d);
}
///////////////////////////////////////

// multiply
TEST_CASE("* (multiply) test")
{
    Fraction a(2,3), b(1,2) ,c(1,3);
    CHECK(a*b == c);
}

TEST_CASE("* (multiply) test")
{
    Fraction a(1,7), b(1,7) ,c(1,49);
    CHECK(a*b == c);
}

//////////////////////////////////////////
TEST_CASE("* test")
{
    Fraction b(1,2),c(1,4);
    float a = 0.50;
    CHECK(a*b == c);
    CHECK(b*a == c);
}
///////////////////////////////////////

//divide
TEST_CASE("/ (divide) test")
{
    Fraction a(1,5), b(1,2) ,c(2,5);
    CHECK(a/b == c);
}

TEST_CASE("/ (divide) test")
{
    Fraction a(1,2), b(1,2) ,c(1,1);
    CHECK(a/b == c);
}

//////////////////////////////////////////
TEST_CASE("/ test")
{
    Fraction b(1,2),c(1,1);
    float a = 0.50;
    CHECK(a/b == c);
    CHECK(b/a == c);
}
///////////////////////////////////////

//equality
TEST_CASE("== (equality) test")
{
    Fraction a(1,4), b(1,4);
    CHECK(a == b);
}

TEST_CASE("== (equality) test")
{
    Fraction a(1,2), b(1,4) ;
    CHECK_FALSE(a == b);
}

//////////////////////////////////////////
TEST_CASE("== test")
{
    Fraction b(1,2);
    float a = 0.50;
    CHECK(a == b);
    CHECK(b == a);
}
///////////////////////////////////////

// <
TEST_CASE("< test")
{
    Fraction a(-1,2), b(1,2);
    CHECK(a<b);
}

TEST_CASE("< test")
{
    Fraction a(1,2), b(-1,2);
    CHECK_FALSE(a<b);
}

//////////////////////////////////////////
TEST_CASE("< test")
{
    Fraction b(2,2);
    float a = 0.50;
    CHECK(a < b);
    CHECK_FALSE(b < a);
}
///////////////////////////////////////

// >
TEST_CASE("> test")
{
    Fraction a(1,2), b(1,3);
    CHECK(a>b);
}

TEST_CASE("> test")
{
    Fraction a(1,2), b(1,2);
    CHECK_FALSE(a>b);
}

//////////////////////////////////////////
TEST_CASE("> test")
{
    Fraction b(1,2);
    float a = 1.0;
    CHECK(a > b);
    CHECK_FALSE(b > a);
}
//////////////////////////////////////////

// >=
TEST_CASE(">= test")
{
    Fraction a(2,5), b(2,5);
    CHECK(a>=b);
}

TEST_CASE(">= test")
{
    Fraction a(3,7), b(2,7);
    CHECK(a>=b);
}

//////////////////////////////////////////
TEST_CASE(">= test")
{
    Fraction b(1,2);
    float a = 1.50;
    CHECK(a >= b);
    CHECK(b >= a);
}
//////////////////////////////////////////


// <=
TEST_CASE("<= test")
{
    Fraction a(-4,7), b(-4,7);
    CHECK(a<=b);
}

TEST_CASE("<= test")
{
    Fraction a(-3,7), b(5,7);
    CHECK(a<=b);
}
//////////////////////////////////////////
TEST_CASE("<= test")
{
    Fraction b(2,2);
    float a = 1.0;
    CHECK(a <= b);
    CHECK(b <= a);
}
///////////////////////////////////////

 //  prefix
TEST_CASE("++ test")
{
    Fraction a(1,2), b(3,2);
    CHECK(++a == b);
}

TEST_CASE("-- test")
{
    Fraction a(1,2), b(-1,2);
    CHECK(--a == b);
}

 // postfix
TEST_CASE("++ test")
{
    Fraction a(1,2), b(1,2);
    CHECK(a++ == b);
}

TEST_CASE("-- test")
{
    Fraction a(1,2), b(1,2);
    CHECK(a-- == b);
}

//   <<
TEST_CASE("<< test")
{
    Fraction a(3,4);
    CHECK(a.get_numnumerator() == 3);
    CHECK(a.get_denominator() == 4);

}













