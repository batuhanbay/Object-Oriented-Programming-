#pragma once
#include "Observer.h"
#include"Subject.h"
#include"Engine.h"
/**
* @brief: Created a class for ObserverEngine, inherited from Observer
* @author: Yasemin Gerboga 152120171056
*/
class ObserverEngine :
    public Observer
{
private:
    Write write;
    string message;
public:
    void update() {
        message = "Engine: Simulation stopped\n";
        write.write_file(message);
    }
};