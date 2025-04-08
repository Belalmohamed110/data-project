#include "U_WaitingList.h"
bool u_WaitingList::enqueue(Patients* p) {
    if (isEmpty()) {
             return LinkedQueue<Patients*>::enqueue(p);
    }

       LinkedQueue<Patients*> tempQueue;
    bool inserted = false;

    while (!isEmpty()) {
        Patients* existingPatient;
        if (LinkedQueue<Patients*>::dequeue(existingPatient)) { // Use base class dequeue
            // Compare adjustedPT to find insertion point
            if (!inserted && p->getAdjustedPT() < existingPatient->getAdjustedPT()) {
                tempQueue.enqueue(p); // Insert new patient first
                inserted = true;
            }
            tempQueue.enqueue(existingPatient); // Reinsert existing patient
        }
    }

    // If the new patient wasn't inserted, add it at the end
    if (!inserted) {
        tempQueue.enqueue(p);
    }

    // Rebuild the original queue from the tempQueue
    while (!tempQueue.isEmpty()) {
        Patients* patient;
        if (tempQueue.dequeue(patient)) {
            LinkedQueue<Patients*>::enqueue(patient); // Use base class enqueue
        }
    }

    return true;
}
