#pragma once
#include<iostream>
#include"LatePatients.h"
#include"EarlyPatients.h"
#include"Patients.h"
#include"LinkedQueue.h"
using namespace std;

class AllPatients
{
private:
	LinkedQueue<Patients*> all;
public:
	void CreateInputFile();
};

