#pragma once
#include<list>
#include"Engine.h"
#include"Read.h"
#include"Write.h"
#include"SplitString.h"
#include"EngineSingleton.h"
#include"ObserverTank.h"
#include"ObserverEngine.h"
#include"ObserverValve.h"
#include"Subject.h"
/**
* @brief	: Created a class for Simulation
*/
class Simulation
{
public:
	Simulation(Read,EngineSingleton*);
	~Simulation();
	Engine getEngine()const;
	void setEngine(Engine);
	void connect_fuel_tank_to_engine(int);
	void disconnect_fuel_tank_from_engine(int);
	Tank getTank()const;
	void setTank(Tank);
	list<Tank> getTank_list()const;
	void stop_simulation();
	int list_fuel_tanks();
	void print_fuel_tank_count();
	void add_fuel_tank(double);
	void fill_tank(int, double);
	void remove_fuel_tank(int);
	void print_total_consumed_fuel_quantity();
	void setTotalConsumedFuel(double);
	double getTotalConsumedFuel();
	void fileOperations(vector<string>);
	SplitString getSplitString()const;
	void setSplitString(SplitString);
	void wait(int);
	void print_tank_info(int);
	void repair_fuel_tank(int);
	void break_fuel_tank(int);
	Read read;
	Write write;
private:
	double total_consumed_fuel = 0.0;
	Subject* subject = new Subject();
	Observer* observer;
	EngineSingleton* engine;
	list<Tank> tank_list;
	SplitString splitString;
	Tank tank;
	Valve valve;
};