#pragma once
#include<iostream>
#include <string>
#include<sstream>
#include <vector>
using namespace std;
/**
* @brief	: Created a class for splitting string.
*/
class SplitString
{
public:
	vector<double> temporary;
	SplitString();
	~SplitString();
	double values(string);
	void doubleValues(string command);
};