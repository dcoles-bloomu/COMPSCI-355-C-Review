/*
 * Implementation file for the Rational class.
 *
 * Points of discussion: operator overloading, friend functions, default
 * arguments.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cassert>
#include "rational.h"
using namespace std;

Rational::Rational(int num, int den) {
   // The greatest common divisor of the numerator and
   // denominator will be factored out so that each rational
   // number has a unique representation.
   int div = gcd(num, den);

   // It is convenient to store the denominator as a positive
   // integer, so if needed we can take the additive inverse of
   // both numerator and denominator.
   if (den < 0) {
       this->num = -num / div;
       this->den = -den / div;
   } else {
       this->num = num / div;
       this->den = den / div;
   }
}

int Rational::gcd(int x, int y) { // Euclidean algorithm
    if (x < 0) {
        return gcd(-x, y);
    }
    if (x < y) {
        return gcd(y, x);
    }
    return y == 0 ? x : gcd(y, x % y);
}

Rational& Rational::operator+=(Rational& r) {
   *this = *this + r;
   return *this;
}

Rational& Rational::operator-=(Rational& r) {
   *this = *this - r;
   return *this;
}

Rational& Rational::operator*=(Rational& r) {
   *this = *this * r;
   return *this;
}

Rational& Rational::operator/=(Rational& r) {
   *this = *this / r;
   return *this;
}

ostream& operator<<(ostream& out, const Rational& r) {
   if (r.num == 0) {
      out << 0;
   }
   else if (r.den == 1) {
      out << r.num;
   }
   else out << r.num << "/" << r.den;
   return out;
}

bool operator==(const Rational& r, const Rational& s) {
   return r.num == s.num && r.den == s.den;
}

bool operator!=(const Rational& r, const Rational& s) {
   return r.num != s.num || r.den != s.den;
}

bool operator<(const Rational& r, const Rational& s) {
   return (r.num * s.den < s.num * r.den);
}

bool operator>(const Rational& r, const Rational& s) {
   return (r.num * s.den > s.num * r.den);
}

bool operator<=(const Rational& r, const Rational& s) {
   return (r.num * s.den <= s.num * r.den);
}

bool operator>=(const Rational& r, const Rational& s) {
   return (r.num * s.den >= s.num * r.den);
}

Rational operator+(const Rational& r, const Rational& s) {
    int x = r.num * s.den + s.num * r.den;
    int y = r.den * s.den;
    return Rational(x, y);
}

Rational operator-(const Rational& r, const Rational& s) {
   int x = r.num * s.den - s.num * r.den;
   int y = r.den * s.den;
   return Rational(x, y);
}

Rational operator*(const Rational& r, const Rational& s) {
   return Rational(r.num * s.num, r.den * s.den);
}

Rational operator/(const Rational& r, const Rational& s) {
   Rational zero(0);
   assert (s != zero);
   return Rational(r.num * s.den, r.den * s.num);
}