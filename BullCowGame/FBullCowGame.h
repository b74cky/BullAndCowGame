#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); // TO DO make a more rich return value.
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidaty(std::string); // TODO make a more rich return value.
	// provide a method for counting buuls & cows, and increasing try #


private:
	int MyCurrentTry;
	int MyMaxTries;
};