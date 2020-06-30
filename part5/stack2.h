/*
 * Header file for StackOfChars.
 *
 * Points of discussion: separate compilation and namespaces.
 *
 * Author: Drue Coles
 */

#ifndef STACK2_H_INCLUDED
#define STACK2_H_INCLUDED

namespace stack2 {
    // a bounded stack of characters
    class StackOfChars {
    public:
        StackOfChars(int); // constructs empty stack of given max capacity
        ~StackOfChars(); // releases dynamically allocated stack space
        void push(char); // pushes a character onto stack
        char pop(); // pops a character off stack and returns it
        bool is_empty() const;
        bool is_full() const;
    private:
       char* ptr;
       int top; // index of next available location
       int size; // maximum capacity of stack
    };
}
#endif