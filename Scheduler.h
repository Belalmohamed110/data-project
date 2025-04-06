#pragma once
#include <iostream>
#include <fstream>
#include"Patients.h"
#include"Resources.h"
#include "LatePatients.h"
#include"EarlyPatients.h"
#include"priQueue.h"

using namespace std;
class Scheduler
{
	int current_time_step=0 ;
	priQueue<EarlyPatients>early;
	priQueue<LatePatients>late;
public:
	Scheduler();
	void LoadPatientstoAll(string filename);
	void addtowaitlist(Patients & p);
	//void checkAllpatientslist();
	void randomwaiting();
	/*void settime();
	int gettime();*/
	//void simulation();
};

