
// Jonathan Benson
// Program 1
// CS201
// June 11, 2019

#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

const int THRESHOLD = 50;

enum player { USER, AI };
enum action { ROLL, HOLD, PLAY, QUIT };

void output(player turn);
void output(int user_score, int ai_score);
void output(int dice, int pot, bool is_bust);
void output(int user_score, int ai_score, int pot, player winner);

void roll(int& dice);

void bust(int& pot, player& turn, int& player_score);
void hold(int& pot, player& turn, int& player_score);

bool exists_winner(int user_score, int ai_score, int pot, const int THRESHOLD);

action user_choose(int dice, int pot);
action user_choose();

action ai_choose(int dice, int pot);

void change(player& current);





int main() {

	srand(time(NULL)); // seed the random number generator

	int dice;

	player turn;
	player previous_start = AI;
	action choice = ROLL;

	do {
		
		//initialize variables
		int user_score = 0, ai_score = 0, pot = 0;

		// change starting turn every game
		// the first game will always default to the user's turn
		change(previous_start);

		turn = previous_start;

		// output the score and whos turn it is
		output(user_score, ai_score);
		output(turn);

		do {

			// roll the dice (1-6) and add it to the pot
			roll(dice);
			pot += dice;

			if (dice == 1) {
				// if the player rolled a 1, then it is a bust

				output(dice, pot - 1, true); // output the die roll and the current pot

				bust(pot, turn, turn == USER ? user_score : ai_score); // set the player's score and the pot to 0, and change turns
				

				// output whos turn it is and the score
				output(turn);

				output(user_score, ai_score);

				// it is then the next players turn
				continue;
			}
			else {
				// if the user rolled 2-6, then then they get to roll again

				output(dice, pot, false);

				// check to see if there is a winner yet
				if (exists_winner(user_score, ai_score, pot, THRESHOLD))
					break;

			}

			// get the player's choice to either roll or hold in their next try
			if (turn == USER)
				choice = user_choose(dice, pot);
			else if (turn == AI)
				choice = ai_choose(dice, pot);
			

			if (choice == HOLD) {
				// if the player decides to hold...
				// the pot is added to their score
				// it switches to the other player's turn

				hold(pot, turn, turn == USER ? user_score : ai_score);
				
				// output whos turn it is and the score
				output(turn);
				output(user_score, ai_score);
			}


		} while (true);

		// when there is a winner, output who it is and final score
		output(user_score, ai_score, pot, turn);


	} while (user_choose() == PLAY); // ask the user if they want to play again


	return 0;
}

void output(player turn) {
	// output whos turn it is to the console

	if (turn == USER)
		std::cout << "\nYour turn.\n";
	else if (turn == AI)
		std::cout << "\nAI's turn.\n";

	std::cout << std::endl;

}

void output(int user_score, int ai_score) {
	// outputs the score at the beginning of a turn

	std::cout << "Score\tYou : " << user_score << " AI : " << ai_score << std::endl << std::endl;

}

void output(int dice, int pot, bool is_bust) {
	// output both the die roll and the pot to the console

	std::cout << "Die Roll : " << dice << "\tPot : " << pot << " ";

	// if it is a bust, let them know
	if (is_bust == true)
		std::cout << "BUST";

}


void output(int user_score, int ai_score, int pot, player turn) {
	// outputs the final score when there is a winner
	
	std::string winner = ((turn == USER) ? "you" : "the ai");
	
	std::cout << "\n\nCongratulations " << winner << " won!!\n\n";

	if (turn == USER)
		output(user_score + pot, ai_score);
	else if (turn == AI)
		output(user_score, ai_score + pot);

}

void roll(int& dice) {
	// rolls the dice to a random value of 1-6

	dice = (rand() % 6) + 1;
}

void bust(int& pot, player& turn, int& player_score) {
	// set the pot, player_score to 0 and change turns

	pot = 0;
	player_score = 0;
	change(turn);

	std::cout << std::endl;

}

void hold(int& pot, player& turn, int& player_score) {
	// increment the player's score by the pot, set the pot to 0, and change turns

	player_score += pot;
	pot = 0;
	change(turn);

}

bool exists_winner(int user_score, int ai_score, int pot, const int THRESHOLD) {
	// check to see if there is a winner yet
	// there is a winner if the sum of a player's score and the pot exceed or equal 50

	return ((user_score + pot) >= THRESHOLD) || ((ai_score + pot) >= THRESHOLD);

}

action user_choose(int dice, int pot) {
	// validates and returns whether a player wishes to ROLL or HOLD

	char c;

	while (true) {

		std::cout << "(R)oll again or (H)old? ";
		std::cin >> c;

		c = toupper(c);

		if (c == 'R')
			return ROLL;
		else if (c == 'H')
			return HOLD;
		else
			std::cout << "You must enter R or H\n\t";

	}

}

action user_choose() {
	// validates and returns whether a user wishes to continue playing or to quit

	char c;

	while (true) {

		std::cout << "Do you want to play the game again? Y or N" << std::endl;
		std::cin >> c;

		c = toupper(c);

		if (c == 'Y')
			return PLAY;
		else if (c == 'N')
			return QUIT;
		else
			std::cout << "You must only enter Y or N.\n";
	}

}

action ai_choose(int dice, int pot) {
	// returns whether or not the ai wishes to roll or hold based on the pot
	// if the pot is greater than or equal to 20, it will hold, else roll

	std::cout << std::endl;

	if (pot < 20)
		return ROLL;
	else
		return HOLD;

	

}

void change(player& current_turn) {
	// changes the players turns

	if (current_turn == USER)
		current_turn = AI;
	else
		current_turn = USER;

}


