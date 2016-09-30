#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	
	// struct GetGuess();
	void Reset(); 
	bool CheckGuessValidity(FString); //TODO make a more rich return value.
	// provide a method for counting bulls and cows and increasing try number
	
	
	
	int32 NumberBulls();
	int32 NumberCows();
	FString RequestNewWord();
	FString GetClue();


private:
	// see constructor for initialisation values
	int32 MyCurrentTry;
	int32 MyMaxTries;
};