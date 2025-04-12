#pragma once
#include "PriQueue.h"
#include "Patients.h"

class InTreatmentList : public priQueue <Patients *> {
public:
    InTreatmentList();
};


