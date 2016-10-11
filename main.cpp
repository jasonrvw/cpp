#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

int main();

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetGuess();


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
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}


// loop for the number of turns asking for guesses
// TODO change from FOR to WHILE loop once we start validating answers
void PlayGame()
{
	BCGame.Reset();
	int32 GetMaxTries = BCGame.GetMaxTries();
		
	for (int32 count = 1; count <= GetMaxTries; count++)
	{
		// submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(GetGuess());
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "." << std::endl;
	}
	// TODO add a game summary
	return;
}



FText GetGuess()
{
	// get a guess from the player
	int32 GetCurrentTry = BCGame.GetCurrentTry();
	
	FText Guess = "";
	std::cout << std::endl;
	std::cout << "Try " << GetCurrentTry;
	std::cout << ". My guess is: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



