#include "Valve.h"

Valve::Valve()
{
}

Valve::~Valve()
{
}

void Valve::open_valve()
{
	this->valve = true;
}

void Valve::close_valve()
{
	this->valve = false;
}

bool Valve::getSatus() const
{
	return this->valve;
}
