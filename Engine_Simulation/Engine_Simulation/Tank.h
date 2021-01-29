#pragma once
#include"Valve.h"
/**
* @brief	: Created a class for Tank
*/
class Tank
{
public:
	Tank();
	~Tank();
	static int getCounter();
	int getId()const;
	void setId(int);
	double getCapacity()const;
	void setCapacity(double&);
	double getFuel_quantity()const;
	void setFuel_quantity(double);
	bool getBroken()const;
	void setBroken(bool&);
	Valve getValve()const;
	void setValve(Tank&, bool);
	bool operator == (const Tank& s) const { return id == s.id; }
	bool operator != (const Tank& s) const { return !operator==(s); }
	static int counter;
private:
	int id;
	double capacity;
	double fuel_quantity;
	bool broken;
	Valve valve;
};

