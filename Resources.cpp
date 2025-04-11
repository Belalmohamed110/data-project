#include "Resources.h"

Resources::Resources(int id, string rtype) {
    ID = id;
    resourcetype = rtype;
    p = nullptr;
}

int Resources::getID() const {
    return ID;
}

string Resources::getresourcetype() const {
    return resourcetype;
}

Patients* Resources::getAssignedPatient() const {
    return p;
}

bool Resources::isEmpty() const {
    return p == nullptr;
}

void Resources::setID(int id) {
    ID = id;
}

void Resources::setresourcetype(string rtype) {
    resourcetype = rtype;
}

bool Resources::assignPatient(Patients* patient) {
    if (isEmpty()) {
        p = patient;
        return true;
    }
    return false;
}

bool Resources::removePatient() {
    if (!isEmpty()) {
        p = nullptr;
        return true;
    }
    return false;
}

// Operator<< implementation
ostream& operator<<(ostream& os, const Resources& res) {
    if (res.resourcetype == "X") {
        os << "R" << res.ID;
    } else {
        os << res.resourcetype << res.ID;
    }
    return os;
}
