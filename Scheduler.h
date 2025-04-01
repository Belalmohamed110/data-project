#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Scheduler
{
	int current_time_step=0 ;
public:
	Scheduler();
	void LoadPatientsFromFile(string );
	void checkAllpatientslist();
	void settime();
	int gettime();
	//void simulation();
};

