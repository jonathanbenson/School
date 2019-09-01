
#include <iostream>
#include "Month.h"
using namespace std;

int Month::num_days() {
	// find out how many days are in the month based on which month it is

	// if the month's order number is an even number, then its days are 30
	// else if the month's order number is an odd number, then its days are 31
	// however, if the month is February (the second month), then its days are 28 for a non-leap year, else 29
	if ((month + 1) == 2)
		if (of_leap_year)
			return 29;
		else
			return 28;
	else
		if ((month + 1) % 2 == 0)
			return 30;
		else
			return 31;
	
}

