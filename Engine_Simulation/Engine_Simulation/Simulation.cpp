#include "Simulation.h"
#include <list>

/**
 * @brief					: This function is used to create simulation object.
 * @param _read , engine	: Read read, EngineSingleton* engine
 * @return					: void
 */
Simulation::Simulation(Read _read, EngineSingleton* engine) :engine(engine)
{
	this->read = _read;
	if (remove("output.txt") != 0)
		string message="Error deleting file";
	else
		string message="File successfully deleted";
}
/**
 * @brief					: This function is used to deconstructure of Simulation object.
 * @param Null				: Null
 * @return					: void
 */
Simulation::~Simulation()
{
}
/**
 * @brief					: This function is used to get Engine of Simulation class.
 * @param Null				: Null
 * @return					: Engine engine
 */
Engine Simulation::getEngine() const
{
	return Engine();
}
/**
 * @brief					: This function is used to set Engine of Simulation class.
 * @param engine 			: Engine engine
 * @return					: void
 */
void Simulation::setEngine(Engine)
{
}
/**
 * @brief					: This function is used to connect fuel tank to engine.
 * @param _id				: int id
 * @return					: void
 */
void Simulation::connect_fuel_tank_to_engine(int _id)
{
	list<Tank> enngineConnectedTanks = this->engine->getEngine()->getListTank();
	bool hasTank = false;
	string message;
	try
	{
		for (Tank tank : this->tank_list) {
			if (tank.getId() == _id) { // eslesen id var mi yok mu kontrol
				hasTank = true; // istenen tank listede var
				enngineConnectedTanks.push_back(tank); // engine tank listesine ekle
			}
		}
		this->engine->getEngine()->setListTank(enngineConnectedTanks);
		if (hasTank == false) { // eger istenilen id de tank yoksa hata mesaji yazdır
			message = "Hata baglanamadi! " + to_string(_id) + " numarali id ye sahip tank bulunamadi\n";
			throw message; // hata mesaji gonder
		}
	}
	catch (string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: This function is used to disconnect fuel tank from engine.
 * @param _id				: int _id
 * @return					: void
 */
void Simulation::disconnect_fuel_tank_from_engine(int _id)
{
	list<Tank> enngineConnectedTanks = this->engine->getEngine()->getListTank();
	bool hasTank = false;
	string message;
	try
	{
		for (Tank tank : enngineConnectedTanks) {
			if (tank.getId() == _id) { // eslesen id var mi yok mu kontrol
				hasTank = true; // istenen tank listede var
				enngineConnectedTanks.remove(tank); // listeden tanki kaldir
				break; //döngüyü kir
			}
		}
		this->engine->getEngine()->setListTank(enngineConnectedTanks);
		if (hasTank == false) { // eger istenilen id de tank yoksa hata mesaji yazdır
			message = "Silinmek istenen " + to_string(_id) + " numarali tank silinemedi. Bu tank daha once silinmis veya tank listesine ekli olmuyabilir...!\n";
			throw message; // hata mesaji gonder
		}
	}
	catch (string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: This function is used to get Tank of Simulation class.
 * @param Null				: Null
 * @return					: Tank tank
 */
Tank Simulation::getTank() const
{
	return Tank();
}
/**
 * @brief					: This function is used to set Tank of Simulation class.
 * @param tank				: Tank tank
 * @return					: void
 */
void Simulation::setTank(Tank)
{
}
/**
 * @brief					: This function is used to sget List Tank of Simulation class.
 * @param Null				: Null
 * @return tank_list		: list<Tank> tank_list
 */
list<Tank> Simulation::getTank_list() const
{
	return list<Tank>();
}
/**
 * @brief					: This function is used to stop simulation.
 * @param Null				: Null
 * @return					: void
 */
void Simulation::stop_simulation()
{
	exit(0);
}
/**
 * @brief					: This function is used to list of fuel tanks of Simulation class.
 * @param Null				: Null
 * @return					: void
 */
int Simulation::list_fuel_tanks()
{
	return this->tank_list.size();
}
/**
 * @brief					: This function is used to print fuel tank count
 * @param Null				: Null
 * @return					: void
 */
void Simulation::print_fuel_tank_count()
{
	string message = "Fuel tank count: ";
	message += to_string(this->tank_list.size()) + "\n";
	this->write.write_file(message);
}
/**
 * @brief					: This function is used to add fuel tank to capacity and push tank list which is in simulation class.
 * @param capacity			: double capacity
 * @return					: void
 */
void Simulation::add_fuel_tank(double capacity)
{
	Tank::counter++;//id atama default -> id = 1
	this->tank.setId(Tank::counter);
	this->tank.setCapacity(capacity); // kapasiite ata 
	this->tank_list.push_back(this->tank); //tanki pushla listeye
	observer = new ObserverTank();
	subject->registerObserver(observer);
}

/**
 * @brief					: This function is used to add fuel tank to quantity by using tank id.
 * @param id , quantity		: int id ,double quantity
 * @return					: void
 */
void Simulation::fill_tank(int id, double quantity)
{
	bool hasTank = false;
	string message;
	try
	{
		for (Tank& tank : this->tank_list) {
			if (tank.getId() == id) { // eslesen id var mi yok mu kontrol
				hasTank = true; // istenen tank listede var
				if (tank.getCapacity() <= quantity) // Kontrol et eğer doldurulmak istenen yakıt kapasiteden fazla mı ? 
				{
					tank.setFuel_quantity(tank.getCapacity()); // Fazla ise kapasitesi kadar yakıt doldur
				}
				else // Fazla degilse
				{
					tank.setFuel_quantity(quantity); //istenilen yakiti doldur
				}
			}
		}
		if (hasTank == false) { // eger istenilen id de tank yoksa hata mesaji yazdır
			throw message = "Yakıt doldurulmak istenen" + to_string(id) + " numarali tank bulunamadi...!\n";; // hata mesaji
		}
	}
	catch (string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: This function is used to remove tank from simulation tank list.
 * @param id 				: int id 
 * @return					: void
 */
void Simulation::remove_fuel_tank(int id)
{
	bool hasTank = false;
	string message;
	try
	{
		for (Tank tank : this->tank_list) {
			if (tank.getId() == id) { // eslesen id var mi yok mu kontrol
				hasTank = true; // istenen tank listede var
				this->tank_list.remove(tank); // listeden tanki kaldir
				break; // döngüyü kır
			}
		}
		if (hasTank == false) { // eger istenilen id de tank yoksa hata mesaji yazdır
			throw message = "Silinmek istenen" + to_string(id) + "tank bulunamadi...!\n";; // throw hata mesaji

		}
	}
	catch (string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: Prints total fuel_quantity to output file.
 * @param					: Null
 * @return 					: returns void
 */
void Simulation::print_total_consumed_fuel_quantity()
{
	string message = "Total Consumed Fuel Quantity: ";
	message += to_string(getTotalConsumedFuel()) + "\n";
	this->write.write_file(message);
}
void Simulation::setTotalConsumedFuel(double quantity)
{
	total_consumed_fuel = quantity;
}
double Simulation::getTotalConsumedFuel()
{
	return total_consumed_fuel;
}
/**
 * @brief					: This function get command and implement the operation related to command
 * @param commands			: vector<string> commands
 * @return 					: void
 */

void Simulation::fileOperations(vector<string> commands)
{
	for (int i = 0; i < commands.size(); i++)
	{
		//start simulation
		if (commands[i] == "start_engine;") {
			this->engine->getEngine()->start_engine();
			//Engine starts (start engine içinde status true set edilek)
			if (this->engine->getEngine()->getStatus() == true) {
				observer = new ObserverEngine();
				subject->registerObserver(observer);
			}
		}
		if (commands[i] == "stop_engine;") {
			this->engine->getEngine()->stop_engine();
			//stop engine
		}
		if (commands[i].find("print_tank_info") != string::npos) {
			this->wait(1);
			double number = splitString.values(commands[i]);
			print_tank_info(number);
		}
		if (commands[i].find("break_fuel_tank") != string::npos) {
			//split fonksiyonla id elde edilcek
			this->wait(1);
			double number = splitString.values(commands[i]);
			break_fuel_tank(number);
		}
		if (commands[i].find("repair_fuel_tank") != string::npos) {
			this->wait(1);
			//split fonksiyonla id elde edilcek
			double number = splitString.values(commands[i]);
			repair_fuel_tank(number);
		}
		if (commands[i].find("add_fuel_tank") != string::npos)
		{
			this->wait(1);
			//get the value of command (value = capacity)
			int number = splitString.values(commands[i]);
			//add_fuel_tank fonk cağır ve  the id and capacity ekle yeni tanka
			add_fuel_tank(number);
			// oluşturulan tankı simulation list tanka pushla
		}

		if (commands[i].find("fill_tank") != string::npos) {
			this->wait(1);
			//split fonksiyonla id ve lt elde edilcek
			splitString.doubleValues(commands[i]);
			int number1 = splitString.temporary[0];
			double number2 = splitString.temporary[1];
			//elde edilen id ve lt fill_tank fonskiyonu çağrılcak ve parametre olarak atancak fonksiyona
			fill_tank(number1, number2);
			//fill_tank fonk içinde id eşleşmesi yapılcak, eslesen tank id ile tankin yakıtı lt parametresi ile atancak
		}
		if (commands[i].find("connect_fuel_tank_to_engine") != string::npos) {
			this->wait(1);
			//split fonksiyonla id elde edilcek
			int number = splitString.values(commands[i]);
			//connect_fuel_tank_to_engine() fonksiyonu çağrılcak(Valve kontrol edilcek! Tank olup olmadığı kontrol edilcek.)
			connect_fuel_tank_to_engine(number);
			//connect_fuel_tank_to_engine() fonksiyonu içinde similasyondaki tank listesinde id eslesen tankı engine deki tank listesine pushlancak
		}
		if (commands[i].find("remove_fuel_tank") != string::npos) {
			this->wait(1);
			//split fonksiyonla id elde edilcek
			int number = splitString.values(commands[i]);
			//remove_fuel_tank fonk cağrılcak ( Tank olup olmadığı kontrol edilcek.)
			remove_fuel_tank(number);
			//remove_fuel_tank fonk , engine içindeki tank listesinden id esleseni remove et(Tank olup olmadığı kontrol edilcek.) ve simulasyondaki tank listesinden de remove et(Tank olup olmadığı kontrol edilcek.)
		}
		if (commands[i].find("disconnect_fuel_tank_from_engine") != string::npos) {
			this->wait(1);
			//split fonksiyonla id elde edilcek
			int number = splitString.values(commands[i]);
			//disconnect_fuel_tank_from_engine fonksiyonu cağır 
			disconnect_fuel_tank_from_engine(number);
			//disconnect_fuel_tank_from_engine fonk içinde, engine içindeki tank listesinden id esleseni remove et(Tank olup olmadığı kontrol edilcek.)
		}

		if (commands[i].find("give_back_fuel") != string::npos) {
			//split fonksiyonla quantity elde edileck
			//give_back_fuel fonk cagir  process
			this->wait(1);
		}

		if (commands[i].find("open_valve") != string::npos) {
			this->wait(1);
			//split fonksiyonla id elde edilcek
			int number = splitString.values(commands[i]);
			//open_valve fonksiyonu cagir 
			engine->getEngine()->openValveOperation(number);
			observer = new ObserverValve();
			subject->registerObserver(observer);
		}
		if (commands[i].find("close_valve") != string::npos) {
			this->wait(1);
			//split fonksiyonla id elde edilcek
			int number = splitString.values(commands[i]);
			//close_valve fonksiyonu cagir 
			engine->getEngine()->closeValveOperation(number);
		}
		if (commands[i].find("list_fuel_tanks") != string::npos) {
			this->wait(1);
			//list fuel tanks fonk cağir
			list_fuel_tanks();
		}
		if (commands[i].find("wait") != string::npos) {
			//split fonksiyonl süre elde edlicek
			int number = splitString.values(commands[i]);
			wait(number);
		}
		if (commands[i].find("print_fuel_tank_count") != string::npos) {
			this->wait(1);
			//print process
			print_fuel_tank_count();
		}
		if (commands[i].find("list_connected_tank") != string::npos) {
			//
			this->wait(1);
			this->engine->getEngine()->list_connected_tank();
		}
		if (commands[i].find("print_total_fuel_quantity") != string::npos) {
			//
			this->wait(1);
			this->engine->getEngine()->print_total_fuel_quantity();
		}
		if (commands[i].find("print_total_consumed_fuel_quantity") != string::npos) {
			//
			this->wait(1);
			print_total_consumed_fuel_quantity();
		}
		//stops simulation
		if (commands[i] == "stop_simulation;") {
			subject->notifyObservers();
			this->stop_simulation();
		}
	}
}
/**
 * @brief					: This function is used to get SplitString object .
 * @param Null 				: Null
 * @return					: splitString object of simulation class
 */
SplitString Simulation::getSplitString() const
{
	return splitString;
}
/**
 * @brief					: This function is used to set SplitString object into Simulation Class .
 * @param splitString 		: SplitString splitString
 * @return					: void
 */
void Simulation::setSplitString(SplitString splitString)
{
	this->splitString = splitString;
}
//Girilen zamana ve moturun durumuna göre bekleme ve yakit yakma
/**
 * @brief					: This function is used to wait and consume quantity which is given time also related to status of engine.
 * @param number 			: int number(time)
 * @return					: void
 */
void Simulation::wait(int number)
{
	double quantity = 0;
	double difference;
	double left_quantity;

	//gets fuel consume
	if (this->engine->getEngine()->getStatus())	//checks engine is opened or closed
	{
		quantity = this->engine->getEngine()->getFuel_per_second() * number;		//harcanacak yakıt, zamana göre
		difference = this->engine->getEngine()->getInternal().getFuel_quantity() - quantity; //harcanacak yakıtla internal tanktaki benzin arasındaki fark(geri kalan yakıt)

		if (difference < 20) {
			double default_quantity = 20;	//default yakıt(20'nin altındaki değerler için depodaki yakıt sabit 20 değerini alır)
			left_quantity = quantity - (this->engine->getEngine()->getInternal().getFuel_quantity() - 20); // diğer tanklardan alınması gereken yakıt miktarı
			engine->getEngine()->getInternal().setFuel_quantity(default_quantity); //internal tanka kalan yakıtın set edilmesi(default "20")
			setTotalConsumedFuel(getTotalConsumedFuel() + (quantity- left_quantity));
			engine->getEngine()->absorb_fuel(left_quantity);
			setTotalConsumedFuel(getTotalConsumedFuel() + left_quantity);
		}
		else {
			engine->getEngine()->getInternal().setFuel_quantity(difference); //internal tanka kalan yakitin set edilmesi
			setTotalConsumedFuel(getTotalConsumedFuel() + quantity);
		}
		
	}
}
/**
 * @brief					: This function print all information about the selected tank
 * @param id				: int id
 * @return 					: void
 */
void Simulation::print_tank_info(int id)
{
	for (auto const& i : engine->getEngine()->getListTank()) {
		if (i.getId() == id) {
			string message = "Tank ID: " + to_string(i.getId()) + " Information: \n" + "Capacity: " +
				to_string(i.getCapacity()) + "\tFuel quentity: " + to_string(i.getFuel_quantity()) +
				"\tBroken status: " + to_string(i.getBroken()) + "\n";
			this->write.write_file(message);
		}
	}
}
/**
 * @brief					: This function that repairs the selected fuel tank
 * @param id				: int id
 * @return 					: void
 */
void Simulation::repair_fuel_tank(int _id)
{
	bool broken;
	bool hasTank = false;
	string message;
	try
	{
		for (Tank& tank : this->tank_list) {
			if (tank.getId() == _id) { // eslesen id var mi yok mu kontrol
				hasTank = true; // istenen tank listede var 
				broken = false;
				if (tank.getBroken())
					tank.setBroken(broken);
				else {
					throw message = "Tamir edilmek istenen" + to_string(_id) + " daha önce tamir edilmiş veya bozulmamış...!\n"; // hata mesaji=
				}

			}
		}
		if (hasTank == false) { // eger istenilen id de tank yoksa hata mesaji yazdır
			throw message = "Tamir edilmek istenen" + to_string(_id) + " numarali tank bulunamadi...!\n"; // hata mesaji
		}
	}
	catch (string message)
	{
		write.write_file(message);
	}
}
/**
 * @brief					: This function that brokes the selected fuel tank
 * @param id				: int id
 * @return 					: void
 */
void Simulation::break_fuel_tank(int _id) 
{
	bool broken;
	bool hasTank = false;
	string message;
	try
	{
		for (Tank& tank : this->tank_list) {
			if (tank.getId() == _id) { // eslesen id var mi yok mu kontrol
				hasTank = true; // istenen tank listede var 
				broken = true;
				if (!tank.getBroken())
					tank.setBroken(broken);
				else {
					throw message = "Bozulmak istenen" + to_string(_id) + " numarali tank zaten bozuk...!\n"; // hata mesaji=
				}
			}
		}
		if (hasTank == false) { // eger istenilen id de tank yoksa hata mesaji yazdır
			throw message = "Bozulmak edilmek istenen" + to_string(_id) + " numarali tank bulunamadi...!\n"; // hata mesaji
		}
	}
	catch (string message)
	{
		write.write_file(message);
	}
}
