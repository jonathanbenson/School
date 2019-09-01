
#include "MonthlyEmployee.h"

int MonthlyEmployee::get_rank() const {

	return rank;

}

bool MonthlyEmployee::set_rank(int r) {
	// sets an employees rank to a rank given if its rank is between 1 and 10

	if (rank >= 1 && rank <= 10) {

		rank = r;
		return true;

	}

	return false;
}

string MonthlyEmployee::type() const {

	return "Monthly Employee";

}

void MonthlyEmployee::read_data(istream& is) {
	// reads a monthly employee's data from the input file

	string n, i;
	int r;

	is >> n >> i >> r;

	set_name(n);
	set_id(i);
	set_rank(r);

}

void MonthlyEmployee::write_data(ostream& os) {
	// writes a monthly employee's data to an output file

	os << type() << endl;
	os << get_name() << endl;
	os << get_id() << endl;
	os << get_rank() << endl;

}