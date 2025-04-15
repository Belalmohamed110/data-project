#pragma once
#include <iostream>
#include <fstream>
#include "Patients.h"
using namespace std;

class Resources
{
private:
	int ID;
	string resourcetype;
	Patients* p;

public:
	// Constructor
	Resources(int id, string rtype);

	// Getters
	int getID() const;
	string getresourcetype() const;
	Patients* getAssignedPatient() const;
	Patients* getPatient() const { return p; }
	bool isEmpty() const;

	// Setters
	void setID(int id);
	void setresourcetype(string rtype);
	bool assignPatient(Patients* patient);
	bool removePatient();
	void setPatient(Patients* patient) { p = patient; }

	// Print method - outputs the resource identifier
	void print() const {
		if (resourcetype == "X") {
			cout << "R" << ID;
		} else {
			cout << resourcetype << ID;
		}
	}

	// Friend function declaration for operator<<
	friend ostream& operator<<(ostream& os, const Resources& res);
};



