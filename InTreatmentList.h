#pragma once
#include "PriQueue.h"
#include "Patients.h"

class InTreatmentList : public PriQueue<Patient*> {
public:
    InTreatmentList();
};


