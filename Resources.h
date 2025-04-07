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
	Patients* ppp;

public:
	Resources(int id, string rtype);
	//bool IsEmpty(); msh 3aref lsa h3mlha ezay 
	/*void assignresource( Patients * p);
	void removeresource(Patients* p );*/

	// Friend function declaration for operator<<
	friend ostream& operator<<(ostream& os, const Resources& res);
};

