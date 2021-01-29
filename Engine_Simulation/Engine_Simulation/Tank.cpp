#include "Tank.h"
/**
 * @brief					: This function is default constructor.
*/
Tank::Tank()
{
}

/**
 * @brief					: This function is destructor.
*/
Tank::~Tank()
{
}
/**
 * @brief					: Assigns static value of counter.
*/
int Tank::counter = 0;

int Tank::getCounter()
{
	return counter;
}
/**
 * @brief					: This function is used to get id
 * @param					: Null
 * @return id				: returns tank's id
 */
int Tank::getId() const
{
	return this->id;
}
/**
 * @brief					: This function is used to set id
 * @param id				: Tank's id
 * @return void				: returns void
 */
void Tank::setId(int id)
{
	this->id = id;
}

 /**
  * @brief					: This function is used to get capacity
  * @param					: Null
  * @return capacity			: returns tank's capacity
  */
double Tank::getCapacity() const
{
	return capacity;
}
/**
 * @brief					: This function is used to set capacity
 * @param capacity			: Tank's capacity
 * @return					: void
 */
void Tank::setCapacity(double& capacity)
{
	this->capacity = capacity;
}
/**
 * @brief					: This function is used to get fuel quantity
 * @param					: Null
 * @return fuel_quantity	: returns tank's fuel_quantity
 */
double Tank::getFuel_quantity() const
{
	return fuel_quantity;
}
/**
 * @brief					: This function is used to set fuel quentity
 * @param fuel_quentity		: Tank's fuel quentity
 * @return 					: void
 */
void Tank::setFuel_quantity(double fuel_quentity)
{
	this->fuel_quantity = fuel_quentity;
}
/**
 * @brief					: This function is used to get broken status
 * @param					: Null
 * @return broken			: returns tank's broken status
 */
bool Tank::getBroken() const
{
	return broken;
}
/**
 * @brief					: This function is used to set tank's broken status
 * @param broken			: Tank's broken status
 * @return 					: void
 */
void Tank::setBroken(bool& broken)
{
	this->broken = broken;
}
/**
 * @brief					: This function is used to get valve
 * @param					: Null
 * @return valve			: returns tank's valve
 */
Valve Tank::getValve() const
{
	return valve;
}
/**
 * @brief					: This function is used to set tank's valve's status
 * @param tank,status		: Tank and bool status
 * @return 					: void
 */
void Tank::setValve(Tank& tank,bool status)
{
	if (status == true) {
		tank.valve.open_valve();
	}
	else {
		tank.valve.close_valve();
	}
}

