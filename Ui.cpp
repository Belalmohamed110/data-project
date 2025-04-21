#include "Ui.h"
#include "StackADT.h"
#include<iostream>
#include"Patients.h"
#include"Resources.h"
#include "Scheduler.h"
#include "LatePatients.h"
#include"AllPatients.h"
#include"EarlyPatients.h"
#include"E_WaitingList.h"
#include <fstream>
#include "U_WaitingList.h"
#include"X_WaitingList.h"
#include"LinkedQueue.h"
#include"Node.h"
#include"priNode.h"
#include"priQueue.h"
#include "ArrayStack.h"
#include"QueueADT.h"
#include<sstream>
using namespace std;

UI::UI() {
    // Constructor implementation if needed
}

void UI::ClearConsole() {
    system("cls");  // For Windows
}

void UI::printSectionHeader(const string& title) {
    cout << string(20, '=') << " " << title << " " << string(20, '=') << endl;
}

template <typename T>
void UI::printStack(const StackADT<T>& stack) {
    cout << "\n=== Stack Contents ===" << endl;
    stack.printStack();  // This will use the printStack function from StackADT
}

template <typename T>
void UI::printStackCount(const StackADT<T>& stack) {
    cout << "\n=== Stack Statistics ===" << endl;
    cout << "Number of elements in stack: " << stack.GetCountStack() << endl;
}

template <typename T>
void UI::printQueueCount(const QueueADT<T>& queue) {
    cout << "\n=== Queue Statistics ===" << endl;
    cout << "Number of elements in queue: " << queue.getCount() << endl;
}

template <typename T>
void UI::printPriQueue (const priQueue<T>& pqueue) {
    pqueue.print();  // Using the print method from priQueue
}

template <typename T>
void UI::printPriQueueCount(const priQueue<T>& pqueue) {
    cout << "\n=== Priority Queue Statistics ===" << endl;
    cout << "Number of elements in priority queue: " << pqueue.getCount() << endl;
}

void UI::printPatients(Patients* patientList[], int size) {
    for (int i = 0; i < size; i++) {
        if (patientList[i] != nullptr) {
            cout << patientList[i] << endl;
        }
    }
}

void UI::printResource(const Resources& res) {
    res.print();
}

void UI::printSystemStatus() {
    ClearConsole();
    
    // Print current timestep
    cout << "Current Timestep: " << current_time_step << endl;
    
    // Print ALL List with dividing line
    printSectionHeader("ALL List"); 
    cout << ALLpatients << " patients remaining: ";
    printQueue(ALLpatients);
     
    // Print Waiting Lists
    printSectionHeader("Waiting Lists");
    cout << early.getCount() << " E-therapy patients: ";
    printQueue(early);
    cout << uTherapyList.getCount() << " U-therapy patients: ";
    printQueue(uTherapyList);
    cout << xTherapyList.getCount() << " X-therapy patients: ";
    printQueue(xTherapyList);
    
    // Print Early List
    printSectionHeader("Early List");
    cout << earlyList.getCount() << " patients: "; 
    printQueue(earlyList); 
     
    // Print Late List
    printSectionHeader("Late List"); 
    cout << lateList.getCount() << " patients: ";
    printQueue(lateList);
    
    // Print Available Resources
    printSectionHeader("Avail E-devices");
    cout << eDevices.getCount() << " Electro device: ";
    printQueue(eDevices);
    
    printSectionHeader("Avail U-devices");
    cout << uDevices.getCount() << " Ultra device: ";
    printQueue(uDevices);
    
    printSectionHeader("Avail Xrooms");
    cout << xRooms.getCount() << " rooms: ";
    printQueue(xRooms);
    
    // Print In-treatment List
    printSectionHeader("In-treatment List") ;
     cout << inTreatmentList.getCount() << " ==> ";
    printQueue(inTreatmentList);
    
    // Print Finished List
    printSectionHeader("Finished Patients");
    cout << finishedList.getCount() << " finished patients: ";
    cout << "(Recently finished are patients printed first)" << endl;
    printQueue(finishedList);
}
