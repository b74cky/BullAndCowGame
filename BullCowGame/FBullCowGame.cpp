#include "FBullCowGame.h"
#include <map>
#define TMap std::map


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

EGuessStatus FBullCowGame::CheckGuessValidaty(FString Guess) const{
	if (!IsIsogram(Guess)) {  
		return EGuessStatus::Not_Isogram; // if the guess isn't and isogram
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase; // if the guess isn't all lowercase
	}
	else if ( Guess.length() != GetHiddenWordLength()) {
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

bool FBullCowGame::IsIsogram(FString Word) const {
	if (Word.length() <= 1) { return true; } // treat 0 and 1 letter words as isogram
	TMap<char, bool> LetterSeen; // setup our map
	// loop through the word
	for (auto Letter : Word) {
		Letter = tolower(Letter); // handle mixed case
	    // comparing letter with map values
		if (LetterSeen[Letter]) { return false; } // not isogram 
		else {
			LetterSeen[Letter] = true; // add the letter to the map
		}
	}
	return true; //for example in case where /0 or "" is entered
}


