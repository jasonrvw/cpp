#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialised to 0
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame 
{
public:
	FBullCowGame(); //Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;	
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;


	EGuessStatus CheckGuessValidity(FString) const; 
	
	
	// struct GetGuess();
	void Reset(); 
	
	FBullCowCount SubmitGuess(FString);

	// bool CheckGuessValidity(FText);
	
	
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