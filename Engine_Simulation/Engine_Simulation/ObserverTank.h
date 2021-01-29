#pragma once
#include "Observer.h"
#include"Write.h"
/**
* @brief: Created a class for ObserverTank, inherited from Observer
* @author: Yasemin Gerboga 152120171056
*/
class ObserverTank :
    public Observer
{
private:
    Write write;
    string message;
    static int counter;
public:
    void update() {
        message = "Tank: " + to_string(counter++) + " Simulation stopped\n";
        write.write_file(message);
    }
};

