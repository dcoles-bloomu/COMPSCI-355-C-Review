/*
 * Implementation file for StackOfChars.
 *
 * Points of discussion: separate compilation and namespaces.
 *
 * Author: Drue Coles
 */

#include <cassert>
#include "stack2.h"
using namespace stack2;

StackOfChars::StackOfChars(int n) {
   size = n;
   ptr = new char[size];
   top = 0;
}

StackOfChars::~StackOfChars()	{
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