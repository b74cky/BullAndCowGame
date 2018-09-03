/* The game logic (no view code or direct user interaction)
The game is a simple guess the word based on MasterMind */

#pragma once
#include <iostream>
#include <string>
#include <vector>

//to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Lowercase,
	Wrong_length
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	int32 GetTheWordDepOnS(int32);
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidaty(FString) const;
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	std::vector<FString> LiWordofSize;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerase(FString) const;
};

