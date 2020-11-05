#include "Game.h"

Game::Game()
{
	log.StartLog(money);
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
	for (int i = 0; i < 2; ++i) {
		playersHand.AddCard(deck.RandomCard());
		dealersHand.AddCard(deck.RandomCard());
	}
}

bool Game::PlayerContinues()
{
	// If the player's hand is busted and the score is under 22, continue.
	if (playersHand.Busted() && playersHand.BestScore() < 22)
		return true;

	// Otherwise, the player doesn't continue.
	return false;
}

void Game::PlayerHits()
{
	playersHand.AddCard(deck.RandomCard());
}

string Game::PlayerWins()
{
	return "";
}

bool Game::DealerContinues()
{
	// If the dealer must hit, add a card to the dealer's hand and continue
	if (dealersHand.MustHit()) {
		dealersHand.AddCard(deck.RandomCard());
		return true;
	}

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
	if (playersHand.Busted() && dealersHand.Busted()) {
		return Tie();
	}
	else if (playersHand.Busted()
		|| playersHand.BestScore() < dealersHand.BestScore()) {
		DealerWins();
	}
	else if (dealersHand.Busted()
		|| playersHand.BestScore() >= dealersHand.BestScore()) {
		return PlayerWins();
	}
	else {
		return "";
	}
}

void Game::ClearHands()
{
	playersHand.ClearHand();
	dealersHand.ClearHand();
}

void Game::EndGame()
{
	string summary;
	log.CloseLog(summary);
}