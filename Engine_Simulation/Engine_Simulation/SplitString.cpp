#include "SplitString.h"
#include <vector>
/**
 * @brief					: This function is constructor.
*/
SplitString::SplitString()
{
}
/**
 * @brief					: This function is destructor.
*/
SplitString::~SplitString()
{
}
/**
 * @brief					: This function is used to split string by single spaces
 * @param command			: string that we want to split
 * @return stod(s)      	: returns double number
 */
double SplitString::values(string command)
{
    istringstream ss(command);
    string s;
    getline(ss, s, ' ');
    while (getline(ss, s, ' ')) {
        return stod(s);
    }
}
void SplitString::doubleValues(string command)
{
    vector<double> temp;

    istringstream ss(command);
    string s;
    getline(ss, s, ' ');
    while (getline(ss, s, ' ')) {
        temp.push_back(stod(s));
    }
    temporary = temp;
}