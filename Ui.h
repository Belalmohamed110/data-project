pragma once
#include <windows.h>  // For Sleep() and system()
#include <iostream>
#include "StackADT.h"
#include "QueueADT.h"
#include "Patients.h"
#include "Resources.h"

class UI {
public:
    UI();  // Constructor declaration
    
    void ClearConsole();
    void printPatients(Patients* patientList[], int size);
    void printResource(const Resource& res);
    
    template <typename T>
    void printStack(const StackADT<T>& stack);
    
    template <typename T>
    void printStackCount(const StackADT<T>& stack);
    
    template <typename T>
    void printQueueCount(const QueueADT<T>& queue);
};
