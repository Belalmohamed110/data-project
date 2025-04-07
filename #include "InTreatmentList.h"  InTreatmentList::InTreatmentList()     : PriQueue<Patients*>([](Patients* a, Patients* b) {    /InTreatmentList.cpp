#include "InTreatmentList.h"

InTreatmentList::InTreatmentList()
    : PriQueue<Patients*>([](Patients* a, Patients* b) {
   // prioritize earlier finish times
    return a->getCurrentTreatment()->getFinishTime() >
        b->getCurrentTreatment()->getFinishTime();
        }) 
