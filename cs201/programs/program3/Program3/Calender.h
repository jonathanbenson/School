#pragma once

#include <vector>
#include "Month.h"
using namespace std;


class Calender {

private :

	int starting_day;
	int num_days;

	int year;

	vector<Month> months;

	bool is_leap() const;

public :

	Calender(int y, int sd) {

		num_days = 0;
		year = y;
		starting_day = sd;

		
	
	}

	int size() {
		return months.size();
	}

	int get_starting_day() {
		return starting_day;
	}

	void gen();

	void output();


};