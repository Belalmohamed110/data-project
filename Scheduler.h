#include<iostream>
#include"Patients.h"
#include"Resources.h"
#include "LatePatients.h"
#include"AllPatients.h"
#include"EarlyPatients.h"
#include"E_WaitingList.h"
#include <fstream>
#include "U_WaitingList.h"
#include"X_WaitingList.h"
#include"LinkedQueue.h"
#include"Node.h"
#include"priNode.h"
#include"priQueue.h"
#include"StackADT.h"
#include "ArrayStack.h"
#include"QueueADT.h"
#include<sstream>


using namespace std;
class Scheduler
{



public:
	int current_time_step = 0;
	EarlyPatients ERLY;
	priQueue<Patients*>early;
	priQueue<Patients*>late;
	LinkedQueue<Patients*> ALLpatients;
	LinkedQueue<Patients*> RandomWaiting;
	LinkedQueue<Patients*> InTreatment;
	LinkedQueue<Patients*> E_Waiting;
	LinkedQueue<Patients*> U_Waiting;
	LinkedQueue<Patients*> X_Waiting;
	LinkedQueue<Patients*> finished;
	Scheduler();
	void LoadPatientstoAll(string filename);
	void movefromALL(Patients * p);
	//void checkAllpatientslist();
	void simulation();
	void reschedule(int newpt,Patients*p1);
	//void simulation(int max_time_steps);
	/*void settime();
	int gettime();*/
	//void simulation();
};

