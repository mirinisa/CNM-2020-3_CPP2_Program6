#include "Game.h"

Game::Game()
{

}

bool Game::SetBet()
{
	return false;
}

// pass-through methods

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