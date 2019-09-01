
// Jonathan Benson
// cs201
// Program 5
// 7/17/19

#include<vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "MonthlyEmployee.h"
using namespace std;

int main() {

	// file names
	const string INPUT_FILE = "input.txt";
	const string OUTPUT_FILE = "output.txt";

	// array of employee pointers to hold the employees
	Employee* employees[100];


	int i;

	// initialize all of the employee pointers to nullptr
	for (i = 0; i < 100; ++i)
		employees[i] = nullptr;


	
	ifstream reader;
	ofstream writer;

	// establish input and output file streams
	reader.open(INPUT_FILE);
	writer.open(OUTPUT_FILE);

	// make sure the streams are working correctly
	if (reader.fail() || writer.fail()) {

		cout << "Error. The files could not be opened." << endl;
		exit(1);

	}

	int count = 0;
	char e;

	// extract the employee information from the file
	while (!reader.eof()) {

		// late binding will allow the determination for which function to be called in reading the file
		reader >> e;

		if (e == 'H') {
			// if the character read is H, then this is an hourly employee

			employees[count] = new HourlyEmployee; // create a new hourly employee pointer in the array
			employees[count]->read_data(reader); // read the hourly employee's data
			
		}
		else if (e == 'M') {
			// if the character read is M, then this is a monthly employee

			employees[count] = new MonthlyEmployee; // create a new monthly employee pointer in the array
			employees[count]->read_data(reader); // read the monthly employees data
			
		}
		else {
			// for the developer in case the file has any lines that contain invalid format

			cout << "The input file may be corrupted." << endl;
		}

		count++;

	}

	// write all of the hourly employees' data to the output file
	for (i = 0; i < count; i++)
		if (employees[i]->type() == "Hourly Employee")
			employees[i]->write_data(writer);

	// write all of the monthly employees' data to the output file
	for (i = 0; i < count; i++)
		if (employees[i]->type() == "Monthly Employee")
			employees[i]->write_data(writer);

	// free all of the memory holding all of the employees' data
	for (i = 0; i < 100; ++i)
		delete employees[i];

	// close both file streams
	reader.close();
	writer.close();


	return 0;
}