
#include "bank.h"
using namespace std;


choice menu() {
	// prints a menu, and gets and returns a valid choice from the user

	cout << endl;

	char c;

	while (true) {

		cout << "1. Print all customers data" << endl;
		cout << "2. Print names and IDs" << endl;
		cout << "3. Print accounts total" << endl;
		cout << "4. Enter q/Q to quit" << endl << endl;

		cout << "Enter your choice or q/Q to quit. ";

		cin >> c;

		switch (toupper(c)) {

		case '1':

			return ALL;

		case '2':

			return NAMES_IDS;

		case '3':

			return ACCOUNTS;

		case 'Q':

			return QUIT;

		default:
			// if the user enteres anything besides 1, 2, 3, or q/Q... output an error message
			cout << "Error. Please choose 1, 2, 3, or q/Q." << endl << endl;
			break;

		}

	}


}


void get_lines(const string& FILE_NAME, vector<string>& lines) {
	// populates a vector full of the lines (as strings) of the file

	ifstream reader;

	reader.open(FILE_NAME);

	// if the file fails to open, output an error message and exit the program
	if (reader.fail()) {

		cout << "Error. " << FILE_NAME << " could not be opened." << endl;
		exit(1);
	}

	char c = '\n';

	// populate the vector of strings with the lines of the file
	while (!reader.eof()) {

		if (c == '\n') {

			lines.push_back(string());

		}
		else {

			lines.at(lines.size() - 1) += c;

		}

		reader.get(c);

	}

	// close the file when done extracting information
	reader.close();


}

void parse_lines(vector<string>& lines, vector<int>& ids, vector<string>& firsts, vector<string>& lasts, vector<double>& savings, vector<double>& checkings) {
	// from the lines of the file, it extracts each of the people's ids, names, checking and saving acounts
	// ...and stores them in their own corrosponding vectors
	// it assumes that each of the lists of items (ids, names, etc.) are all the same size

	int i;

	int id;
	string first, last;
	double saving, checking;


	
	for (i = 0; i < lines.size(); ++i) {

		istringstream line(lines.at(i));

		line >> id >> first >> last >> saving >> checking;

		ids.push_back(id);
		firsts.push_back(first);
		lasts.push_back(last);
		savings.push_back(saving);
		checkings.push_back(checking);

	}

}

void output(vector<int>& ids, vector<string>& firsts, vector<string>& lasts, vector<double>& savings, vector<double>& checkings) {
	// assumes all of the vectors passed all have the same size
	// outputs the accounts' ids, first names, last names, savings accounts, checkings accounts

	cout << endl;

	int i;
	const int W = 20;

	cout << left << setw(W) << "ID";
	cout << setw(W) << "First";
	cout << setw(W) << "Last";
	cout << setw(W) << "Savings Account";
	cout << setw(W) << "Checkings Account";
	cout << endl;

	for (i = 0; i < ids.size(); ++i) {

		cout << left << setw(W) << ids.at(i);
		cout << setw(W) << firsts.at(i);
		cout << setw(W) << lasts.at(i);
		cout << fixed << setprecision(2) << setw(W) << savings.at(i);
		cout << setw(W) << checkings.at(i);
		cout << endl;

	}

}

void output(vector<int>& ids, vector<string>& firsts, vector<string>& lasts) {
	// outputs the accounts' ids, first names, and last names

	cout << endl;

	int i;
	const int W = 20;

	cout << left << setw(W) << "ID";
	cout << setw(W) << "First";
	cout << setw(W) << "Last";
	cout << endl;

	for (i = 0; i < ids.size(); ++i) {

		cout << left << setw(W) << ids.at(i);
		cout << setw(W) << firsts.at(i);
		cout << setw(W) << lasts.at(i);
		cout << endl;

	}

}



void output(vector<double>& savings, vector<double>& checkings) {
	// outputs the accounts' savings accounts, and checkings accounts
	cout << endl;

	int i;
	const int W = 20;

	cout << left << setw(W) << "Savings Account";
	cout << setw(W) << "Checkings Account";
	cout << endl;

	for (i = 0; i < savings.size(); ++i) {

		cout << fixed << setprecision(2) << setw(W) << savings.at(i);
		cout << setw(W) << checkings.at(i);
		cout << endl;

	}

}