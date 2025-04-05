    void ClearConsole() {
        Sleep(5000);  // Wait for 5 seconds (Windows only)
        system("cls"); // Clear console (Windows only)
    }

    void printPatients(Patients* patientList[], int size) {
        for (int i = 0; i < size; i++) {
            cout << *patientList[i] << endl;  // Assuming Patients has overloaded operator<<
        }
    }

    void printResource(const Resource& res) {
        cout << res << endl;
    }

    // Function to print any stack passed to it
    template <typename T>
    void printStack(const StackADT<T>& stack) {
        stack.print();  // Calls the appropriate print function from the specific stack
    }

    // Function to print stack count
    template <typename T>
    void printStackCount(const StackADT<T>& stack) {
        cout << "Number of elements in stack: " << stack.getCount() << endl;
    }
};

