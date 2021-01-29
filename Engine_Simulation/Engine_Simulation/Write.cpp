#include "Write.h"
/**
 * @brief					: This function is constructor.
*/
Write::Write()
{
}
/**
 * @brief					: This function is destructor.
*/
Write::~Write()
{
}
/**
 * @brief					: This function is used to write string to output file.
 * @param write				: string that we want to write to output file.
 * @return 					: void
 */
void Write::write_file(string write)
{
	fstream outfile;
	outfile.open("output.txt", ios::app);
	outfile << write;
	outfile.close();
}
