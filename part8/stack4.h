/*
 * Header file for Stack<T>.
 *
 * Points of discussion: class templates, template classes, the impossibility 
 * of separate compilation with template classes.
 *
 * Author: Drue Coles
 */

#ifndef STACK4_H_INCLUDED
#define STACK4_H_INCLUDED

template <typename T>
class Stack {
public:
   Stack(int = 10);
   Stack(Stack&);
   Stack& operator=(const Stack&);
   ~Stack();
   void push(T);
   T pop();
   bool is_empty() const;
   bool is_full() const;
private:
   T* ptr;
   int top;
   int size;
};
#endif