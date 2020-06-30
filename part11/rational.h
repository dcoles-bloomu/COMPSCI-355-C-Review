/*
 * Header file for a class representing rational numbers.
 *
 * Points of discussion: operator overloading, friend functions, default
 * arguments.
 *
 * Author: Drue Coles
 */

#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
using namespace std;

class Rational {

   // Displays the number in standard format, i.e., with a slash
   // between numerator and denominator, as in 2/3 or -23/17.
   friend ostream& operator<<(ostream&, const Rational&);

   // friend functions for arithmetic operations
   friend Rational operator+(const Rational&, const Rational&);
   friend Rational operator-(const Rational&, const Rational&);
   friend Rational operator*(const Rational&, const Rational&);
   friend Rational operator/(const Rational&, const Rational&);

   // friend functions for relational operations
   friend bool operator==(const Rational&, const Rational&);
   friend bool operator!=(const Rational&, const Rational&);
   friend bool operator<(const Rational&, const Rational&);
   friend bool operator<=(const Rational&, const Rational&);
   friend bool operator>(const Rational&, const Rational&);
   friend bool operator>=(const Rational&, const Rational&); 
   
public:
   // Rational x(5);   <->  Rational x(5, 1);     
   // Rational y;      <->  Rational y(0, 1);
   Rational(int=0, int=1);

   // modified assignment operators
   Rational& operator+=(Rational&);
   Rational& operator-=(Rational&);
   Rational& operator*=(Rational&);
   Rational& operator/=(Rational&);

private:
   int num; // numerator
   int den; // denominator

   // greatest common divisor calculated in the constructor
   // to reduce numerator and denominator to lowest terms.
   int gcd(int, int);

};
#endif