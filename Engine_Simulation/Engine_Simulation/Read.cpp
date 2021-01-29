#include "Read.h"
#include <iostream>
using namespace std;
Read::Read()
{
}
/**
 * @brief					: This function is constructor.
 * @param filePath			: Path of file.
 */
Read::Read(string filePath)
{
	this->filePath = filePath;
}

Read::~Read()
{
}
/**
 * @brief					: This function is used to read 'input.txt'.
 * @param					: Null
 * @return					: void
 */
void Read::read_file()
{
	ifstream in_file;
	int flag = 0;
	in_file.open(this->filePath.c_str(), ios::in);
	if (in_file.is_open()) {
		string command;
		//reads .txt file line by line, 
		while (getline(in_file, command)) {
			//push the lines to vector string
			if (command == "start_engine;") {
				flag++;
			}
			if (flag != 0) {
				this->commands.push_back(command);
			}
			if (command == "stop_simulation;") {
				break;
			}
		}
	}
	else {
		cout << "File cannot be opened." << endl;
		exit(0);
	}
}
/**
 * @brief					: This function is used to get commands
 * @param					: Null
 * @return this->commands	: returns read object's commands.
 */
vector<string> Read::getCommands() const
{
    return this->commands;
}
