#include "Resources.h"

Resources::Resources(int id, string rtype) {
    ID = id;
    resourcetype = rtype;
    ppp = nullptr;
}

// Operator<< implementation
ostream& operator<<(ostream& os, const Resources& res) {
    os << "Resource Type: " << res.resourcetype << ", ID: " << res.ID;
    return os;
}
void print() const {
		cout << "Resource Type: " << resourcetype << ", ID: " << ID << endl;
	}


//bool Resources::IsEmpty()
//{
//    return false;
//}



