//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackADT.h"
#include "car.h"

//Unless spesificed by the stack user, the default size is 100
template<typename T>
class ArrayStack : public StackADT<T>
{
private:
	static const int MAX_SIZE = 100;  // Maximum size of the stack
	T items[MAX_SIZE];		// Array of stack items
	int top;                   // Index to top of stack
	
public:

	/** Constructor */
	ArrayStack()
	{
		top = -1;
		this->count = 0;  // Initialize count from base class
	}  // end default constructor

	/** Check if stack is empty */
	bool isEmpty() const override
	{
		return top < 0;	
	}  // end isEmpty

	/** Add new item to top of stack */
	bool push(const T& newEntry) override
	{
		if (top < MAX_SIZE - 1) {  // Check if stack is not full
			items[++top] = newEntry;   
			this->count++;  // Increment count (inherited from StackADT)
			return true;
		}
		return false;  // Stack is full
	}  // end push

	/** Remove top item from stack */
	bool pop(T& TopEntry) override
	{
		if (isEmpty()) return false;
		
		TopEntry = items[top];		 
		top--;
		this->count--;  // Decrement count (inherited from StackADT)
		return true;
	}  // end pop
	
	/** Look at top item without removing it */
	bool peek(T& TopEntry) const override
	{
		if (isEmpty()) return false;
		
		TopEntry = items[top];		 
		return true;
	}  // end peek

	int GetCountStack() const {
		return this->count;
	}

	/** Print all items in the stack */
	void printStack() const override {
		if (!isEmpty()) {
			for (int i = top; i >= 0; i--) {
				cout << items[i];
				if (i > 0)
					cout << ", ";
			}
			cout << endl;
		}
	}
}; // end ArrayStack

#endif

