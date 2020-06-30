/*
 * Outputs initial Fibonacci numbers followed by zeros.
 *
 * Points of discussion: STL containers and iterators.
 *
 * Execution snapshot:
 *
 *      0       1       1       2       3
 *      5       8      13      21      34
 *     55      89     144     233     377
 *    610     987    1597    2584    4181
 *   6765   10946   17711   28657   46368
 *      0       0       0       0       0
 *
 *      0       1       1       2       3
 *      5       8      13      21      34
 *     55      89     144     233     377
 *    610     987    1597    2584    4181
 *   6765   10946   17711   28657   46368
 *      0       0       0       0       0
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main () {
    // initialize a vector with some Fibonacci numbers
    vector<int> fib(25);
    fib[0] = 0; // v.operator[](0) = 0
    fib[1] = 1; // v.operator[](1) = 1
    for (size_t i = 2; i < fib.size(); i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // add some zeros to the end
    for (int i = 0; i < 5; i++) {
        fib.push_back(0);
    }

    // output contents
    const int NUMS_PER_LINE = 5;
    const int COL_WIDTH = 8;
    for (size_t i = 0; i < fib.size(); i++) {
      cout << setw(COL_WIDTH) << fib[i];
      if ((i + 1) % NUMS_PER_LINE == 0) {
        cout << endl;
      }
    }
    cout << endl;

    // traverse collection using an iterator
    vector<int>::iterator iter;
    int i = 0; // for counting numbers per line
    for (iter = fib.begin(); iter != fib.end(); ++iter) {
        if (i++ % NUMS_PER_LINE == 0) {
            cout << endl;
        }
        cout << setw(COL_WIDTH) << *iter;
    }
    cout << endl;
    return 0;
}