#pragma once
#include <string>


class FBullCowGame {
public:
	void Reset(); //TODO make a more rich return value.
	int GetMaxTries();
	int GetCurrentTry();
	// struct GetGuess();
	bool CheckGuessValidity(std::string); //TODO make a more rich return value.
	bool IsGameWon();
	int NumberBulls();
	int NumberCows();
	std::string RequestNewWord();
	std::string GetClue();


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};