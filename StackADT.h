//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file StackADT.h */

#ifndef STACK_ADT_
#define STACK_ADT_

#include <iostream>
using namespace std;

template<typename T>
class StackADT
{
protected:
    int count;  // Counter for number of elements in stack

public:
    StackADT() : count(0) {}  // Constructor initializes count to 0
    virtual ~StackADT() {}    // Virtual destructor

    /** Checks whether this stack is empty.
     @return  True if the stack is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the top of this stack.
     @post  If the operation was successful, newEntry is at the top of the stack.
     @param newEntry  The object to be added as a new entry.
     @return  True if the addition is successful or false if not. */
    virtual bool push(const T& newEntry) = 0;

    /** Copies the top item of the stack to the passed parameter and removes it from stack
     @post  If the operation was successful, the top item of the stack
        has been copied to TopEntry parameter.
     @return  True if the removal is successful or false if not. */
    virtual bool pop(T& TopEntry) = 0;

    /** Copies the top item of the stack to the passed parameter without removing it from stack
     @pre  The stack is not empty.
     @post  If the operation was successful, the top item of the stack
        has been copied to TopEntry parameter.
     @return  True if stack is not empty or false if not. */
    virtual bool peek(T& TopEntry) const = 0;

    /** Print the stack contents */
    virtual void print() const = 0;

    /** Returns the number of elements in the stack */
    int getCount() const { 
        return count; 
    }
};
#endif

