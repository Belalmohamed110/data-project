#pragma once
#include <windows.h>  // For Sleep() and system()
#include <iostream>
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
};
