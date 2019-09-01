#pragma once

#include "Shape.h"

class Circle : public Shape {

public:

	Circle() {
		len = 0;
	}

	friend ostream& operator<<(ostream& output, const Circle& shape);
	friend istream& operator>>(istream& input, Circle& shape);

	double area() const;



};