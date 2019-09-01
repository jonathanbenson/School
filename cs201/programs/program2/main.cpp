
#include "bank.h"
using namespace std;

int main() {

	// this program assumes the input file name to be "input.txt"
	const string FILE_NAME = "input.txt";
	vector<string> lines;

	// ids, first names, last names, savings accounts, checking accounts
	vector<int> ids;
	vector<string> firsts, lasts;
	vector<double> savings, checkings;
	
	// get the lines of the file and store them in a vector as strings
	get_lines(FILE_NAME, lines);

	// extract each item from the lines of the file and store them in their corrosponding vectors
	parse_lines(lines, ids, firsts, lasts, savings, checkings);

	choice c;

	do {

		// get a choice from the user on what to output from the data
		c = menu();

		// ALL, NAMES_IDS, ACCOUNTS, QUIT

		switch (c) {

		case ALL :
			
			// output all of the information
			output(ids, firsts, lasts, savings, checkings);
			break;

		case NAMES_IDS :

			// output only the ids, first and last names
			output(ids, firsts, lasts);
			break;

		case ACCOUNTS :

			// outputs only the saving and checking accounts
			output(savings, checkings);
			break;

		case QUIT :

			// quit the program
			break;

		default :

			// for the developer, in which case the menu() function is not working
			cout << "FIXME: menu()" << endl;
			break;

		}


	} while (c != QUIT);


	return 0;
}



