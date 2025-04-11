#include "E_Devices.h"
#include"LinkedQueue.h"
#include"E_WaitingList.h"
E_Devices::E_Devices(int id) : Resources(id, "E_Device")
{}

bool E_Devices::enqueue(E_WaitingList * p)
{
    if (isEmpty()) {
        return LinkedQueue<E_WaitingList*>::enqueue(p);
    }
}

