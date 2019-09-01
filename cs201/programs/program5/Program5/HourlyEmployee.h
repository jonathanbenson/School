#pragma once

#include "Employee.h"

class HourlyEmployee : public Employee {

private :

	int salary;
	char expert_employee;
	
public :

	char get_expert_employee() const;
	int get_salary() const;
	virtual string type() const;

	bool set_expert_employee(char ep);
	bool set_salary(double new_salary);

	virtual void read_data(istream& is);
	virtual void write_data(ostream& os);


};

