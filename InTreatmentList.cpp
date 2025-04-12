#include "InTreatmentList.h"
#include"Patients.h"
#include"priNode.h"
#include"priQueue.h"

InTreatmentList::InTreatmentList()
    : priQueue<Patients*> ( [](Patients* a, Patients* b)
        {
   // prioritize earlier finish times
    return a-> getCurrentTreatment() -> getEndtime() >  b-> getCurrentTreatment()-> getEndtime();
 
     }) 
{ }
