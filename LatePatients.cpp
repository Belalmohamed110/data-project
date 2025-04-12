#include "LatePatients.h"
#include<iostream>
#include"Patients.h"
#include"priQueue.h"
using namespace std;

// mmken mn priqueu 3ady 


void LatePatients::AddPatient(Patients*p)
{
	int pri=p->getPT() + p->penaltytime();
	LATE.enqueue(p, -pri);

}

void LatePatients::NewList(int currenttimestep)
{ 
	if (LATE.isEmpty())
	{
	    return ;
	}
	Patients *p;
	int pri = p->getPT() + p->penaltytime();
	if(!LATE.peek(p,pri))
	{
		return ;
	}
	int c = p->getVT() + p->penaltytime();
	
    if (currenttimestep <= c)
	{
		return;
	}
	else
	{ 
		LATE.dequeue(p,pri);
		
	}
}

