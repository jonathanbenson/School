
// functions notes

// user defined functions

// it is common practice to declare functions above the main function...
// define functions below the main function...
// and call functions inside of other functions between the declaration and the definition

#include <iostream>

// function declaration
void example();


int main() {
	
	// function call
	// a function must be defined before it is called
	example();

	return 0;
}



// function definition
// all functions must be declared before they are defined
void example() {
	// FIXEME this is a function stub
	
	// block of statements
	std::cout << "Hello from example!" << std::endl;
}





// parameters and arguments

#include <iostream>
#include <string>


// a parameter is a function input specified in a function definition
// an argument is a value passed to a function's parameter in a function call

void output(string message); // function declaration with string parameter message

int main() {

	output("Hello World!"); // function call with "Hello World!" as a string argument

	string m = "Welcome to the Program!";
	output(m); // function call of output with string argument variable m containing the value "Welcome to the Program!"

	return 0;
}


void output(string message) {
	// function definition of output

	std::cout << message << std::endl;

}




// return

#include <iostream>
#include <string>

// int is the return type for the function add
// ...meaning it MUST return a SINGLE value of int type
int add(int a , int b);

// a return type of void means that the function does not return anything
void print(string s);

int main() {
	
	int a = 5, b = 20;
	
	int sum;

	sum = add(a , b); // function call in an expression

	print("5 + 10 = " + std::to_string(sum)); // functions of return type void CANNOT be used in expressions

	return 0;

}

int add(int a , int b) {
	
	// return statement
	return a + b;

}

void print(string s) {

	std::cout << s << std::endl;
	
	// void of a return statement
}



// how functions work

// each function call creates a new set of local variables, forming part of what is known as a stack frame. A return causes those local variables to be discarded (or at the end of a void function)

// a more detailed explanation...
// The compiler generates instructions to copy arguments to parameter local variables, and to store a return address. A jump instruction jumps from main to the function's instructions. The function executes and stores results in a designated return value location. When the function completes, an instruction jumps back to the caller's location using the previously-stored return address. Then, an instruction copies the function's return value to the appropriate variable.



// reference variables

#include <iostream>

int main() {
	
	int a = 1;
	int b = a; // b is a copy of a...meaning whatever changes happen to b DO NOT happen to a, and vice versa
	int& c = a; // c is a...meaning whatever changes to c happen to a, and vice versa

	b++;
	std::cout << a; // 1

	c++;
	std::cout << a; // 2

	// vice versa...
	
	b--; c--; // reset b and c

	a++;

	std::cout << b; // 1
	std::cout << c; // 2

	return 0;

}


// pass by value

void swap(int a , int b);


int main() {

	int value1 = 5, value2 = 10;

	swap(value1 , value2);
	
	std::cout << "value1 = " << value1 << std::endl;
	std::cout << "value2 = " << value2 << std::endl;

	// output...
	// a = 10
	// b = 5
	// value1 = 5
	// value2 = 10
	
	// pass by value means that parameters are copies of the original arguments and whatever changes happen to them are NOT reflected outside of the scope of the function
	
	return 0;

}

void swap(int a , int b) {

	int t = a;

	a = b;
	
	b = t;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
}




// pass by reference


void swap(int& a , int& b);

int main() {

	int value1 = 5; value2 = 10;

	swap(value1 , value2);
	
	std::cout << "value1 = " << value1 << std::endl;
	std::cout << "value2 = " << value2 << std::endl;

	// output...
	// a = 10
	// b = 5
	// value1 = 10
	// value2 = 5
	
	// pass by reference means that the parameters become the original arguments themselves and whatever changes happen to them are reflected outside of the scope of the function	
	return 0;
}


void swap(int &a , int &b) {

	int t = a;

	a = b;

	b = t;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

}


// if a large value is being passed to a function such as a string or vector, pass by reference is the way to go
// if you do not want the pass by reference item to be modified, one can make it constant

#include <iostream>
#include <string>

int size_of(const string& s);

int main() {

	string name = "Jonathan Benson";

	std::cout << length(name) << std::endl;

	return 0;
}

int length(const string& s) {

	return s.size();

}


// functions with c string parameters
// c strings are automatically passed by pointer to functions
#include <iostream>
#include <cstring>

void example(char s[]); // array parameters require brackets

int main() {

	char str[] = "Hello";

	example(str);
	
	return 0;

}

// scope and lifetime
// a variable declared in a function has scope limited to inside that function and the functions declared in that function
// its lifetime is throughout the entirety of its enclosing function
// an identifier declared outside any function is a global idenitifier and its scope extends after the declaration to the file's end. Global variables should be used sparingly.




// default parameters

#include <iostream>
#include <string>

// default parameters must be the last parameters
void print(string& s , string sep = " " , string end = "\n"); // end is a default parameter with a value of "\n"

int main() {
	
	string m = "Sincerely,";
	string n = "Jonathan Benson";

	print(m);
	print(m , "");

	// output...
	// Sincerely,
	// Jonathan Benson

	return 0;
}

void print(string& s , string end = "\n") {

	std::cout << s << end;

}

// function overloading
// the compiler decides which function to call based on the number and types of the arguments

#include <iostream>
#include <string>

void printDate(int month , int day , int year);
void printDate(const string& month , int day , int year);

int main() {

	printDate(8 , 30 , 1998); // first function will be called and output: 8/30/1998
	std::cout << std::endl;
	printDate("August" , 30 , 1998); // second function will be called and output: August 30, 1998

	return 0;
}

void printDate(int month , int day , int year) {
	
	std::cout << month << '/' << day << '/' << year;
}

void printDate(const string& month , int day , int year) {
	
	std::cout << month << ' ' << day << ", " << year;
}



// include
// include statements DO NOT have a semicolon

// importing the contents of another file

#include "example.h" // this causes the preprocessor to look for example.h in the cwd
#include <example> // this causes the preprocessor to look for example in the standard library
#include <cmath> // files that were apart of the original c standard library have c prepended in their name
#include <someFolder/somefile.h> // the / symbol directs the preprocessor into another directory containing the include file





// separate files

// convention...
// declare functions and classes in header files
// include those header files both into the main.cpp and their corrosponding .cpp files where their functions are defined

// header file guards
// preprocessor directives, which cause the compiler to only include the contents of the header file once.

#define FILENAME_H // defines the symbol FILENAME_H to the preprocessor

// the following form a pair that instructs the preprocessor to process the code between the pair...
// ONLY if FILENAME_H is not defined
#ifndef FILENAME_H

void example1();
void example2();
void example3();

#endif

// good practice is to guard every header file




