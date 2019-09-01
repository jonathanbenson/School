
#include "Square.h"

ostream& operator<<(ostream& output, const Square& square) {
	// outputs the square to the console

	output << "Square | Side length: " << square.len << " | Area: " << square.area();

	return output;
}

istream& operator>>(istream& input, Square& square) {
	// gets the square's side length from the user
	// assumes the user will not enter anything besides a double value

	while (true) {

		try {

			input >> square.len;

			if (square.len < 0.0)
				throw runtime_error("Error. Please enter a value greater than 0.");

			return input;

		}
		catch (runtime_error& e) {

			input.clear();
			cout << e.what() << endl;
			

		}
	}
}

double Square::area() const {
	// gets and returns the area of the square

	return len * len;

}