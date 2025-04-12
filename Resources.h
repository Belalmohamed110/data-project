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
	Patients* getPatient() const { return p; }
	bool isEmpty() const { return p == nullptr; }

	// Setters
	void setID(int id);
	void setresourcetype(string rtype);
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



