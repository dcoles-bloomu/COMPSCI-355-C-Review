/*
 * Header file for Stack<T>.
 *
 * Points of discussion: class templates, template classes, the impossibility 
 * of separate compilation with template classes.
 *
 * Author: Drue Coles
 */

#include <cassert>
#include "stack4.h"

template <typename T>
Stack<T>::Stack(int n) {
   size = n;
   ptr = new T[size];
   top = 0;
}

template <typename T>
Stack<T>::Stack(Stack<T>& s) {
   ptr = new T[s.size];
   for (int i = 0; i < s.size; i++)
      ptr[i] = s.ptr[i];
   size = s.size;
   top = s.top;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
   delete []ptr;
   ptr = new char[s.size];
   for (int i = 0; i < s.size; i++)
      ptr[i] = s.ptr[i];
   top = s.top;
   return *this;
}

template <typename T>
Stack<T>::~Stack() {
   delete []ptr;
}

template <typename T>
void Stack<T>::push(T c) {
   assert(!is_full());
   ptr[top++] = c;
}

template <typename T>
T Stack<T>::pop() {
   assert(!is_empty());
   return ptr[--top];
}

template <typename T>
bool Stack<T>::is_empty() const {
   return top == 0;
}

template <typename T>
bool Stack<T>::is_full() const {
   return top == size;
}