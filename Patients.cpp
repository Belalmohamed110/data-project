#include "Patients.h"
#include<iostream>
#include <string>
using namespace std;


Patients::Patients(int id, int pt, int vt, string s, string t) :
	PID(id), PT(pt), VT(vt), status(s), patienttype(t) {
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

void Patients::setstatus(string s)
{
	status = s;
}

void Patients::setpatienttype(string  t)
{
	patienttype = t;
}

void Patients::settreatmentcount(int c)
{
	treatmentcount = c;
}

void Patients::AddTreatment(treatment* t) {
	treatments.enqueue(t); }

treatment* Patients::getNextTreatment() {
	if (treatments.isEmpty()) return nullptr;

	treatments.dequeue(currentTreatment);
	return currentTreatment;
}

int Patients::getAdjustedPT()  {
	if (VT > PT) {
		int penalty = (VT - PT) / 2;
		adjustedPT = PT + penalty;
	}
	else {
		adjustedPT = PT;
	}
	return adjustedPT;
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
ostream& operator<<(ostream& out, const Patients* patient) {
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

treatment* Patients::getCurrentTreatment(){ return currentTreatment; }
treatment* Patients:: getEndtime() {return endtime;}
