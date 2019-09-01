#pragma once

#include <iostream>
using namespace std;

class Shape {

protected :

	double len;

public :

	virtual double area() const = 0;

};