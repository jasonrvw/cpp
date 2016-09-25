#pragma once
class FBullCowGame {
public:
	void Reset(); //TODO make a more rich return value.
	int GetMaxTries();
	int GetCurrectTry();
	struct GetGuess();
	bool CheckGuessValidity(string); //TODO make a more rich return value.
	bool bAnswerCorrect();
	int NumberBulls();
	int NumberCows();


private:
	int MyCurrentTry();
	int MyMaxTries();
};