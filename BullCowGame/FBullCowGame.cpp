#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() { return MyMaxTries; }
int FBullCowGame::CurrentTry() { return MyCurrentTry; }

void FBullCowGame::Reset() {
	return;
}

bool FBullCowGame::IsGameWon() {
	return false;
}

bool FBullCowGame::CheckGuessValidaty(std::string) {
	return false;
}
