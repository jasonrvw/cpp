#pragma once
#include <string>
#include <map>
#define TMap std::map

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
	Invalid_Status,
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
	
	
	void Reset(); // TODO write richer return value
	FBullCowCount SubmitValidGuess(FString);

	
	int32 NumberBulls();
	int32 NumberCows();
	FString RequestNewWord();
	FString GetClue();
	


private:
	// see constructor for initialisation values
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	
	bool IsIsogram(FString) const;
};