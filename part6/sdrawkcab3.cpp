/*
 * Prompts user for a line of text and displays it backwards. This program
 * has a deliberate bug used to demonstrate why any class with pointer data
 * should provide a copy constructor and overloaded assignment operator.
 *
 * Points of discussion: copy constructors and overloaded assignment operators.
 *
 * Execution snapshot:
 *
 *      Enter a line of text.
 *      > The circle is now complete.
 *      > .etelpmoc won si elcric ehT
 *      > .etelpmoc won si el lh ª`
 *
 * Author: Drue Coles
 */

#include <iostream>
#include "stack2.h"

using namespace std;
using namespace stack2;

void pop_and_print(StackOfChars);

int main() {
   const int MAX_INPUT_LEN = 100;
   stack2::StackOfChars stack(MAX_INPUT_LEN);

   cout << "Enter a line of text.\n> ";
   char c;
   cin.get(c);

   // Push input characters onto the stack.
   while (c != '\n') {
      stack.push(c);
      cin.get(c);
   }

   pop_and_print(stack); // Local stack is passed by value.

   // Local stack not modified (?), so we can pop and print again.
   pop_and_print(stack); // GENERATES INVALID OUTPUT OR CRASHES
   return 0;
}

void pop_and_print(StackOfChars stack) {
    cout << "> ";
    while (!stack.is_empty()) {
        cout << stack.pop();
    }
    cout << endl;
}
