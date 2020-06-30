/*
 * Prompts user for a line of text and displays it backwards.
 *
 * Points of discussion: destructors, assert macro, const methods, prefix vs.
 * postfix increment.
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
#include <cassert>
using namespace std;

// a bounded stack of characters
class StackOfChars {
public:
   StackOfChars(int);
   ~StackOfChars();
   void push(char);
   char pop();
   bool is_empty() const;
   bool is_full() const;
private:
   char* ptr;
   int top;
   int size;
};

StackOfChars::StackOfChars(int n) {
   size = n;
   ptr = new char[size];
   top = 0;
}

StackOfChars::~StackOfChars() {
   delete []ptr;
}

void StackOfChars::push(char c) {
   assert(!is_full());
   ptr[top++] = c;
}

char StackOfChars::pop() {
   assert(!is_empty());
   return ptr[--top];
}

bool StackOfChars::is_empty() const {
   return top == 0;
}

bool StackOfChars::is_full() const {
   return top == size;
}

int main() {
   const int MAX_INPUT_LEN = 100;
   StackOfChars stack(MAX_INPUT_LEN);

   cout << "Enter a line of text.\n> ";

   char c;
   cin.get(c);

   // push characters of input onto the stack
   while (c != '\n') {
      stack.push(c);
      cin.get(c);
   }

   // print backwards by popping off stack
   cout << "> ";
   while (!stack.is_empty()) {
      cout << stack.pop();
   }
   cout << endl;
   return 0;
}