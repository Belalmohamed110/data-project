#include "Patients.h"
#include<iostream>
#include <string>
using namespace std;

void Patients::setPID(int id)
{ 
	PID = id;
}

void Patients::setPT(int appointementtime)
{
	PT = appointementtime;
}

void Patients::setVT(int arrivaltime)
{
	VT = arrivaltime;
}

void Patients::setstatus(string s)
{
	status = s;
}

void Patients::setpatienttype(string t)
{
	patienttype = t;
}

void Patients::AddTreatment(string &t, int d)
{
	int treatmentcount = 0;
		if (treatmentcount >= 3)
		{
			return;
		}
		else
		{
			requiredtreatment.enqueue(t);
			duration[treatmentcount] = d;
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

int Patients::penaltytime()
{
	if (VT > PT)
	{
		return ((PT + VT) / 2);
	}
	else
	{
		return false;
	}
ostream& operator<<(ostream& out, const Patients* patient) {
    if (patient) {
        out << "Patient ID: " << patient->PID
            << ", Type: " << patient->patienttype
            << ", Status: " << patient->status
            << ", Arrival Time: " << patient->VT
            << ", Appointment Time: " << patient->PT;
    } else {
        out << "Null Patient Pointer";
    }
    return out;
}













