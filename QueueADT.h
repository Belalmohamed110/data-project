//     This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file QueueADT.h */
#ifndef QUEUE_ADT_
#define QUEUE_ADT_

#include <iostream>
using namespace std;

template<typename T>
class QueueADT {
protected:
    int count;  // Counter for number of elements in queue

public:
    QueueADT() {
        count = 0;
    }

    virtual ~QueueADT() { }

    /** Checks whether this queue is empty.
     @return  True if the queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the back of this queue.
     @post  If the operation was successful, newEntry is at the back of the queue.
     @param newEntry  The object to be added as a new entry.
     @return  True if the addition is successful or false if not. */
    virtual bool enqueue(const T& newEntry) = 0;

    /** Copies the front item of the queue to the passed parameter and removes it from queue
     @post  If the operation was successful, the front item of the queue
        has been copied to FrontEntry parameter.
     @return  True if the removal is successful or false if not. */
    virtual bool dequeue(T& FrontEntry) = 0;

    /** Copies the front item of the queue to the passed parameter without removing it from queue
     @pre  The queue is not empty.
     @post  If the operation was successful, the front item of the queue
        has been copied to FrontEntry parameter.
     @return  True if queue is not empty or false if not. */
    virtual bool peek(T& FrontEntry) const = 0;

    /** Print the queue contents */
    void print() const {
        cout << "\n=== Queue Contents ===" << endl;
        cout << "Number of elements in queue: " << count << endl;
    }

    /** Returns the number of elements in the queue */
    int getCount() const { 
        return count; 
    }
};

#endif
