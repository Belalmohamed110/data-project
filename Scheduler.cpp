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

    int id;
    int vt, pt;
    while (file >> id >> vt >> pt) { // Read values
        Patients newPatient(id, vt, pt);
        ALLpatients.enqueue(newPatient); // Add patient to queue
    }

    file.close();
}

void Scheduler::movefromALL(Patients & p)
{
  
    if (p.getVT() < p.getPT() ) {
        ALLpatients.dequeue(p);
        early.enqueue(p,pri );
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
    //Patients p;

    if (x < 33) {
        // E-Waiting
        if (!early.isEmpty()) {
            EarlyPatients p;
            int pri;
            early.dequeue(p,pri);
            E_Waiting.enqueue(p);
            Patients p1();
            p1().setstatus("E-Waiting");
        }
    }
    else if (x < 66 && x>=33) {
        // U-Waiting
        if (!early.isEmpty()) {
            EarlyPatients p;
            int pri;
            early.dequeue(p,pri);
            U_Waiting.enqueue(p);
            Patients p1();
            p1().setstatus("U-Waiting");
        }
    }
    else {
        // X-Waiting
        if (!early.isEmpty()) {            
            EarlyPatients p;
            int pri;
            early.dequeue(p,pri);
            X_Waiting.enqueue(p);
            Patients p1();
            p1().setstatus("X-Waiting");
        }
    }

    int X = rand() % 101;

    if (X < 10) {
        //  patient from Early to RandomWaiting
        if (!early.isEmpty()) {
            EarlyPatients p;
            int pri;
            early.dequeue(p, pri);
            RandomWaiting.enqueue(p);
            p.setstatus("RandomWaiting from Early");
        }
    }
    else if (X < 20 && X>=10) {
        // patient from Late to RandomWaiting using PT + penalty
        if (!late.isEmpty()) {
            late.dequeue(p);
            p.setPT(p.getPT() + 5); // Apply penalty
            RandomWaiting.enqueue(p);
            p.setstatus("RandomWaiting from Late with penalty");
        }
    }
    else if (X < 40 && X >= 20) {
        // 2 patients from RandomWaiting to InTreatment
        for (int i = 0; i < 2 && !RandomWaiting.isEmpty(); ++i) {
            RandomWaiting.dequeue(p);
            InTreatment.enqueue(p);
            p.setstatus("In-Treatment");
        }
    }
    else if (X < 50 && X >= 40) {
        // iv. Move 1 patient from InTreatment to RandomWaiting
        if (!InTreatment.isEmpty()) {
            InTreatment.dequeue(p);
            RandomWaiting.enqueue(p);
            p.setstatus("Back to RandomWaiting");
        }
    }
    else if (X < 60 && X >= 50) {
        //  Move patient from InTreatment to Finish
        if (!InTreatment.isEmpty()) {
            InTreatment.dequeue(p);
            Finish.enqueue(p);
            p.setstatus("Finished");
        }
    }
    else if (X < 70 && X >= 60) {
        //  patient from X-Waiting to Finish
        if (!X_Waiting.isEmpty()) {
            X_Waiting.dequeue(p);
            Finish.enqueue(p);
            p.setstatus("Finished from X-Waiting");
        }
    }
    else if (X < 80 && X >= 70) {
        if (!early.isEmpty()) {
            early.dequeue(p);
            p.setstatus("Rescheduled");
            early.enqueue(p);
        }
    }
}
// yaraaaaaaab
// kolo d5l fe b3do w msh 3aref da leh 3laka b phase 2 wla la 
void Scheduler::simulation(int max_time_steps) {
    for (current_time_step = 1; current_time_step <= max_time_steps; ++current_time_step) {
        cout << "---------- Time Step: " << current_time_step << " ----------\n";

        while (!ALLpatients.isEmpty()) {
            Patients p;
            ALLpatients.peek(p);
            if (p.getVT() == current_time_step) {
                ALLpatients.dequeue(p);
                movefromALL(p);
            }
            else {
                break; // Remaining patients are for future times
            }
        }
        randomwaiting();
        cout << "Early List Size: " << early.getCount() << endl;
        cout << "Late List Size: " << late.getCount() << endl;
        cout << "E_Waiting Size: " << E_Waiting.getCount() << endl;
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
