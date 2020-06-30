/*
 * Test program for Rational class. Prompts the user for two rational
 * numbers and outputs the results of several calculations involving
 * these numbers.
 *
 * Points of discussion: operator overloading and friend functions.
 *
 * Execution snapshot:
 *
 *      Enter two non-zero rational numbers (without slashes): 2 3 7 8
 *      2/3 is less than 7/8
 *      2/3 + 7/8 = 37/24
 *      2/3 - 7/8 = -5/24
 *      2/3 * 7/8 = 7/12
 *      2/3 / 7/8 = 16/21
 *      (2/3)^2 + (7/8)^2 = 697/576
 *
 * Author: Drue Coles
 */
#include <iostream>
#include "rational.h"

int main() {
    cout << "Enter two non-zero rational numbers (without slashes): ";
    int n1, d1, n2, d2;
    cin >> n1 >> d1 >> n2 >> d2;
    Rational r1(n1, d1);
    Rational r2(n2, d2);

    if (r1 < r2) {
        cout << r1 << " is less than " << r2 << endl;
    } else if (r1 > r2) {
        cout << r1 << " is smaller than " << r2 << endl;
    } else {
        cout << r1 << " equals " << r2 << endl;
    }

    Rational sum = r1 + r2;
    Rational difference = r1 - r2;
    Rational product = r1 * r2;
    Rational quotient = r1 / r2;
    Rational sumOfSquares = r1 * r1 + r2 * r2;
    
    cout << r1 << " + " << r2 << " = " << sum << endl;
    cout << r1 << " - " << r2 << " = " << difference << endl;
    cout << r1 << " * " << r2 << " = " << product << endl;
    cout << r1 << " / " << r2 << " = " << quotient << endl;
    cout << "(" << r1 << ")^2 + (" << r2 << ")^2 = " << sumOfSquares << endl;

    return 0;
}