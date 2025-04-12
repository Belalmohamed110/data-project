#include "AllPatients.h"
#include<iostream>
#include"LatePatients.h"
#include"EarlyPatients.h"
#include"Patients.h"
#include"LinkedQueue.h"
using namespace std;
#include <fstream>

void AllPatients::CreateInputFile()
{
    std::ofstream file("patients.txt");
    if (!file) {
        std::cout << "Error creating file!" << std::endl;
        return;
    }
    file << "P1 10 5" << endl;
    file << "P2 15 8" << endl;
    file << "P3 20 6" << endl;
    file.close();
    std::cout << "File created successfully!" << std::endl;

}
//lists only store patienrts -> enquque and dequeue only 
//file -> all -> schedueler -> hwa el biwz3 kol haga
// 7oto 3ndk w b3d shwia hakhdo 3shan m3ado geh 
// print kolohom

// patient -> object mn queue bas msh mstahla class.
