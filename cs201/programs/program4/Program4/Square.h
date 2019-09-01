#pragma once

#include "Shape.h"

class Square : public Shape {


public :

	Square() {
		len = 0;
	}

	friend ostream& operator<<(ostream& output, const Square& square);
	friend istream& operator>>(istream& input, Square& square);

	double area() const;



};