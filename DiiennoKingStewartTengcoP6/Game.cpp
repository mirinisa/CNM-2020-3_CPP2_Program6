#include "Game.h"

Game::Game()
{

}

bool Game::SetBet(int b)
{
	// If bet is less than 0 or bet is greater than money, return false.
	if (b < 0 || b > money) {
		return false;
	}
	// Otherwise, return true.
	else {
		bet = b;
		return true;
	}
}

void Game::InitialDeal()
{
}

bool Game::PlayerContinues()
{

	return false;
}

void Game::PlayerHits()
{

}

string Game::PlayerWins()
{
	return "";
}

bool Game::DealerContinues()
{
	return false;
}

string Game::DealerWins()
{
	return "";
}

string Game::Tie()
{
	return "";
}

string Game::ShowResults()
{
	return "";
}

void Game::ClearHands()
{

}

void Game::EndGame()
{

}