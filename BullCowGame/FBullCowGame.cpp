#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidaty(FString Geuss) const{
	if (false) {
		return EGuessStatus::Not_Isogram; // if the guess isn't and isogram
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase; // if the guess isn't all lowercase
	}
	else if ( Geuss.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_length; // if the length is wrong
	}
	else {
		return EGuessStatus::OK; // otherwise  OK
	}
}



// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuning same length as guess

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < Guess.length(); GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				// if they're in the same place
				if (GChar == MHWChar) {
					// incriment bulls 
					BullCowCount.Bulls++;
				}
				// if they're in different place
				else {
					// incriment cows 
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}
