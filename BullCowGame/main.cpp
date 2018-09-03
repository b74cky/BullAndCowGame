/*This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#pragma once

#include <limits>
#include <iostream>
#include <string>
#include"FBullCowGame.h"

using FText = std::string;
using int32 = int;

//function prototypes as outside class
void PrintIntro();
void PlayTheGame();
void PrintGameSummary();
void SetTheWLength();
bool AskToPlayAgain();
bool FIsDigit(FText WordLength);
FText GetValidGuess();


FBullCowGame BCGame; //instantiate a new game, which we re-use across plays


int main() {
	do {
		PrintIntro();
		PlayTheGame();
		PrintGameSummary();
	} while (AskToPlayAgain());

	return 0;
}

//--Functions--
void PrintIntro() {
	std::cout << "---------------------------------------------------\n";
	std::cout << "    Welcome to Bulls and Cows, a fun word game!    \n";
	std::cout << "---------------------------------------------------\n";
	std::cout << "                }   {         ___ " << std::endl;
	std::cout << "                (o o)        (o o) " << std::endl;
	std::cout << "         /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "        / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << "       *  |-,--- |              |------|  * " << std::endl;
	std::cout << "          ^      ^              ^      ^ " << std::endl;
	std::cout << "---------------------------------------------------\n";
	std::cout << "----------D  E  S  C  R  I  P  T  I  O  N:---------\n";
	std::cout << "---------------------------------------------------\n";
	std::cout << "A Bull - a correct letter in the right place.\n";
	std::cout << "A Cow - a correct letter, but in the wrong place.\n";
	std::cout << "---------------------------------------------------\n";
	std::cout << "----G O O D  L U C K  &  L E T' S  S T A R T !:----\n";
	std::cout << "---------------------------------------------------\n";
}

//play the single game to complection
void PlayTheGame() {
	BCGame.Reset();
	SetTheWLength();
	int32 MaxTries = BCGame.GetMaxTries();
	//loop asking for guesses while the game is NOT won
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();
		//submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	return;
}

//loop continually until the user enter a valid guess
FText GetValidGuess() {
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";

		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidaty(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram word (without repeating letters). \n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters. \n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << "\n\n";
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations! You won the game! \n";
	}
	else {
		std::cout << "Bad luck. You can try one more time. \n";
	}
}
void SetTheWLength() {
	FText WordLength = "";
	std::cout << "Select the length of the word (from 3 to 6): ";
	getline(std::cin, WordLength);
	std::cout << "\n";
	while (!FIsDigit(WordLength)) { 
		std::cout << "Please enter the right number.\n";
		std::cout << "Select the length of the word (from 3 to 6): ";
		getline(std::cin, WordLength); 
		std::cout << "\n";
	};
	int32 WordLengthInt = std::stoi(WordLength);
	BCGame.GetTheWordDepOnS(WordLengthInt);
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? \n";
	std::cout << "You have " << BCGame.GetMaxTries() << " tries to guess the hidden word.\n\n";
	return;
}

//Input validation to define a correct digit
bool FIsDigit(FText WordLength) {
	const char *temp = "0123456789-+";
	unsigned point_count = 0;

	for (int32 i = 0; i < WordLength.size(); i++) {
		if ((i > 0) && (WordLength[i] == '+' || WordLength[i] == '-')) return false;
		else if (WordLength[i] == '.') {
			point_count++;
			if (point_count > 1) return false;
		}
		else if (!strchr(temp, WordLength[i])) return false;
		else if (WordLength.size() > 10) return false;
	}
	if (WordLength == "") return false;
	else if (std::stoi(WordLength) < 3 || std::stoi(WordLength) > 6) return false;
	return true;
}
