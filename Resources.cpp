#include "Resources.h"

Resources::Resources(int id, string rtype) {
    ID = id;
    resourcetype = rtype;
    p = nullptr;
}

void Resources::setID(int id)
{
	ID = id;
}

void Resources::setresourcetype(string rtype)
{
	resourcetype = rtype;
}

int Resources::getID()
{
	return ID;
}

string Resources::getresourcetype()
{
	return resourcetype;
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



