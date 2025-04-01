#include "LatePatients.h"
#include<iostream>
#include"Patients.h"
#include"priQueue.h"
using namespace std;
void LatePatients::AddPatient(Patients p)
{
	int pri=p.getPT() + p.penaltytime();
	LATE.enqueue(p, -pri);

}

void LatePatients::NewList(int currenttimestep)
{ 
	Patients p;
	int c = p.getVT() + p.penaltytime();
	int pri =p.getPT() + p.penaltytime();

	if (currenttimestep <= c)
	{
		return;
	}
	if(!LATE.isEmpty())
	{ 
		Patients P;
		LATE.dequeue(P,pri);
	}
}

