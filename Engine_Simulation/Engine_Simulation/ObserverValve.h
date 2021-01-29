#pragma once
#include "Observer.h"
#include "Write.h"

class ObserverValve:
    public Observer
{
private:
    Write write;
    string message;
    static int counter;
public:
    void update() {
        message = "Valve:"+ to_string(counter++) +" Simulation stopped\n";
        write.write_file(message);
    }
};