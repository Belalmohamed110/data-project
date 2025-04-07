#pragma once
#include <iostream>
#include <fstream>
#include"Patients.h"
#include"Resources.h"
#include "LatePatients.h"
#include"EarlyPatients.h"
#include"priQueue.h"
#include"QueueADT.h"


using namespace std;
class Scheduler
{
	int current_time_step=0 ;
	priQueue<EarlyPatients>early;
	priQueue<LatePatients>late;
	LinkedQueue<Patients> ALLpatients;
	LinkedQueue<Patients> RandomWaiting;
	LinkedQueue<Patients> InTreatment;
	LinkedQueue<Patients> E_Waiting;
	LinkedQueue<Patients> U_Waiting;
	LinkedQueue<Patients> X_Waiting;

public:
	Scheduler();
	void LoadPatientstoAll(string filename);
	void movefromALL(Patients & p);
	//void checkAllpatientslist();
	void randomwaiting();
	void simulation(int max_time_steps);
	/*void settime();
	int gettime();*/
	//void simulation();
};

