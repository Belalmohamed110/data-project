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
	class Treatment
	{
	public:
		string name;
		int duration;
		Treatment(string n,int d)
		{
			name = n;
			duration = d;
		}
	};
	LinkedQueue<Treatment>requiredtreatment;
	int treatmentcount=0;

public:
	void setPID(int id);
	void setPT(int appointementtime);
	void setVT(int arrivaltime);
	void setstatus(string s);
	void setpatienttype(string t);
	void settreatmentcount(int c);
	void AddTreatment(string n, int d);
	int getPID();
    int getPT();
	int getVT();
	string getstatus();
	string getpatienttype();
	int gettreatmentcount();
	int penaltytime();
	friend ostream& operator<<(ostream& out, const Patients* patient);
	


};
	
