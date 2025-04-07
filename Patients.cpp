#include "Patients.h"
#include<iostream>
#include <string>
using namespace std;


Patients::Patients(int id, int appointmenttime, int arrivaltime, string& s, string &t)
{
	PID = id;
	PT = appointmenttime;
	VT = arrivaltime;
	status = s;
	patienttype = t;
}

void Patients::setPID(int id)
{ 
	PID = id;
}

void Patients::setPT(int appointmenttime)
{
	PT = appointmenttime;
}

void Patients::setVT(int arrivaltime)
{
	VT = arrivaltime;
}

void Patients::setstatus(string& s)
{
	status = s;
}

void Patients::setpatienttype(string& t)
{
	patienttype = t;
}

void Patients::settreatmentcount(int c)
{
	treatmentcount = c;
}

void Patients::AddTreatment(string n, int d)
{ 


	if (treatmentcount >= 3)
	{
		return;
	}
		else
		{
		Treatment NEWT(n,d);
			requiredtreatment.enqueue(NEWT);
			treatmentcount++;

		}
	}
	

int Patients::getPID()
{
	return PID;
}

int Patients::getPT()
{
	return PT;
}

int Patients::getVT()
{
	return VT;
}

string Patients::getstatus()
{
	return status;
}

string Patients::getpatienttype()
{
	return patienttype;
}

int Patients::gettreatmentcount()
{
	return treatmentcount;
}

int Patients::penaltytime()
{
	if (VT > PT)
	{
		return (PT + VT) / 2;
	}
	else
	{
		return 0;
	}
}
	ostream& operator<<(ostream & out, const Patients * patient) {
		if (patient) {
			out << "Patient ID: " << patient->PID
				<< ", Type: " << patient->patienttype
				<< ", Status: " << patient->status
				<< ", Arrival Time: " << patient->VT
				<< ", Appointment Time: " << patient->PT;
		}
		else {
			out << "Null Patient Pointer";
		}
		return out;
}




