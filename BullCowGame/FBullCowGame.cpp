#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const {
	return false;
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// incriment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
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
	return BullCowCount;
}
