/*
 * Implementation file for StackOfChars.
 *
 * Points of discussion: copy constructor and overloaded assignment operator.
 *
 * Author: Drue Coles
 */

#include <cassert>
#include "stack3.h"
using namespace stack3;

StackOfChars::StackOfChars(int n) {
   size = n;
   ptr = new char[size];
   top = 0;
}

StackOfChars::StackOfChars(StackOfChars& s) {
   ptr = new char[s.size];
   for (int i = 0; i < s.size; i++)
      ptr[i] = s.ptr[i];
   size = s.size;
   top = s.top;
}

StackOfChars& StackOfChars::operator=(const StackOfChars& s) {
   if (this == &s) // guard against self-assignment
      return *this;

   delete []ptr;
   ptr = new char[s.size];
   for (int i = 0; i < s.size; i++)
      ptr[i] = s.ptr[i];
   size = s.size;
   top = s.top;
   return *this;
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