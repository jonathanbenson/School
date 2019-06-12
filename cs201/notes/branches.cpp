
//branches notes for c++


// a branch is a program path taken only if an expression's value it true

#include <iostream>
#include <string>

//relationall operators
//== , != , < , > , <= , >=

//branches

int main()
{
	int hours;

	std::cout << "Enter in how many hours per week you work ==> ";
	std::cin >> hours;


	// the boolean expressions of branches are wrapped in ()
	// the bodies of branches are wrapped in {}
	
	if (hours > 39)
	// if the boolean expression within the () evaluates to anything but 0, it will execute the statements within the following body of the branch, else will be ignored
	{
		std::cout << "You work full-time." << std::endl;
	}
	else if (hours > 0)
	// if the previous branch's expressions evaluate to 0, and this branch's expression evaluates to anything but 0, it will execute the code within the following body of the branch, else will be ignored
	{
		std::cout << "You work part-time." << std::endl;
	}
	else if (hours == 0)
	// if all the previous branches' expressions evaluate to 0, and this branch's expression evaluates to anything but 0, then the code within this branch's body will execute, else will be ignored
	{
		std::cout << "You are unemployed." << std::endl;
	}
	else
	// if all the previous branches' expressions evaluate to 0, then this branch's code will execute, else will be ignored
	{
		std::cout << "Error." << std::endl;
	}

	// one statement branches
	
	int age;

	std::cout << "Enter your age ==> ";
	std::cin >> age;

	if (age > 64)
	// {} may be omitted if and only if there is only one statement within the body
		std::cout << "You are a senior." << std::endl;
	else if (age > 18)
		std::cout << "You are an adult." << std::endl;
	else if (age > 9)
		std::cout << "You are a teenager." << std::endl;
	else if (age > 0)
		std::cout << "You are a child." << std::endl;
	else
		std::cout << "Error." << std::endl;


	//nested if-else statements
	
	//distinct if statements
	
	int year;

	std::cout << "Please enter the year of your car ==> " << std::endl;
	std::cin >> year;
	
	//these if statements will each execute if their expressions evaluate to anything but 0
	if (year < 1967)
		std::cout << "Probably has a few safety features." << std::endl;
	if (year > 1971)
		std::cout << "Probably has head rests." << std::endl;
	if (year > 1992)
		std::cout << "Probably has anti-lock brakes." << std::endl;
	if (year > 2000)
		std::cout << "Probably has a tire-pressure monitor." << std::endl;
	if (year > 2010)
		std::cout << "Probably has a touch-screen." << std::endl;

	return 0;
}

//bool, boolean expressions, equality and relational operators

int main()
{
	bool a = true; // true evaluates to 1
	bool b = false; // false evaluates to 0

	// a boolean expression is an expression that evaluates to a boolean value (either 1 or 0)
	
	// equality operators
	// == , !=
	// ***for operators that are composed of multiple characters, whitespace is not allowed between the characters
	
	bool c = (5 == 5); // true
	bool d = (4 != 10); // true

	// comparing characters compares their ASCII numerical encoding
	// floating-point types should not be compared using the equality operators due to the imprecise representation of floating-point numbers, as discussed in a later section
	// Strings are equal if they have the same number of characters and corresponding characters are identical
	// comparing strings relationally, their corrosponding ASCII unicode numbers are compared in sequence from left to right	
	// if two strings are equal up to a character, but one string is longer, the longer string will be greater in value
	

	// relational operators
	// < , > , <= , >=
	
	bool e = 5 < 10; // true
	bool f = 10 > 5; // true
	bool g = 5 <= 5; // true
	bool h = 5 >= 5; // true



	// assignment operator in a branch expression
	
	int value = 0;

	if (value = 1) // value gets assigned to 1, and the expression evaluates to 1
		value = value + 1;

	std::cout << value; // this will output 2



	return 0;

}


// logical operators
// a logical operator's operands are true or false (1 or 0), and evaluates to true or false (1 or 0)
// && (and) , || (or) , ! (not)

int main() {
	
	// &&
	// only evaluates to true if both operands evaluate to true, else false
	
	bool a = true && true; // true
	bool b = true && false; // false
	bool c = false && true; // false
	bool d = false && false; // false

	// ||
	// only evaluates to false if both operands evaluate to false, else true
	
	bool e = true || true; // true
	bool f = true || false; // true
	bool g = false || true; // true
	bool h = false || false; // false
	
	// !
	
	bool i = !true; // false
	bool j = !false; // true
	

	// precedence rules
	// () , ! , */%+- , < <= > >= , == != , && , ||
	// acronym PARL = Parenthesis, Arithmetic, Relational

	return 0;
}


// switch statements

