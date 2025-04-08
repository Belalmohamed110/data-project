#pragma once
#include "priNode.h"
#include <iostream>
using namespace std;

//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
private:
    priNode<T>* head;
    int count;  // Counter for number of elements

public:
    priQueue() : head(nullptr), count(0) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {
            newNode->setNext(head);
            head = newNode;
        }
        else {
            priNode<T>* current = head;        
            while (current->getNext() && priority <= current->getNext()->getPri()) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);        
        }
        count++;  // Increment count after successful enqueue
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;  // Decrement count after successful dequeue
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // Get the number of elements in the priority queue
    int getCount() const {
        return count;
    }

    // Print the priority queue contents
    void print() const {
        if (!isEmpty()) {
            priNode<T>* current = head;
            while (current != nullptr) {
                int pri;
                T item = current->getItem(pri);
                cout << item;
                if (current->getNext() != nullptr)
                    cout << ", ";
                current = current->getNext();
            }
            cout << endl;
        }
    }
};
