#pragma once
#include "LinkedQueue.h"
#include "Patients.h"

// Ultrasound Therapy
class U_WaitingList : public LinkedQueue<Patients*>
{

public:
	bool enqueue(Patients* p);

};
