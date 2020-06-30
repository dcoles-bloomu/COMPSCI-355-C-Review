/*
 * Exercise in the use of reference vs. value arguments.
 * Look at the code and predict the output. Then run it
 * to verify your understanding.
 *
 * Author: Drue Coles
 */

 #include <iostream>
 using namespace std;

 void f(int, int&);

 int main() {
    int x = 3;
    int y = 5;
    f(x, y);
    cout << x << " " << y << endl;

    // Also try f(y, x), f(x + y, y).
    // What happens with f(y, x + y)?

    return 0;
 }

 void f(int x, int& y) {
    x *= 2;
    y += x;
 }