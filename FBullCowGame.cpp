#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; } //getter
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; } // getter
bool FBullCowGame::IsGameWon() const { return false; } //getter

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	return;
}

// receives a valid guess, increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;

	// loop through all letters in the guess
		// compare letters to the hidden word
	return BullCowCount;
}


bool FBullCowGame::CheckGuessValidity(FText)
{
	return false;
}


int32 FBullCowGame::NumberBulls()
{
	return 0;
}

int32 FBullCowGame::NumberCows()
{
	return 0;
}

FText FBullCowGame::RequestNewWord()
{
	return FText();
}

FText FBullCowGame::GetClue()
{
	return FText();
}
