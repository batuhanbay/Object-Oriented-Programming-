#include "Engine.h"
#include "EngineSingleton.h"
#include <time.h>       /* time */
#include <vector>
/**
 * @brief					: Assigns static value of fuel per second.
*/
double Engine::fuel_per_second = 5.5;
/**
 * @brief					: This function is constructor.
*/
Engine::Engine()
{
	double capacity = 55.0;
	bool open = true;
	internal.setCapacity(capacity);
	internal.setValve(internal, open);
	this->status = false;
}
/**
 * @brief					: This function is destructor.
*/
Engine::~Engine()
{
}
/**
 * @brief					: This function is used to get fuel_per_second
 * @param					: Null
 * @return fuel_per_second	: returns const fuel_per_second
 */
double Engine::getFuel_per_second() const
{
	return fuel_per_second;
}
/**
 * @brief					: This function is used to get status
 * @param					: Null
 * @return status			: returns status
 */
bool Engine::getStatus() const
{
	return status;
}
/**
 * @brief					: This function is used to set status
 * @param status			: boolean value for status
 * @return					: void
 */
void Engine::setStatus(bool status)
{
	this->status = status;
}
/**
 * @brief					: This function is used to get internal
 * @param					: Null
 * @return internal			: returns internal
 */
Tank& Engine::getInternal()
{
	return internal;
}
/**
 * @brief					: This function is used to set internal
 * @param internal			: Tank internal
 * @return					: returns void
 */
void Engine::setInternal(Tank& internal)
{
	this->internal = internal;
}
/**
 * @brief					: Prints total fuel_quantity to output file.
 * @param					: Null
 * @return 					: returns void
 */
void Engine::print_total_fuel_quantity()
{
	string message = "Total fuel quantitiy is: ";
	double total_fuel = 0.0;
	for (Tank tank : this->list_tank) {
		total_fuel += tank.getFuel_quantity();
	}
	message += to_string(total_fuel)+"\n";
	this->write.write_file(message);
}
/**
 * @brief					:
 * @param					: Null
 * @return 					: return void
 */
void Engine::list_connected_tank()
{
}
/**
 * @brief					: This function start the engine.
 * @param					: Null
 * @return 					: void
 */
void Engine::start_engine()
{
	try
	{
		if (!EngineSingleton::getInstance()->getEngine()->getListTank().empty()) // Engine içindeki tank listesi boş değilse
		{
			bool temp = true;
			EngineSingleton::getInstance()->getEngine()->setStatus(temp);
		}
		else {
			string message = "Motor calistirilamadi! Calistirmak istediginiz motor yakit deposuna sahip degil veya yeterli yakit yok!\n";
			throw message;
		}
	}
	catch (const string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: This function stop the engine.
 * @param					: Null
 * @return 					: void
 */
void Engine::stop_engine()
{
	give_back_fuel(getInternal().getFuel_quantity());
	this->setStatus(false);
}
/**
 * @brief					: This function is used to get list of tanks
 * @param					: Null
 * @return listTank			: returns list of tanks
 */
list<Tank> Engine::getListTank() const
{
	return list_tank;
}
void Engine::setListTank(list<Tank> _list_tank)
{
	this->list_tank = _list_tank;
}
/**
 * @brief					: this function used to absorb fuel from tank list if there is below 20 fuel in internal tank
 * @param quantity			: double quantity
 * @return 					: void
 */
void Engine::absorb_fuel(double quantity)
{
	vector<Tank> tankList;
	bool flag = false;
	int index;
	for (Tank& tank : this->list_tank) {
		if (tank.getFuel_quantity() >= quantity && tank.getValve().getSatus()==true) {
			tankList.push_back(tank);
			flag = true;
		}
	}
	if (flag == true) {
		index = rand() % tankList.size() + 0;
		for (Tank& tank : this->list_tank) {
			if (tank.getId() == tankList[index].getId()) {
				tank.setFuel_quantity(tank.getFuel_quantity() - quantity);
				break;
			}
		}
	}
	else
		this->stop_engine();
}
/**
 * @brief                    : This function is used to give back fuel that contains minimum amount of fuel
 */
void Engine::give_back_fuel(double amount)
{
	double min = INT_MAX;
	for (Tank tank : this->list_tank) {
		if (tank.getFuel_quantity() <= min && tank.getValve().getSatus() == true)
			min = tank.getFuel_quantity();
	}

	for (Tank& tank : this->list_tank) {
		if (min == tank.getFuel_quantity()) {
			tank.setFuel_quantity(tank.getFuel_quantity() + amount);
			this->internal.setFuel_quantity(this->internal.getFuel_quantity() - amount);
			break;
		}
	}
}
/**
 * @brief					: This function is used to open valve
 * @param id				: Tank's id that we want to open valve
 * @return					: returns void
 */
void Engine::openValveOperation(int id)
{
	try
	{
		bool flag = false;
		string message;
		for (Tank& tank : list_tank) {
			if (tank.getId() == id) {
				flag = true;
				tank.setValve(tank, flag);
				return;
			}
		}
		if (flag == false) {
			message = "Kapak acilamadi." + to_string(id) + " numarali ID'ye sahip herhangi bir tankin kapagi bulunamadi.\n";
			throw message;
		}
	}
	catch (const string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: This function is used to close valve
 * @param id				: Tank's id that we want to close valve
 * @return					: returns void
 */
void Engine::closeValveOperation(int id)
{
	try
	{
		bool flag = true;
		string message;
		for (Tank& tank : list_tank) {
			if (tank.getId() == id) {
				flag = false;
				tank.setValve(tank, flag);
				return;
			}
		}
		if (flag == true) {
			message = "Kapak kapanamadi." + to_string(id) + " numarali ID'ye sahip herhangi bir tankin kapagi bulunamadi.\n";
			throw message;
		}
	}
	catch (const string message)
	{
		write.write_file(message);
	}
}

