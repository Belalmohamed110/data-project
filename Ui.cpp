   #include "Ui.h"
#include "StackADT.h"
#include "QueueADT.h"
#include "Patients.h"
#include "Resources.h"
#include <iostream>
using namespace std;

UI::UI() {
    // Constructor implementation if needed
}

void UI::ClearConsole() {
    system("cls");  // For Windows
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

void UI::printPatients(Patients* patientList[], int size) {
    cout << "\n=== Patient List ===" << endl;
    for (int i = 0; i < size; i++) {
        if (patientList[i] != nullptr) {
            cout << *patientList[i] << endl;
        }
    }
}

void UI::printResource(const Resource& res) {
    cout << "\n=== Resource Information ===" << endl;
    // Add your resource printing logic here
    // You might want to add getter methods in Resource class to access ID and type
}
