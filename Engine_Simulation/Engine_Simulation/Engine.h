#pragma once
#include<list>
#include"Tank.h"
#include<iostream>
#include"Write.h"
using namespace std;
/**
* @brief	: Created a class for Engine
*/
class Engine
{
public:
	Engine();
	~Engine();
	double getFuel_per_second()const;
	bool getStatus()const;
	void setStatus(bool);
	Tank& getInternal();
	void setInternal(Tank&);
	list<Tank> getListTank()const;
	void setListTank(list<Tank>);
	void print_total_fuel_quantity();
	void list_connected_tank();
	void start_engine();
	void stop_engine();
	void absorb_fuel(double);
	void give_back_fuel(double);
	void openValveOperation(int);
	void closeValveOperation(int);
	private:	
	static double fuel_per_second;
	bool status;
	Tank internal;
	list<Tank> list_tank;
	Write write;
};