
#include "HourlyEmployee.h"

char HourlyEmployee::get_expert_employee() const {

	return expert_employee;
}

int HourlyEmployee::get_salary() const {

	return salary;
}

string HourlyEmployee::type() const {

	return "Hourly Employee";
}

bool HourlyEmployee::set_expert_employee(char ep) {

	expert_employee = ep;
	return true;
}

bool HourlyEmployee::set_salary(double new_salary) {

	salary = new_salary;
	return true;
}

void HourlyEmployee::read_data(istream& is) {
	// reads an hourly employee's data from an input file

	string n, i;
	char ep;
	double sal;

	is >> n >> i >> ep >> sal;

	set_name(n);
	set_id(i);
	set_expert_employee(ep);
	set_salary(sal);

}

void HourlyEmployee::write_data(ostream& os) {
	// writes an hourly employee's information to an output file

	os << type() << endl;
	os << get_name() << endl;
	os << get_id() << endl;
	os << get_expert_employee() << endl;
	os << get_salary() << endl;


}