#pragma once
#include <iostream>
#include <fstream>
#include"Patients.h"
using namespace std;
class Resources
{
	int ID;
	string resourcetype ;
	Patients* ppp;
public:
	Resources(int id, string rtype);
	//bool IsEmpty(); msh 3aref lsa h3mlha ezay 
	/*void assignresource( Patients * p);
	void removeresource(Patients* p );*/
};

