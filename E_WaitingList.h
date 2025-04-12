#pragma once
#include "LinkedQueue.h"
#include "Patients.h"

//Electro Therapy // clactretement latency -> calc all treatement time
// use pointers queue - protected.
class E_WaitingList : public LinkedQueue<Patients*>
{

public:
	bool enqueue(Patients* p);

};

