#pragma once
#include<iostream>
#include<string>
#include"LinkedQueue.h"
using namespace std;
class Patients
{
private:
	int PID;
	int PT;
	int VT;
	string status;
	string patienttype;
	LinkedQueue<string>requiredtreatment;
	int duration[3];
	int treatmentcount;

public:
	void setPID(int id);
	void setPT(int appointementtime);
	void setVT(int arrivaltime);
	void setstatus(string s);
	void setpatienttype(string t);
	void AddTreatment(string &t, int d);
	int getPID();
	int getPT();
	int getVT();
	string getstatus();
	string getpatienttype();


};
	

