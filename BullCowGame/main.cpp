#include <iostream>
#include <string>

void PrintIntro();
void PlayTheGame();
std::string GetGuess();
bool AskToPlayAgain();


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
	//loop for the number of turns asking for guess
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << "\n";
	}
	return;
}

// get a guess from the player
std::string GetGuess() {
	std::string Guess = "";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



