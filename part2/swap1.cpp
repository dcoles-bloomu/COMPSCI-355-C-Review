/*
 * Outputs two random integers before and after swapping them. This program
 * deliberately fails in order to illustrate the difference between value
 * and reference semantics.
 *
 * Point of discussion: passing arguments by value.
 *
 * Execution snapshot:
 *
 *      Before: 437 896
 *       After: 437 896
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int, int);

int main () {
    srand(time(0));
    int a = rand() % 1000;
    int b = rand() % 1000;
    cout << "Before: " << a << " " << b << endl;
    swap(a, b);
    cout << " After: " << a << " " << b << endl;
    return 0;
}

void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}