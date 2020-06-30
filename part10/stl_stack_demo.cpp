/*
 * Writes the uppercase letters of the alphabet forwards on one line and
 * backwards on the next.
 *
 * Point of discussion: STL containers
 *
 * Execution snapshot:
 *
 *      ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *      ZYXWVUTSRQPONMLKJIHGFEDCBA
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

int main () {
    // Print letters A-Z and push onto the stack.
    stack<char> letters;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << ch;
        letters.push(ch);
    }
    cout << endl;

    // Print and remove letters from the top until stack is empty.
    while (!letters.empty()) {
        cout << letters.top();
        letters.pop();
    }
    cout << endl;
    return 0;
}