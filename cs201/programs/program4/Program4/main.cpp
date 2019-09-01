
// Jonathan Benson
// jbbg9b@mail.umkc.edu
// 7/11/2019
// cs201 Program 4


#include <iostream>
#include "Circle.h"
#include "Square.h"
using namespace std;

int main() {

	// declare a square and circle object for the program
	Square s;
	Circle c;

	// get the square's radius
	cout << "Enter the side length for a square >>> ";
	cin >> s;

	// get the circle's radius
	cout << "Enter the radius for a circle >>> ";
	cin >> c;

	// output the square and the circle to the console
	cout << s << endl;
	cout << c << endl;

	return 0;
}