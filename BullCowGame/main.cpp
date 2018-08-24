#include <iostream>
#include <string>
#include"FBullCowGame.h"

void PrintIntro();
void PlayTheGame();
std::string GetGuess();
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
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows Game! \n";
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of? \n";
}

// play the game section
void PlayTheGame() {

	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop for the number of turns asking for guess
	for (int i = 1; i <= MaxTries; i++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << "\n";
	}
	return;
}

// get a guess from the player
std::string GetGuess() {
	int CurrentTry = BCGame.CurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



