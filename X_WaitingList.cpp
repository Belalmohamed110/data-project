#include "X_WaitingList.h"
#include"LinkedQueue.h"
#include"Patients.h"


// Ordered insertion by adjustedPT (same as E_WaitList)

bool X_WaitingList::enqueue(Patients* p) {
   
    if (isEmpty()) {
        return LinkedQueue<Patients*>::enqueue(p);
    }

    LinkedQueue<Patients*> tempQueue;
    bool inserted = false;

    while (!isEmpty()) {
        Patients* existingPatient;
        LinkedQueue<Patients*>::dequeue(existingPatient);

        if (!inserted && p->getAdjustedPT() < existingPatient->getAdjustedPT()) {
            tempQueue.enqueue(p);
            inserted = true;
        }
        tempQueue.enqueue(existingPatient);
    }

    if (!inserted) {
        tempQueue.enqueue(p);
    }

    while (!tempQueue.isEmpty()) {
        Patients* patient;
        tempQueue.dequeue(patient);
        LinkedQueue<Patients*>::enqueue(patient);
    }

    return true;
}

// Remove a patient at a specific index
Patients* X_WaitingList::removePatientAtIndex(int index) {
    if (index < 0 || index >= getcount()) return nullptr;

    LinkedQueue<Patients*> tempQueue;
    Patients* removedPatient = nullptr;
    int currentIndex = 0;

    while (!isEmpty()) {
        Patients* p;
        LinkedQueue<Patients*>::dequeue(p);

        if (currentIndex == index) {
            removedPatient = p;
        }
        else {
            tempQueue.enqueue(p);
        }
        currentIndex++;
    }

    while (!tempQueue.isEmpty()) {
        Patients* p;
        tempQueue.dequeue(p);
        LinkedQueue<Patients*>::enqueue(p);
    }

    return removedPatient;
}
