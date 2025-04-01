#include "Scheduler.h"
Scheduler::Scheduler() {
    LoadPatientsFromFile("patients.txt");
}
void Scheduler::LoadPatientsFromFile(string filename) {
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

void Scheduler::checkAllpatientslist()
{

}

void Scheduler::settime()
{
    current_time_step++;
}

int Scheduler::gettime()
{
    return current_time_step;
}

//void Scheduler::simulation()
//{
//    int i = 1;
//    current_time_step = i;
//}
