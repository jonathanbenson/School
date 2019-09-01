#pragma once

#include <fstream>
#include <string>
using namespace std;

class Employee {

private:

	string name, id;

public:

	string get_name() const;
	string get_id() const;

	void set_name(string n);
	void set_id(string i);

	virtual string type() const = 0;
	virtual void read_data(istream& is) = 0;
	virtual void write_data(ostream& os) = 0;

};
