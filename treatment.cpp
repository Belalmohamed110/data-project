#include "treatment.h"
#pragma once
#include<iostream>
#include<string>
#include"LinkedQueue.h"

using namespace std;

treatment::treatment(string type, int d) {
	TreatementType = type;
	duration = d;
}
void treatment :: settype(string type) {
	TreatementType = type;
}

void treatment :: setduration(int d) {
	duration =d ;
}

void treatment::start(int currentTime) {
	starttime = currentTime;
}

void treatment :: setstarttime(int st) {
  starttime = st;
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


