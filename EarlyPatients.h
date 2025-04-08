#pragma once
#include<iostream>
#include"PriQueue.h"
#include"Patients.h"
using namespace std;
class EarlyPatients
{
private:
	priQueue<Patients*>ERLY;
	string ListName = "ERLY";

public:
	void AddPatients(Patients* p);
	void newlist(int currenttimestep);
        void reschedule(int newpt,Patients *p)

};


