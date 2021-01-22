#include<iostream>
#include<stdlib.h>
#include <fstream>


using namespace std;

/*! \mainpage  Lab Assigment 1
 *  \brief     Read given values from the .txt file and implement some operations by using various functions.
 *  \details   The code has been written evaluate  sum , product , min number and average of the array which is written in the file than prin the results to log.
 *  \author    Mustafa Batuhan Bayoglu
 *  \version   1.0
 *  \date      04.11.2020
 *  \pre       First initialize the system.
 *  \warning   Improper use can crash  application
 *  \copyright GNU Public License.
 */


 /**
  * @brief                    : This function is used to evaluate sum of values which is written in the txt file.
  * @param values,row         : Values and row to evaluate sum of values in the file
  * @return result            : Sum of the values
  */

double  sum(double* values, double row) {
    double result = 0;
    for (int i = 0; i < row; i++)
    {
        result += *values;
        values++;
    }
    return result;
}

/**
  * @brief                    : This function is used to evaluate product of values which is written in the txt file.
  * @param values,row         : Values and row to evaluate product of values in the file
  * @return result            : Product of the values
  */
double product(double* values, double row) {
    double result = 1;
    for (int i = 0; i < row; i++)
    {
        result *= *values;
        values++;
    }
    return result;

}
/**
  * @brief                    : This function is used to evaluate average of values which is written in the txt file.
  * @param values,row         : Values and row to evaluate average  in the file
  * @return result            : Average of the values
  */
double average(double* values, double row) {
    double result;
    result = sum(values, row) / row;
    return result;
}
/**
  * @brief                    : This function is used to evaluate smallest values which is written in the txt file.
  * @param values,row         : Values and row to evaluate smallest values in the file
  * @return result            : Smallest number
  */
double smallest(double* values, double row) {
    double min = *values;
    for (int i = 0; i < row; i++)
    {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}
/**
  * @brief                    : This function is used to open the file if it is exist and check it out if there is any mistake for given values.After all print the result to log
  * @param mainFile           : The file which is type of .txt file , will be pass into this declaration value which is type of ifstream 
  */
void inputfile(ifstream& mainFile)
{
    double row = -1;
    double* values;
    int i = 0;
    int counter = 0;
    mainFile.open("input.txt");
    if (!mainFile)
    {
        cout << "--->WARNING!" << "--->Message:Can not open file!" << endl;
        exit(1);
    }

    mainFile >> row;
    if (row == -1) {
        cout << endl << "--->WARNING!" << "--->Message:FILE IS EMPTY.Could not find out any value for size of array and values of array! Please assign the values to file" << endl;
    }//end-if
    else {

        values = new double[row];
        while (!mainFile.eof()) { // keep reading until end-of-file

            mainFile >> values[i++]; //assign the value
            counter++;
        }//end process of assigning values to array

        if (counter < row || counter > row)//check if there is extra value or missing value compare to size of array
        {
            cout << endl << "--->WARNING" << endl << "--->Message:Something went wrong.There is one missing or extra value in the Array! Please check size of array and set to numbers based on size!" << endl;
            mainFile.close();
            exit(1);
        }
        else {
            //Start print to console results
            cout << "Sum: " << sum(values, row) << endl;
            cout << "Product: " << product(values, row) << endl;
            cout << "Average: " << average(values, row) << endl;
            cout << "Smallest: " << smallest(values, row) << endl;
            //End print to console results
        }
        mainFile.close();
    }

}
/**
  * @brief      : Main function is used to call the function which is to open and check file.
  */
void main() {
    ifstream indata;
    inputfile(indata);
}