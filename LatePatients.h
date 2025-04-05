#pragma once
#include<iostream>
#include"Patients.h"
#include"priQueue.h"
using namespace std;
class LatePatients
{
private:
	priQueue<Patients*>LATE;
	const string ListName = "LATE";
	
public:
	void AddPatient(Patients * p);
	void NewList(int currenttimestep );

};
