/*
 * Prompts user for a line of text and displays it backwards.
 *
 * Points of discussion: separate compilation and namespaces
 *
 * Execution snapshot:
 *
 *      Enter a line of text.
 *      > The circle is now complete.
 *      > .etelpmoc won si elcric ehT
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cctype>
#include "stack2.h"

using namespace std;

int main() {
   const int MAX_INPUT_LEN = 100;
   stack2::StackOfChars stack(MAX_INPUT_LEN);

   cout << "Enter a line of text.\n> ";
   char c;
   cin.get(c);

   // push input characters onto the stack
   while (c != '\n') {
      stack.push(c);
      cin.get(c);
   }

   // pop characters off the stack and print them
   cout << "> ";
   while (!stack.is_empty()) {
      cout << stack.pop();
   }
   cout << endl;
   return 0;
}