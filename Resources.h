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
	Resources(int id, string rtype);
	void setID(int id);
	void setresourcetype(string rtype);
	int getID();
	string getresourcetype();


	//bool IsEmpty(); msh 3aref lsa h3mlha ezay 
	/*void assignresource( Patients * p);
	void removeresource(Patients* p );*/

	// Friend function declaration for operator<<
	friend ostream& operator<<(ostream& os, const Resources& res);
        void print() const

};



