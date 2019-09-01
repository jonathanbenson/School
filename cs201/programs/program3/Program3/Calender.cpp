
#include <iostream>
#include <iomanip>
#include <ios>
#include "Calender.h"
#include "Month.h"
using namespace std;

bool Calender::is_leap() const {
	// returns if the year of the calender is a leap year or not
	
	// if the year is evenly divisible by 4, it is a leap year unless...
	// it is evenly divisible by 100 and NOT evenly divisible by 400
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}

		return true;
	}
	else {
		return false;
	}

}

void Calender::gen() {
	// generates a calender by populating a member variable containing a vector of objects

	int i, sd = starting_day;

	for (i = 0; i < 12; ++i) {
		
		months.push_back(Month(i, sd, is_leap()));

		sd += months.at(i).num_days();

		// reset the starting day
		sd %= 7;

	}


}

void Calender::output() {
	// output the calender to the console

	int i, j, k, l;

	Month* m;

	for (i = 0; i < months.size(); ++i) {

		m = &months.at(i);

		// output the month name and year
		cout << m->name() + " " + to_string(year) << endl;

		// output the days of the week
		for (j = 0; j < 7; ++j)
			cout << DAYS[j] << ' ';
		cout << endl;


		// output all of the days
		l = m->get_starting_day() + 1;

		for (k = 0; k < l - 1; k++)
			cout << "    ";

		for (k = 1; k <= m->num_days(); ++k) {

			// ...formatting...
			if (k < 10)
				cout << "  " << k;
			else
				cout << ' ' << k;

			cout << ' ';

			// ...insert newlines when appropriate
			if (l == 7) {
				cout << endl;
				l = 0;
			}

			l++;

		}

		cout << endl << endl;

	}


}