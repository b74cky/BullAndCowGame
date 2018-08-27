/*This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include"FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayTheGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for application
int main() {
	do {
		PrintIntro();
		PlayTheGame();
	} while (AskToPlayAgain());

	return 0;
}


//Functions

// intoduce the game section
void PrintIntro() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows Game! \n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
}

// play the game section
void PlayTheGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guess
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess(); //TODO make loop checking valid

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n";
		std::cout << "Your guess was: " << Guess << "\n";
	}

	//TODO summarise game
	return;
}

// get a guess from the player
FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



