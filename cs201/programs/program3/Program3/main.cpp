
#include <iostream>
#include "Calender.h"
#include "module.h"
using namespace std;


int main() {

	int year, starting_day;
	
	// get both the year and the starting day of the week for the calender
	year = get_year();
	starting_day = get_starting_day();

	Calender cal(year, starting_day); // initialize a calender given the year and starting day of the week

	cal.gen(); // generate a calender
	cal.output(); // output the calender


	return 0;
}