#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; } //getter
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; } // getter
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; } //getter

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "saturn";
	
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

// receives a valid guess, increments try and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	
	// loop through all letters in the hidden word	
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters to the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match then
			if (MyHiddenWord[MHWChar] == Guess[GChar]) {
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
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}


/*bool FBullCowGame::CheckGuessValidity(FText) 
{
	return false;
} */


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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram; // TODO write function
	} 
	else if (false)
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
	} 
	else if (Guess.length() !=  GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
	
}

