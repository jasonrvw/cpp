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

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;


	MyCurrentTry = 1;
	return;
}

// receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters to the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (MyHiddenWord[MHWChar] == Guess[MHWChar]) {
				// if they're in the same place
				if (MHWChar == GChar) {
					// increment the bulls
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++; // increment cows if they're not in the same place
					}
					
			}
		}
	}
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
