#include <iostream>
#include <string>


int main();

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();

// the entry point of our application
int main()
{
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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}


// loop for the number of turns asking for guesses
void PlayGame()
{
	constexpr int NUM_GUESS = 5;
	for (int count = 1; count <= NUM_GUESS; count++)
	{
		std::cout << "Your guess was: " << GetGuess() << std::endl;
	}
	return;
}



std::string GetGuess()
{
	// get a guess from the player
	std::string Guess = "";
	std::cout << std::endl;
	std::cout << "My guess is: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

