#pragma once
#include "LinkedQueue.h"
#include "Patients.h"

class X_WaitingList : public LinkedQueue<Patients*> {
public:
    bool enqueue(Patients* p);

    Patients* removePatientAtIndex(int index);
};
