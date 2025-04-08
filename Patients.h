#pragma once
#include<iostream>
#include<string>
#include"LinkedQueue.h"
#include"treatment.h"

using namespace std;
class Patients
{
private:
	int PID;
	int PT;
	int VT;
	int adjustedPT;
	string status;
	string patienttype;
	
	LinkedQueue<treatment*> treatments;
	treatment* currentTreatment;
	int treatmentcount = 0;

public:
	Patients(int id, int appointmenttime, int arrivaltime, string s, string t);
	void setPID(int id);
	void setPT(int appointmenttime);
	void setVT(int arrivaltime);
	void setstatus(string s);
	void setpatienttype(string t);
	void settreatmentcount(int c);

	int getAdjustedPT();
	void AddTreatment(treatment* t);
	treatment* getNextTreatment();

	int getPID();
	int getPT();
	int getVT();
	string getstatus();
	string getpatienttype();
	int gettreatmentcount();
	int penaltytime();
	friend ostream& operator<<(ostream& out, const Patients* patient);

	treatment* getCurrentTreatment();


};

