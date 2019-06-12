
/*
	
Variable declaration
	
	a statement that declares a new variable, specifying the variable's name and type
	
	its type specifies what type of value it can hold
	
Assignment Statement

	variable = expression

	assigns the variable on the left-side of the = with the current value of the right-side expression
*/

int main()
{
	
	//all variables must be declared with a type before they can be used
	
	int variable1; //declaration statement
	
	int variable2 , variable3; //variables can be declared on the same line, separated by a comma
	/*
	"=" is the assignment operator
	assigns the left side (variable) to the right side (expression)
	*/
	
	variable = 5; //assignment statement
	
	/*
	A variable that is declared but not assigned to a value yet,
	is assigned to an unknown value that was previously stored at its current
	memory location.
	
	*/
	
	int variable4 = 10; //declaration and assignment combined into one statement
	
	int variable5 = 10, variable6 = 11; //multiple declarations and assignments in one statement
	
	//"int variable5 , variable6 = 20 , 30" WILL issue an error
	
	//it is terrible practice to assign variables of one type to a value of another type
	
	
	//incremental operators
	
	variable4 = variable4 + 1; //assignment statement with same variable on both sides
	
	//is the same as...
	
	variable4 += 1;
	
	//and...
	
	variable4++;
	
	
	return 0;
	
}

/*
Identifiers

	Names created by programmers for an item like a variable or function
	
	Identifiers in c++ must...
	
		be a sequence of letters (a-z, A-Z), underscores (_), and digits(0-9)
		
		start with a letter or underscore

		cannot contain any special characters or spaces
		
	Identifiers in c++ are...
	
		case sensitive
		
Reserved word is...

	a word that is part of the language, like int, short , or double in c++.
	
	also known as a keyword

	list of them...

	and
	and_eq
	asm
	auto
	bitand
	bitor
	bool
	break
	case
	catch
	char
	class
	compl
	const
	continue
	default
	delete
	do
	double
	dynamic_cast
	else
	enum
	explicit
	export
	extern
	false
	float
	for
	friend
	goto
	if
	inline
	int
	long
	mutable
	namespace
	new
	not
	not_eq
	operator
	or
	or_eq
	private
	protected
	public
	register
	reinterpret_cast
	return
	short
	signed
	sozeof
	static
	static_cast
	struct
	switch
	template
	this
	throw
	true
	try
	typedef
	typeid
	typename
	union
	unsigned
	using
	virtual
	void
	volatile
	wchar_t
	while
	xor
	xor_eq

*/


/* Arithmetic expressions
 * An expression is a combination of items, like variables, literals, operators, and parentheses, that evalutes to a singular value
 * A literal is a specific value in code
 * An operater is a symbol that performs a built in calculation
 *
 * Arithmetic operators: + , - , / , *
 *
 * Arithmetic precedence rules: parenthesis, unary (-), * \/ %, +-, left-to-right
 *
 */

/*
 * Compound operators: += , -= , *= , /= , %=
 */

void main()
{
	int value;
	
	//the two statements below are the same
	value += 1;
	value = value + 1;
}


//int

void main()
{

	int a;

	int b = 1;

	int c = -500;

	int d = 3.5; //this will round DOWN to 3

	int e = 4 / 5; //this will round DOWN to 0

}

//double

void main()
{
	
	double a;

	double b = 2.0; //when initializing a double value, it must always have a decimal

	double c = 1.0 / 2.0; //the rule above applies also when performing operations

	double d = 0.75; //it is best practice to provide a 0 before fractional numbers

	double e = 0.0 / 0.0; //this will result in nan (not a number)

	double f = 100.0 / 0.0; //this will result in inf (infinity)

	double g = -100.0 / 0.0; //this will result in -inf (negative infinity)

	double h = 0.0 / 5.0; //this will result in 0.0

	//scientific notation
	
	double i = 1.0e6; //i will equal 1000000
	double j = -1.0e-6; //j will equal 0.000001
	

}

//const

//An initialized variable whose value cannot change is called a constant variable.

