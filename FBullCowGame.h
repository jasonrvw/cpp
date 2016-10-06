#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialised to 0
struct BullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); //Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	
	// struct GetGuess();
	void Reset(); 
	bool CheckGuessValidity(FString); //TODO make a more rich return value.
	BullCowCount SubmitGuess(FString);
	
	
	int32 NumberBulls();
	int32 NumberCows();
	FString RequestNewWord();
	FString GetClue();


private:
	// see constructor for initialisation values
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};