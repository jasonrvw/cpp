#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

int main();

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetValidGuess();
void PrintGameSummary();


FBullCowGame BCGame; // instantiate (create instance of) a new game.

// the entry point of our application
int main()
{
	// std::cout << BCGame.GetCurrentTry();
	
		do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());	
	
	std::cout << std::endl;
	return 0;
}

// introduce the game
void PrintIntro() 
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}


// loop for the number of turns asking for guesses

void PlayGame()
{
	BCGame.Reset();
	int32 GetMaxTries = BCGame.GetMaxTries();
	
	// loop asking for guesses while the game
	// is NOT won and there are still tries remaining
	while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= GetMaxTries) 
	{
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(GetValidGuess());	
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "." << "\n\n";
	}
	PrintGameSummary();
	return;
}


// loop continually until the user gives a valid guess
FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do	{
		// get a guess from the player
		int32 GetCurrentTry = BCGame.GetCurrentTry();	
		FText Guess = "";
		std::cout << std::endl;
		std::cout << "Try " << GetCurrentTry;
		std::cout << ". My guess is: ";
		std::getline(std::cin, Guess);	
	
		// Check Guess validity and provide feedback
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)	{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Guess is not an Isogram. Enter a word without repeating letters.";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Only lowercase letters are allowed.";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping till we get no errors
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You guessed the correct word, WELL DONE!\n\n";
	}
	else 
	{
		std::cout << "You're out of tries...ergo....LOSER!!!\n\n";
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