int main()
{
	int value;

	std::cout << "Please enter a number between 0 and 2 ==> " << std::endl;
	std::cin >> value;
	
	// switch statement will evaluate each case, and if true, execute the code within the case block
	
	// the break statement will break out of the entire switch statement
	// the default case will automatically execute if reached
	
	switch (value) {

		case 0 :

			std::cout << "You entered 0." << std::endl;
			break;

		case 1 :

			std::cout << "You entered 1." << std::endl;
			break;

		case 2 :

			std::cout << "You entered 2." << std::endl;
			break;

		default :

			std::cout << "You did not enter a number between 0 and 2." << std::endl;
			break;
		
		}

	// omitting the break statement
	// omitting the break statement for a case will cause the statements within the next case to be executed.
	
	int grade;

	std::cout << "Please enter your grade ==> ";
	std::cin >> grade;

	switch (grade) {

		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
			// if the user enters 1-5, the following code executes
			std::cout << "You are in lower school." << std::endl;
			break;

		case 6 :
		case 7 :
		case 8 :
			// if the user enters 6-8, the following code executes
			std::cout << "You are in middle school." << std::endl;
			break;

		case 9 :
		case 10 :
		case 11 :
		case 12 :
			// if the user enters 9-12, the following code executes
			std::cout << "You are in upper school." << std::endl;
			break;

		default :
			// if none of the previous cases evaluated to true, then the following executes
			std::cout << "You are not in school." << std::endl;
			break;
		}



	return 0;


}

// boolean
// true or false
int main() {
	
	bool a;
	
	// boolean expressions evaluate to either true or false (anything but 0 or 0)
	// they are composed of relational and logical operators
	bool b = true;
	bool c = false;
	bool d = 4 < 5; // true


	return 0;
}


// string access operations

#include <iostream>
#include <string>

int main() {

	// a string is a sequence of characters in memory
	// each character in the string has an index indicating its position
	// the first character's index in every string is 0
	
	string message = "Hello!";

	// string.at(int i) is a method that returns the character at index i
	// trying to access an index out of the range of the string will produce an error	
	std::cout << message.at(0);
	std::cout << message.at(1);
	std::cout << message.at(2);
	std::cout << message.at(3);
	std::cout << message.at(4);
	std::cout << message.at(5);

	// output...
	// Hello!
	
	// changing characters at specific indices of a string
	
	string name = "Jonathon Benson";
	std::cout << name << std::endl; // Jonathon Benson

	name.at(6) = 'a';
	std::cout << name << std::endl; // Jonathan Benson

	// changing multiple adjacent characters within a string
	
	string something = "123";
	std::cout << something << std::endl; // 123
	
	something.at(0) = "abc";
	std::cout << something << std::endl; // abc

	// determining size of a string
	
	string dog = "Mickey";

	std::cout << dog.size() << std::endl; // 6

	// appending characters to a string
	// string.append(string s)

	string another_message = "Hello World";
	another_message.append("!!!");
	std::cout << another_message << std::endl; // Hello World!!!

	// c-style index accessing with brackets
	
	string word = "doggo";
	std::cout << word[0];
	std::cout << word[1];
	std::cout << word[2];
	std::cout << word[3];
	std::cout << word[4];
	std::cout << word[5];

	// output...
	// doggo

	// more string operations
	
	string phrase = "Hello World!";

	std::cout << phrase.find('W') << std::endl; // 6
	std::cout << phrase.find("llo") << std::endl; // 2
	std::cout << phrase.find("asdf") << std::endl; // std::string::npos

	std::cout << phrase.substr(6 , 5) << std::endl; // World

	phrase.push_back('!');
	std::cout << phrase << std::endl; // Hello World!!

	phrase.insert(0 , "Hola Mundo!!!");
	std::cout << phrase << std::endl; // Hola Mundo!!!

	string sentence = "You have many gifts";
	sentence.replace(9 , 4 , "a plethora of"); // first number is starting inclusive, second is ending exclusive
	std::cout << sentence << std::endl; // You have a plethora of gifts

	string first = "Jonathan";
	string last = "Benson";
	std::cout << first + last << std::endl; // Jonathan Benson



	return 0;
}

// character functions

#include <cctype> // must include this library to use these character methods

int main() {

	char a = 'A';
	char b = '1';
	char c = ' ';
	char d = 'a';
	char e = 'A'

	std::cout << isalpha(a) << std::endl; // true
	std::cout << isdigit(b) << std::endl; // false
	std::cout << isspace(c) << std::endl; // true
	std::cout << toupper(d) << std::endl; // A
	std::cout << tolower(e) << std::endl; // a


	return 0;
}


// conditional expressions
// also referred to as a ternary operator

#include <iostream>
#include <string>
int main() {

	bool boolExpr = true;

	string example = boolExpr ? "boolExpr evaluated to true" : "boolExpr evaluated to false";
	
	std::cout << example << std::endl; // boolExpr evaluated to true

	return 0;
}

// floating point comparison

#include <iostream>
#include <cmath>

int main() {
	
	// when comparing floating point numbers, avoid equality operators (== , !=)
	
	double x = 5.0;

	if (fabs(x - 5.0) <= 0.001)
		std::cout << "x is equal to 5.0";
	else
		std::cout << "x is not equal to 5.0";
	
	std::cout << endl;

	return 0;
}


