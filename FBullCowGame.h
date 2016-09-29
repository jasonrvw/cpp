#pragma once
#include <string>


class FBullCowGame {
public:
	FBullCowGame(); //Constructor
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	
	// struct GetGuess();
	bool CheckGuessValidity(std::string); //TODO make a more rich return value.
	void Reset(); //TODO make a more rich return value.
	
	
	
	int NumberBulls();
	int NumberCows();
	std::string RequestNewWord();
	std::string GetClue();


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};