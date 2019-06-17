
// strings and streams notes cpp


// ostream, short for "output stream"
// is a class that supports output

#include <iostream> // the library that deals with output streams

using namespace std; // the namespace where output stream items are defined like std::cout and std::endl

int main() {

	// << is an overloaded operator known as the insertion operator
	cout << "Hello World!" << endl;
	//is the same thing as...
	
	(cout.operator<<("Hello World!")).operator<<(endl);



	return 0;
}

// istream and cin streams
// a class that supports input

#include <iostream>

using namespace std;


int main() {

	int a, b;
	
	// >> is an overloaded operator known as the insertion operator
	// will ignore all preceding whitespace and once encountering whitespace, move onto storing the next variable
	cin >> a >> b; // user enteres " 1 4 ", a = 1, b = 4

		

	return 0;
}



// file input and output

#include <iostream>
#include <fstream> // file stream class

using namespace std;


int main() {
	
	ifstream reader; // declaration of a ifstream object

	// establishes a stream or connection with a PRE-EXISTING file in the CWD named example.txt
	reader.open("example.txt");

	if (!reader.is_open()) {

		cout << "example.txt could not be opened." << endl;

	}

	int number_in_file;

	// reads a number in the file and assigns it to a variable
	reader >> number_in_file;

	// ALWAYS close the file when done
	reader.close();

	return 0;

}


// reading in all the characters from a file into a vector


#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>


using namespace std;

void output(vector<vector<char>>& lines);

int main() {

	vector<vector<char>> lines;

	ifstream reader;

	reader.open("example.txt");
	
	if (reader.fail()) {

		cout << "Error. The file could not be opened." << endl;
		exit(1);
	}

	char c = '\n';

	while (!reader.eof()) {
		
		if (c == '\n') {

			lines.push_back(vector<char>());

		}
		else {

			lines.at(lines.size() - 1).push_back(c);

		}

		reader.get(c);

	}


	output(lines);

	reader.close();
	return 0;

}


void output(vector<vector<char>>& lines) {
	
	int i , j;

	for (i = 0; i < lines.size(); i++) {

		for (j = 0; j < lines.at(i).size(); j++) {
			
			cout << lines.at(i).at(j);

		}

		if (i < lines.size() - 1) cout << endl;
	}
}



// ofstream

#include <fstream>
#include <cstring>

using namespace std;

int main() {

	char name[] = "Jonathan Benson";

	ofstream writer;

	writer.open("example2.txt");

	if (writer.fail()) {

		cout << "Error. File could not be opened." << endl;
		exit(1);
	}


	int i;

	for (i = 0; name[i] != '\0'; i++) {

		ofstream.put(name[i]);

	}

	writer.close();	
	

	return 0;

}


// output formatting

#include <iostream>
#include <ios>
#include <iomanip>

// ios::fixed - use fixed-point notation
// ios::scientific - use scientific notation
// iomanip::setprecision(p)
// ios::showpoint

// iomanip::setw(n) - sets the number of characters for the next output item only, by default, the item will be right-aligned, and filled with spaces
// iomanip::setfill(c) - sets the fill character c
// ios::left - changes to left alignment
// ios::right - changes back to right alignment

// std::endl
// std::flush - informs the system to flush the buffer
int main() {


	const double PI = 3.14159;
	const double e = 2.718281;
	std::cout << ios::setprecision(3) << PI << std::endl; // 3.14
	std::cout << e << std::endl; // 2.71...the setprecision is persistent

	std::cout << ios::fixed << ios::setprecision(3) << PI << std::endl; // 3.142
	
	std::cout << iomanip::setfill('*') << iomanip::left;
	std::cout << iomanip::setw(6) << "Bob" << std::endl;
	std::cout << iomanip::setw(6) << "Fred" << std::endl;
	
	// output...
	// Bob***
	// Fred**
	return 0;

}



// sstream (string stream)

#include <sstream>
#include <string>
using namespace std;

int main() {
	
	// istringstream
	string info = "Jonathan Benson 20";
	istringstream inSS(info);

	string first;
	string last;
	int age;

	inSS >> first;
	inSS >> last;
	inSS >> age;

	inSS.clear();

	string moreinfo = "Billy Bob 35";

	inSS.str(moreinfo);

	inSS >> first;
	inSS >> last;
	inSS >> age;

	// ostringstream
	
	ostringstream oSS;

	string fullName;

	string last = "Benson";
	string first = "Jonathan";
	
	oSS << last << ", " << first;

	fullName = oSS.str();




	return 0;
}


// stream errors
// good() returns true if no stream errors have occured
// eof() returns value of eofbit, if end-of-file reached on extraction
// fail() returns true if either failbit or bad bit is set, indicating an error for the previous stream operation
// bad() returns true if badbit is set, indicating the stream is bad

// clear() clears the error state from cin

// ignoring maximum number of characters for cin

cin.ignore(numeric_limits<streamsize>::max() , '\n');

// extraction before getline

#include <iostream>
#include <string>
using namespace std;


int main() {

	int age;
	string line;

	cin.ignore(1 , '\n');

	cin >> age;
	getline(cin , line);

	return 0;
}


