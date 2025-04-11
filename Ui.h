#pragma once
#include <windows.h>  // For Sleep() and system()
#include <iostream>
#include "StackADT.h"
#include "QueueADT.h"
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patients.h"
#include "Resources.h"
using namespace std;

class UI {
public:
    UI();  // Constructor declaration
    
    void ClearConsole();
    void printPatients(Patients* patientList[], int size);
    void printResource(const Resources & res);
    void printSectionHeader(const string& title);
    
    // Template functions must stay in header
    template <typename T>
    void printStack(const StackADT<T>& stack) {
        stack.printStack();
    }
    
    template <typename T>
    void printStackCount(const StackADT<T>& stack) {
        cout << stack.GetCountStack();
    }
    
    template <typename T>
    void printQueue(const LinkedQueue<T>& queue) {
        queue.print();
    }
    
    template <typename T>
    void printQueueCount(const QueueADT<T>& queue) {
        cout << queue.getCount();
    }

    template <typename T>
    void printPriQueue(const priQueue<T>& pqueue) {
        pqueue.print();
    }
    
    template <typename T>
    void printPriQueueCount(const priQueue<T>& pqueue) {
        cout << pqueue.getCount();
    }

    // Print the entire system status
    void printSystemStatus(
        int currentTimestep,
        const LinkedQueue<Patients>& allList,
        const LinkedQueue<Patients>& eTherapyList,
        const LinkedQueue<Patients>& uTherapyList,
        const LinkedQueue<Patients>& xTherapyList,
        const LinkedQueue<Patients>& earlyList,
        const LinkedQueue<Patients>& lateList,
        const LinkedQueue<Resources>& eDevices,
        const LinkedQueue<Resources>& uDevices,
        const LinkedQueue<Resources>& xRooms,
        const LinkedQueue<Patients>& inTreatmentList,
        const LinkedQueue<Patients>& finishedList
    );
    template<typename T>
    void printPriQueue(const priQueue<T>& pqueue);
};
