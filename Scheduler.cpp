#include<iostream>
#include"Patients.h"
#include"Resources.h"
#include "Scheduler.h"
#include "LatePatients.h"

using namespace std;
Scheduler::Scheduler() {
    LoadPatientstoAll("patients.txt");
}
void Scheduler::LoadPatientstoAll(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    string id;
    int vt, pt;
    while (file >> id >> vt >> pt) { // Read values
        Patients newPatient(id, vt, pt);
        ALLpatients.enqueue(newPatient); // Add patient to queue
    }

    file.close();
}

void Scheduler::addtowaitlist(Patients & p)
{
    if (p.getVT() < p.getPT() ) {
        early.enqueue(p);
        p.setstatus("early wait list");
    }
    else if (p.getVT() > p.getPT()) {
        
        late.enqueue(p);
        p.setstatus("late wait list");
    }
    //else hay5osh 3la waiting 3la tol  

}

//void Scheduler::checkAllpatientslist()
//{
//
//}

void Scheduler::randomwaiting() {
    int x = rand() % 101; // number from 0 to 100

    if (x < 33) {
        // E-Waiting
        if (!early.isEmpty()) {
            Patients p;
            early.dequeue(p);
            E_Waiting.enqueue(p);
            p.setstatus("E-Waiting");
        }
    }
    else if (x < 66) {
        // U-Waiting
        if (!early.isEmpty()) {
            Patients p;
            early.dequeue(p);
            U_Waiting.enqueue(p);
            p.setstatus("U-Waiting");
        }
    }
    else {
        // X-Waiting
        if (!early.isEmpty()) {
            Patients p;
            early.dequeue(p);
            X_Waiting.enqueue(p);
            p.setstatus("X-Waiting");
        }
    }

    // New random number for main control
    int X = rand() % 101;

    if (X < 10) {
        // i. Move patient from Early to RandomWaiting
        if (!early.isEmpty()) {
            Patients p;
            early.dequeue(p);
            RandomWaiting.enqueue(p);
            p.setstatus("RandomWaiting from Early");
        }
    }
    else if (X < 20 && X>=10) {
        // ii. Move patient from Late to RandomWaiting using PT + penalty
        if (!late.isEmpty()) {
            Patients p;
            late.dequeue(p);
            p.setPT(p.getPT() + 5); // Apply penalty
            RandomWaiting.enqueue(p);
            p.setstatus("RandomWaiting from Late with penalty");
        }
    }
    else if (X < 40 && X >= 20) {
        // iii. Move 2 patients from RandomWaiting to InTreatment
        for (int i = 0; i < 2 && !RandomWaiting.isEmpty(); ++i) {
            Patients p;
            RandomWaiting.dequeue(p);
            InTreatment.enqueue(p);
            p.setstatus("In-Treatment");
        }
    }
    else if (X < 50 && X >= 40) {
        // iv. Move 1 patient from InTreatment to RandomWaiting
        if (!InTreatment.isEmpty()) {
            Patients p;
            InTreatment.dequeue(p);
            RandomWaiting.enqueue(p);
            p.setstatus("Back to RandomWaiting");
        }
    }
    else if (X < 60 && X >= 50) {
        // v. Move 1 patient from InTreatment to Finish
        if (!InTreatment.isEmpty()) {
            Patients p;
            InTreatment.dequeue(p);
            Finish.enqueue(p);
            p.setstatus("Finished");
        }
    }
    else if (X < 70 && X >= 60) {
        // vi. Random patient from X-Waiting to Finish
        if (!X_Waiting.isEmpty()) {
            Patients p;
            X_Waiting.dequeue(p);
            Finish.enqueue(p);
            p.setstatus("Finished from X-Waiting");
        }
    }
    else if (X < 80 && X >= 70) {
        // vii. Choose random patient from Early list to reschedule
        if (!early.isEmpty()) {
            Patients p;
            early.dequeue(p);
            // reschedule logic – here we just re-add with status
            p.setstatus("Rescheduled");
            early.enqueue(p);
        }
    }
}


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
