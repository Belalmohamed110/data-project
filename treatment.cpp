#include "treatment.h"
#pragma once
#include<iostream>
#include<string>
#include"LinkedQueue.h"

using namespace std;

treatment::treatment(string& type, int d) {
	TreatementType = type;
	duration = d;
	starttime = -1;
	endtime = -1;
	if (type != "E" && type != "U" && type != "X") {
		cout << "Invalid Treatement type, Use: E / U / X" << endl;
		return;
	}
	if (d <= 0) {
		cout << "Invalid duration , duration must be >0" << endl;
		return;
	}
}

void treatment :: settype(string& type) {
	if (type != "E" && type != "U" && type != "X") {
		cout << "Invalid Treatement type, Use: E / U / X" << endl;
		return;
	}
	TreatementType = type;
}

void treatment :: setduration(int d) {
	
	if (d <= 0) {
		cout << "Invalid duration , duration must be >0" << endl;
		return;
	}
	duration = d;
}

void treatment::start(int currentTime) {
	if (currentTime < 0) {
		cout << "Invalid time , time cannot be negative" << endl;
		return;
	}
	starttime = currentTime;
}

string treatment:: gettype() {
	return TreatementType;
}

int treatment :: getduration() {
	return duration;
}
int treatment::getstarttime() {
	return starttime;
}
void treatment:: getEndtime() {
	endtime = starttime + duration;
}


