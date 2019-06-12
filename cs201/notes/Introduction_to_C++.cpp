


//this is a comment

/*

this is a mutliline comment
...also known as a block comment

*/



//this is a simple program

#include <iostream> //importing an external library

int main()
{
	//the main function of the program
	
	//each statement ends with a semicolon (;)
	
	//whitespace (ex space, newline, tab, etc.) is ignored by compiler

	int wage; //declaration of a variable and its type
	
	wage = 20; //assignment statement
	
	
	std::cout << "Salary is "; //writing to console
	std::cout << wage * 40 * 50;
	std::cout << std::endl;
	
	return 0; //the main function always returns 0
}


//basic input

#include <iostream> //need to include this library for io

int main()
{
	int wage;
	
	//cin stands for "characters in"
	std::cin >> wage; //gets an input value and assigns it to variable wage
	
	std::cout << "Salary is ";
	std::cout << wage * 40 * 50;
	std::cout << std::endl;
	
	return 0;
}

//basic output

#include <iostream>

int main()
{
	
	std::cout << "Keep calm" << std::endl; //endl represent the \n character
	std::cout << "...and carry on.";
	
	return 0;
}

//this will output
/*
Keep calm
...and carry on.
*/

//outputing a variable

#include <iostream>

int main()
{
	int wage;
	
	wage = 20;
	
	std::cout << "Wag is ";
	std::cout << wage << "." << std::endl;
	std::cout << "Goodbye.";
	
	return 0;
	
}

//this will output
/*
Wage is 20.
Goodbye.
*/

//outputing multiple items with one statement

#include <iostream>

int main()
{
	
	int wage;
	
	wage = 20;
	
	std::cout << "Wage is: " << wage << std::endl;
	std::cout << "Goodbye." << std::endl;
	
	return 0;
	
}

/*
Erors and Warnings

	Syntax Errors (also known as compile-time errors)
	
		The violation of a programming language's rules on how symbols can be combined to create a program.
		An example would be forgetting a semicolon after a statement.
		
		When debugging syntax errors...
		
			1. Focus on FIRST error message, ignoring the rest.
			2. Look at reported line of first error message. If error found, fix. Else, look at previous few lines.
			3. Compile. Repeat.
			
	Logic Errors (also known as bugs)
	
		An error that occurs while a program runs.
		
		Good practice is to compile after writing every other few lines of code.
		
	Warnings
	
		The indication of a possible bug (logic error).
		
		A great compilation command "g++ -Wall main.cpp"

*/

/*
How a computer works under the hood

All the memory on a computer is a (theoretically) infinte, one dimensional array of 1's and 0's (bits).
A computer can read and write from that memory and perform arithmetic and logical operations on that data.

Analogy

The arrangement is akin to a chef (processor) who executes instructions of a recipe (program).
Each instruction modifying ingredients (data), with the recipe and ingredients kept on a nearby counter (memory).


A computer can only understand machine instructions made up of 1's and 0's.
A compiler translates human readable code into machine instructions that a computer can understand.


*/

/*
Computer tour

Input/Output Devices

	output
		
		a screen
		
	input
	
		a keyboard
		
Storage

	a hard drive
	
		stores files an other data, such as program files.
	
Memory

	RAM (random-access memory)
	
		temporarily holds data read from storage, and is designed such that any address can be accessed much faster than disk, in just a few clock ticks rather than hundreds of ticks.
		
Processor

	runs the computer's programs, reading and ececuting instructions from memory, performing operations, and reading/writing data from/to memory.
	
Clock

	a processor's instructions execute at a rate governed by the processor's clock, which ticks at a specific frequency.
	
	The faster the tick frequency of a processor, the more expensive the processor.


*/


/*
Language history

C++ created by Bjarne Soustrup is a superset of C.

*/



	





	




