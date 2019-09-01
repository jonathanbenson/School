#pragma once

#include "Employee.h"

class MonthlyEmployee : public Employee {

private :

	
	int rank;

public :

	int get_rank() const;

	bool set_rank(int r);

	virtual string type() const;

	virtual void read_data(istream& is);
	virtual void write_data(ostream& os);


};