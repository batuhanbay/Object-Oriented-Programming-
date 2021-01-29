#include "EngineSingleton.h"
EngineSingleton* EngineSingleton::instance = 0;
void EngineSingleton::setEngine(Engine* engine)
{
    this->engine = engine;
}

Engine *EngineSingleton::getEngine()
{
    return this->engine;
}
