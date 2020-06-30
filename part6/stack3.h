/*
 * Header file for StackOfChars.
 *
 * Points of discussion: copy constructor and overloaded assignment operator.
 *
 * Author: Drue Coles
 */

#ifndef STACK3_H_INCLUDED
#define STACK3_H_INCLUDED

namespace stack3 {
    class StackOfChars {
    public:
        StackOfChars(int); // constructs empty stack of given max capacity
        StackOfChars(StackOfChars&); // copy constructor
        StackOfChars& operator=(const StackOfChars&);
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