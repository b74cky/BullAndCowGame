#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TO DO make a more rich return value.
	int GetMaxTries();
	int CurrentTry();
	bool IsGameWon();
	bool CheckGuessValidaty(std::string); // TODO make a more rich return value.



private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};