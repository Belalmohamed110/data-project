#pragma once
#include <iostream>
#include <string>
#include"LinkedQueue.h"
using namespace std;

class treatment
{
private:
	string TreatementType;
	int duration;
	int starttime;
	int endtime;
	
public:
	void settype(string type) {}
	void setduration(int d) {}
	void setstarttime(int startime) {}

	treatment(string type, int d) {}
		
	void  start(int currentTime) {}
	
	string gettype() {}
	int getduration() {}
	int getstarttime() {}
	void getEndtime() {}

};