void main()
{
	const int CONSTANT_VARIABLE; //it is best practice to capitalize const variables and separate words by underscore

	const double PI = 3.14;

	double radius = 5.0;

	double circle_area = PI * (radius * radius); //const variables can be used in expressions

}

//math functions

#include <cmath> //this library has about 20 useful math functions

//Here are some of them...
double sqrt(double number);
double pow(double base , double exp);
double fabs(double number);


//modulo operator %

void main()
{

	int a = 51;
	int b = 2;

	int remainder_of_a_and_b = 51 % 2; //1

	//both operands of the modulo MUST be integers
	
	
}

//type casting

void main()
{
	
	//some compilers may implicitally convert types, however best practice is to explicitly convert types
	
	int a = 5;

	double b = static_cast<double>(a); // type casts a from an integer into a double

	//it is best practice to type cast all values in an expression to the same desired final evaluation value type
	
	int c = 123;
	int d = 456;

	double e = static_cast<double>(c) / static_cast<double>(d);
}



//char


void main()
{

	char a;

	std::cin >> a; // std::cin can be used to get char values

	char b = 'b'; // char literals are wrapped by single quotes

	// all characters corrospond with an ASCII number encoding.
	// for example, the char 'A' corrosponds with 65 and 'a' corrosponds with 97
	


}


// escape sequences
// A two-character sequence starting with \ that represents a special character
// here are some common ones...
// \n , \t , \' , \" , \\


// string
// a sequence of characters

#include <string> // this library must be included in order to work with strings

void main()
{
	
	string example; // this is an empty string ""

	string first = "Jonathan"; // string literals are wrapped by double quotes
	
	string last;

	last = "Benson"; // assigning a string of a different length from when its length when it was declared will automatically reallocate memory to compensate

	string a = "asdf";
	string b = "jkl;";

	a = b; // a will be assigned to a COPY of b's value, not the same value

	b = "something else";

	std::cout << a; // this will output "jkl;" because the changing of b's value does not affect a's value because they do not corrospond to the same value (address-wise)



	// strings with std::cin
	// ignores preceding whitespace and characters after the first encountered whitespace character

	string input_string;

	std::cin >> input_string; // the user inputs "\t Hello World!"

	std::cout << input_string; // the output will be "Hello"

	// how to work around this problem...
	
	string first;
	string last;

	std::cout << "Enter in your first and last name separated by a space." << std::endl;

	std::cin >> first;
	std::cin >> last;

	std::cout << "First name: " << first << std::endl;
	std::cout << "Last name: " << last;

	//if the user inputted "Jonathan Benson" for the above example, the output will be...
	// First name: Jonathan
	// Last name: Benson
	
	//-----------------------------
	//getting a string with whitespace
	
	string phrase;

	std::getline(std::cin , phrase);

	// if the user inputted "\t Hello World!\n", then phrase would equal "\t Hello World!"
}


// numeric data types

void main()
{

	char a; // size of 8 bits, -128 to 127 number range
	short b; // size of 16 bits, -32768 to 32767
	long c; // size of 32 bits, -2147483648 to 2147483647
	long long d; // 64 bits, -9223372036854775808 to 9223372036854775807
	int e; // 32 bits, -2147483648 to 2147483647

	float f; // 32 bits, -3.4e38 to 3.4e38
	double g; // 64 bits -1.7e308 to 1.7e308

	// unsigned can be used for every date type, doubles the range in positive (0 to #)
	unsigned int h; // unsigned means that the integer is expected to be a positive integer
}


// random numbers

#include <cstdlib> // must include the c standard library in order to generate random numbers

void main()
{
	srand(time(0)); // seed the random number generator

	// RAND_MAX = 214783647

	int r = rand(); //will generate a random number from 0 to RAND_MAX

	int s = rand() % 100; // will generate a random number from 0 to 99

	// to generate random numbers within a certain range, fancy algebra is needed
	// to generate a random number between 5 and 15
	
	int rand_num = (rand() % (15 - 5 + 1)) + 5;


}

// auto (since c++11)

void main()
{
	// cannot declare a variable with auto without initializing it with a value

	auto a = 5; // int
	auto b = 5.0 // double
	auto c = 'a' // char

	// strings do not work with auto
}







