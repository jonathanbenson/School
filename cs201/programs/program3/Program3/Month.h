#pragma once

#include <string>
#include <vector>
using namespace std;

// for convenience in settting values later in the program
const string MONTHS[12] = { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };
const string DAYS[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

class Month {

private :

	int month;
	int starting_day;

	bool of_leap_year;

public :

	Month(int m, int s, bool oly) {

		month = m;
		starting_day = s;
		of_leap_year = oly;

	}
	
	int num_days();

	int get_starting_day() {
		return starting_day;
	}
	string name() {	return MONTHS[month]; }
};
