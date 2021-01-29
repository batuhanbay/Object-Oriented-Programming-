#include<iostream>
#include"Engine.h"
#include"Read.h"
#include"Simulation.h"
#include"Tank.h"
#include"Valve.h"
#include"Write.h"
#include"EngineSingleton.h"
using namespace std;
/*! \mainpage  Take Home 4
 *  \brief     Declerate and implement simulation.
 *  \author    Yasemin Gerboga (152120171056), Mustafa Batuhan Bayoğlu (1521202171002), Mustafa Harun Türkmenoğlu (152120171059), Zorbey Çelik(152120191094)
 *  \date      9 December 2020
 */
int main() {
	EngineSingleton* engine = EngineSingleton::getInstance();
	Read read("input.txt");
	Simulation simulation(read,engine);
	simulation.read.read_file();
	simulation.fileOperations(simulation.read.getCommands());
	return 0;
}