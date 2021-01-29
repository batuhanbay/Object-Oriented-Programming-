#pragma once
#include<vector>
#include<string>
#include <fstream>

using namespace std;
/**
* @brief	: Created a class for reading input file.
*/
class Read
{
public:
	Read();
	Read(string);
	~Read();
	void read_file();
	vector<string> getCommands() const;
private:
	vector<string> commands;
	string filePath;
};
