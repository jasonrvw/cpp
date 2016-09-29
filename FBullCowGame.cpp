#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	MyCurrentTry = 666;
	MyMaxTries = 666;
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; } //getter
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; } // getter
bool FBullCowGame::IsGameWon() const { return false; } //getter

void FBullCowGame::Reset()
{
	return;
}


bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}


int FBullCowGame::NumberBulls()
{
	return 0;
}

int FBullCowGame::NumberCows()
{
	return 0;
}

std::string FBullCowGame::RequestNewWord()
{
	return std::string();
}

std::string FBullCowGame::GetClue()
{
	return std::string();
}
