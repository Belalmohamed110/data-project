#pragma once
#include "LinkedQueue.h"
#include "Patients.h"

//Electro Therapy
class E_WaitingList : public LinkedQueue<Patients*>
{

public:
	bool enqueue(Patients* p);

};

