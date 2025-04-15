#include<iostream>
#include"Patients.h"
#include"Resources.h"
#include "Scheduler.h"
#include "LatePatients.h"
#include"AllPatients.h"
#include"EarlyPatients.h"
#include"E_WaitingList.h"
#include <fstream>
#include "U_WaitingList.h"
#include"X_WaitingList.h"
#include"LinkedQueue.h"
#include"Node.h"
#include"priNode.h"
#include"priQueue.h"
#include"StackADT.h"
#include "ArrayStack.h"
#include"QueueADT.h"
#include<sstream>

using namespace std;

Scheduler::Scheduler() {

}


void Scheduler::LoadPatientstoAll(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    // Read the 4 header lines
    string line;
    int ne, nu, nx;         // Line 1: devices/rooms
    int cap1, cap2;         // Line 2: capacities
    int pcancel, presc;     // Line 3: probabilities
    int numPatients;        // Line 4: patient count
    
    // Read devices/rooms
    getline(file, line);
    istringstream(line) >> ne >> nu >> nx;
    
    // Read capacities
    getline(file, line);
    istringstream(line) >> cap1 >> cap2;
    
    // Read probabilities
    getline(file, line);
    istringstream(line) >> pcancel >> presc;
    
    // Read patient count
    getline(file, line);
    istringstream(line) >> numPatients;
    
    // Read each patient
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        istringstream iss(line);
        char type;
        int id,pt, vt, nt;
        
        iss >> type >> id>>pt >> vt >> nt;
        
        string status = "New";
        string patientType = (type == 'N') ? "Normal" : "Recovering";
        
        // Create patient
        Patients *newPatient =new Patients (id,pt, vt, patientType, status);
        
        // Read treatments
        for (int j = 0; j < nt; j++) {
            string treatmentType;
            int duration;
            iss >> treatmentType >> duration;
            
            treatment* newTreatment = new treatment(treatmentType, duration);
            newPatient->AddTreatment(newTreatment);
        }
        
        ALLpatients.enqueue(newPatient);
    }

    file.close();
    cout << "File loaded successfully." << endl;
}
void Scheduler::movefromALL(Patients* p)
{


for (int i = 0; i < 30; i++) {
    //Node<Patients*>* ptr = new Node<Patients*>(p);
    //Patients *ptr;
    
    p=ALLpatients.frontPtr->getItem();



    if (p->getVT() < p->getPT()) {
        //  ALLpatients.dequeue(*p);
       
       early.enqueue(p, p->getPT());
    }
    else if (p->getVT() > p->getPT()) {
		late.enqueue(p, p->getPT());    

    }
}
}
//void Scheduler::reschedule(int newpt, Patients*p1)
//{
//    Patients* ptr;
//    while(ptr!=p1)
//    { 
//    int pri = -p1->getPT();
//    p1 = early.head->getItem(pri);
//    p1->setPT(newpt)
//
//
//}
////
//void Scheduler::LoadPatientsFromDesktop(string fullPath) {
//    cout << "Loading patients from: " << fullPath << endl;
//    LoadPatientstoAll(fullPath);
//}
//
//
////void Scheduler::checkAllpatientslist()
////{
////
////}
//
void Scheduler::simulation() {
    int x = rand() % 101; // number from 0 to 100
    //Patients p;
    
    Patients *p;
    p = ALLpatients.frontPtr->getItem();

    if (x < 33) {
        // E-Waiting
        if (!early.isEmpty()) {
 
            //p->newlist(current_time_step);
            E_Waiting.enqueue(p);
            p->setstatus("E-Waiting");
        }
    }
    else if (x < 66 && x>=33) {
        // U-Waiting
        if (!early.isEmpty()) {
          
            U_Waiting.enqueue(p);
            p->setstatus("E-Waiting");
        }
    }
    else {
        // X-Waiting
        if (!early.isEmpty()) {            
            X_Waiting.enqueue(p);
            p->setstatus("E-Waiting");
        }
    }

    int X = rand() % 101;

    if (X < 10) {
        //  patient from Early to RandomWaiting 
        if (!early.isEmpty()) {
            Patients * E;
            int pri = -E->getPT();
            E = early.head->getItem(pri);
            RandomWaiting.enqueue(E);
            E->setstatus("RandomWaiting from Early");
        }
    }
    else if (X < 20 && X>=10) {
        // patient from Late to RandomWaiting using (PT + penalty)
        if (!late.isEmpty()) {
            Patients* l; 
            int pri = -l->getPT();
            l= early.head->getItem(pri);
            RandomWaiting.enqueue(l);
            l->setstatus("RandomWaiting from Early"); 
        }
    }
    else if (X < 40 && X >= 20) {
        // 2 patients from RandomWaiting to InTreatment
        for (int i = 0; i < 2 && !RandomWaiting.isEmpty(); ++i) {
            Patients* p1;
            Patients* p2;

            p1= RandomWaiting.frontPtr->getItem();
            p2 = RandomWaiting.frontPtr->getNext()->getItem();

            InTreatment.enqueue(p1);
            InTreatment.enqueue(p2);

            p1->setstatus("In-Treatment");
            p2->setstatus("In-Treatment");

        }
    }
    else if (X < 50 && X >= 40) {
        // iv. Move 1 patient from InTreatment to RandomWaiting
        if (!InTreatment.isEmpty()) {
            Patients* p1;
            p1 = InTreatment.frontPtr->getItem();
           /* InTreatment.dequeue(p1);*/
            RandomWaiting.enqueue(p1);
            p1->setstatus("Back to RandomWaiting");
        }
    }
    else if (X < 60 && X >= 50) {
        //  Move patient from InTreatment to Finish
        if (!InTreatment.isEmpty()) {
            Patients* p1;
            p1 = InTreatment.frontPtr->getItem();
            InTreatment.dequeue(p1);
            finished.enqueue(p1);
            p1->setstatus("Finished");
        }
    }
    else if (X < 70 && X >= 60) {
        //  patient from X-Waiting to Finish
        if (!X_Waiting.isEmpty()) {
            Patients* p1;
            p1 = X_Waiting.frontPtr->getItem();
           /* X_Waiting.dequeue(p1);*/
            finished.enqueue(p1);
            p1->setstatus("Finished from X-Waiting");
        }
    }
  /* else if (X < 80 && X >= 70) {
        if (!early.isEmpty()) {
            Patients* p1;
            early.dequeue(p1,-p1->getPT());
            p->setstatus("Rescheduled");
            early.enqueue(p1);
        }*/

    }

// yaraaaaaaab
// kolo d5l fe b3do w msh 3aref da leh 3laka b phase 2 wla la 
//void Scheduler::simulation(int max_time_steps) {
//    for (current_time_step = 1; current_time_step <= max_time_steps; ++current_time_step) {
//        cout << "---------- Time Step: " << current_time_step << " ----------\n";
//
//        while (!ALLpatients.isEmpty()) {
//            Patients p;
//            ALLpatients.peek(p);
//            if (p.getVT() == current_time_step) {
//                ALLpatients.dequeue(p);
//                movefromALL(p);
//            }
//            else {
//                break; // Remaining patients are for future times
//            }
//        }
//        randomwaiting();
//        cout << "Early List Size: " << early.getCount() << endl;
//        cout << "Late List Size: " << late.getCount() << endl;
//        cout << "E_Waiting Size: " << E_Waiting.getCount() << endl;
//    }
//}

//void Scheduler::settime()
//{
//    current_time_step++;
//}
//
//int Scheduler::gettime()
//{
//    return current_time_step;
//}

//void Scheduler::simulation()
//{
//    int i = 1;
//    current_time_step = i;
//}
