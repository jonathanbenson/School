
#include "module.h"

string upper(string s) {
	// takes a string and returns a string all uppercase

	int i;

	for (i = 0; i < s.size(); ++i)
		s.at(i) = toupper(s[i]);

	return s;

}

int get_year() {
	// gets a valid year from the user
	// the year must be between 1000 and 9999 inclusive

	int year;

	while (true) {

		try {

			cout << "Enter year (must be in range 1000 <= Year <= 9999): ";

			cin >> year;

			if (year < 1000 || year > 9999 || cin.fail())
				throw runtime_error("The year must be an integer between 1000 and 9999.");

			return year;
		}
		catch (runtime_error& e) {

			cout << e.what() << endl;

		}
	}
}

int get_starting_day() {
	// gets a starting day from the user
	// must be a week or weekend day name (case non-sensitive)

	string day;

	while (true) {

		try {

			cout << "What day of the week does Jan 1 fall on this year? ";

			cin >> day;

			if (upper(day) == "SUNDAY")
				return 0;
			else if (upper(day) == "MONDAY")
				return 1;
			else if (upper(day) == "TUESDAY")
				return 2;
			else if (upper(day) == "WEDNESDAY")
				return 3;
			else if (upper(day) == "THURSDAY")
				return 4;
			else if (upper(day) == "FRIDAY")
				return 5;
			else if (upper(day) == "SATURDAY")
				return 6;
			else
				throw runtime_error("Error. ");

		}
		catch (runtime_error& e) {

			cout << e.what() << endl;

		}
	}


}