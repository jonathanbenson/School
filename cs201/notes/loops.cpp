

// loops notes

// a loop is a program construct that repeatedly executes the loop's statements (loop body) while the loop's expression is true
// an iteration is one execution of the loop body

// while

int main() {
	
	int count = 0;
	
	// the program enters the loop if the loop expression evaluates to true
	while (count < 100) {

		std::cout << count << std::endl;

		count = count + 1;

		// at the end of each iteration, it jumps back to the expression at the top and enters another iteration if the loop expression evaluates to true
	}

	
	// infinite loop
	// below is an infinte loop because the loop expression will always evaluate to true at the beginning of each iteration
	while (true) {

		std::cout << "This is an infinite loop." << std::endl;
	}

	// receiving input until a sentinel is seen
	// a sentinel value is a special value indicating the end of a list
	
	int sum = 0;
	const char SENTINEL = '.';

	int inpt;

	while (inpt != SENTINEL) {
		
		std::cout << "Enter a number to sum or enter '.' to compute sum ==> ";
		std::cin >> inpt;

		sum += inpt;

	}


	return 0;
}

// do while
// a loop construct that first executes the lopo body's statments, then checks the loop condition

#include <iostream>

int main() {

	int count = 0;

	do {

		std::cout << count << std::endl;
		
		count += 1;

	} while (count < 100);


	// getting user to input a number within a range of 0 to 100
	
	int userInput;

	do {
		std::cout << "Enter a number within the range of 0 to 100 ==> ";
		std::cin >> userInput;

	} while (userInput > 0 && userInput < 100);



	return 0;
}


// for

#include <iostream>
#include <string>
int main() {

	// outputting all the even numbers from 0 to 100 on separate lines with a for loop
	// three parts: initial expression, condition expression, update expression
	
	int i;

	for (i = 2; i <= 100; i++) {

		if (i % 2 == 0)
			std::cout << i << std::endl;

	}

	// in-loop declaration
	// outputting all the odd numbers in between 0 and 100
	for (int i = 1; i <= 100; i++) {

		if (i % 2 == 1)
			std::cout << i << std::endl;
	}

	// iterating through a string's characters
	
	string name = "Jonathan Benson";

	int i;

	for (i = 0; i < name.size(); i++) {

		std::cout << name.at(i) << std::endl;
	}


	return 0;
}

// pre and post incremental operators

int main() {

	int a = 0;
	int b = 0;

	// pre
	// evaluates expression before the operation is performed
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	// output...
	// 0
	// 1
	
	// post
	// performs operation before expression is evaluated
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;

	// output...
	// 1
	// 1	
	return 0;
}



// nested loops

#include <iostream>
#include <string>

int main() {

	int i;
	char j;

	// outputting all the combinations of numbers and letters (ex. 0a 0b 0c ... 9x 9y 9z)
	
	for (i = 0; i <= 0; i++)
		for (j = 'a'; j <= 'z'; j++)
			std::cout << i << j << ' ';


	return 0;
}


// break and continue

#include <iostream>
#include <ctime>

int main() {
	//guessing game
	
	srand(time(0));

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	int random_i = rand() % alphabet.size();
	
	char random_char = alphabet.at(random_i);
	char guess;

	while (true) {

		std::cout << "Guess a random letter ==> ";
		std::cin >> guess;	
		
		if (guess != random_char) {

			continue; // jump back up to the top of the loop

		} else {

			break; // exit the loop
		
		}
	}

	std::cout << "You guessed correctly!" << std::endl;

	return 0;

}

// enumerations
// declares a name for a new type and possible values for that type

int main() {
	
	// traffic light example
	// state machine	
	enum TL {RED , GREEN , YELLOW}; // indices starting at 0 to size minus 1
	
	TL traffic_light;

	traffic_light = GREEN;

	if (traffic_light == GREEN)
		std::cout << "Green light. Go.";
	else if (traffic_light == YELLOW)
		std::cout << "Yellow. Slow down.";
	else if (traffic_light == RED)
		std::cout << "Red. Stop.";

	std::cout << endl;

	// explicit enum declarations
	
	enum Channel {FOX = 360 , CNN = 101 , CARTOONNETWORK = 58};

	return 0;
}
