#pragma once
#include "LinkedQueue.h"
#include "Patients.h"

class X_WaitList : public LinkedQueue<Patients*> {
public:
    bool enqueue(Patients* p); T
    Patients* removePatientAtIndex(int index);
};
