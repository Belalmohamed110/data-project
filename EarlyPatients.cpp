#include "EarlyPatients.h"
#include<iostream>
#include"PriQueue.h"
#include"Patients.h"
using namespace std;

void EarlyPatients::AddPatients(Patients* p)
{
	if(p==NULL)
	{
		return;
	}
	int pri =p->getPT();
	ERLY.enqueue(p, -pri);

}

void EarlyPatients::newlist(int currenttimestep)
{
	if (ERLY.isEmpty())
	{
		return;
	}
	Patients* p;
	int pri=p->getPT();
	if (!ERLY.peek(p, pri))
	{
		return;
	}
	if (currenttimestep < pri)
	{
		return;
	}
	ERLY.dequeue(p, pri);
}
