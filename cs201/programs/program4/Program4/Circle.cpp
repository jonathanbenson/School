
// this statement is required to use mathematical constants from the cmath library
#define _USE_MATH_DEFINES

#include <cmath>
#include "Circle.h"


ostream& operator<<(ostream& output, const Circle& circle) {
	// outputs the circle to the console

	output << "Circle | Radius: " << circle.len << " | Area: " << circle.area();

	return output;
}

istream& operator>>(istream& input, Circle& circle) {
	// gets the circle's radius from the user
	// assumes the user will not enter anything besides a double value

	while (true) {

		try {

			input >> circle.len;

			if (circle.len < 0.0)
				throw runtime_error("Error. Please enter a value greater than 0.");

			return input;

		}
		catch (runtime_error& e) {
			
			input.clear();
			cout << e.what() << endl;

		}
	}

	
}

double Circle::area() const {
	// gets and returns the area of the circle

	return M_PI * pow(len, 2);

}