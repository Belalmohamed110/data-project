#pragma once
#include"Resources.h"
#include"E_WaitingList.h"
class E_Devices : public Resources
{
public:
	E_Devices(int id);
bool enqueue(E_WaitingList * p);
};

