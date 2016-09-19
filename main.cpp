#include <iostream>
#include <string>

using namespace std;

int main();

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();

// the entry point of our application
int main()
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();
	
	cout << endl;
	return 0;
}

// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	return;
}


// loop for the number of turns asking for guesses
void PlayGame()
{
	constexpr int NUM_GUESS = 5;
	for (int count = 1; count <= NUM_GUESS; count++)
	{
		cout << "Your guess was: " << GetGuess() << endl;
	}
	return;
}



string GetGuess()
{
	// get a guess from the player
	string Guess = "";
	cout << endl;
	cout << "My guess is: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

