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
void EarlyPatients::reschedule(int newpt,Patients*p)
{
	
	if (!p || newpt <= p->getPT())
	{
		return;
	}
	p->setPT(newpt);
	priQueue<Patients*> NEW;
	Patients* N = nullptr;
	int pri = -p->getPT();
	if (!ERLY.isEmpty())
	{
		ERLY.dequeue(N, pri);
		if (N != p)
		{
			NEW.enqueue(N, pri);
		}
	}
	if (!NEW.isEmpty())
	{
		NEW.dequeue(N, pri);
		ERLY.enqueue(N, pri);
	}
	ERLY.enqueue(N, -p->getPT());
}

