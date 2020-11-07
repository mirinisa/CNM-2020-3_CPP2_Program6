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
		Card c1, c2;
		deck.Deal(c1);
		deck.Deal(c2);
		playersHand.AddCard(c1);
		dealersHand.AddCard(c2);
	}
}

bool Game::PlayerContinues()
{
	// If the player's hand is busted and the score is under 22, continue.
	if (playersHand.Busted() && playersHand.Under(22))
		return true;

	// Otherwise, the player doesn't continue.
	return false;
}

void Game::PlayerHits()
{
	Card c;
	deck.Deal(c);
	playersHand.AddCard(c);
}

string Game::PlayerWins()
{
	double winnings{ double(bet) };

	if (playersHand.BlackJack())
		winnings = 1.5 * bet;

	money += winnings;
	wins += 1;
	stringstream ss;
	ss << "Player wins: " << winnings
		<< "\r\nPlayer now has $" << money;
	string ss_str = ss.str();
	return ss_str;
}

bool Game::DealerContinues()
{
	// If the dealer must hit, add a card to the dealer's hand and continue
	if (dealersHand.MustHit()) {
		Card c;
		deck.Deal(c);
		dealersHand.AddCard(c);
		return true;
	}

	return false;

}

string Game::DealerWins()
{
	money -= bet;
	losses += 1;
	stringstream ss;
	ss << "Player loses: " << bet
		<< "\r\nPlayer now has $" << money;
	string ss_str = ss.str();
	return ss_str;
}

string Game::Tie()
{
	ties += 1;
	stringstream ss;
	ss << "tie"
		<< "\r\nPlayer now has $" << money;
	string ss_str = ss.str();
	return ss_str;
}

string Game::ShowResults()
{
	string results;
	if (playersHand.Busted() && dealersHand.Busted()) {
		results = Tie();
	}
	else if (playersHand.Busted()
		|| playersHand.BestScore() < dealersHand.BestScore()) {
		results = DealerWins();
	}
	else if (dealersHand.Busted()
		|| playersHand.BestScore() >= dealersHand.BestScore()) {
		results = PlayerWins();
	}
	else {
		return "";
	}
	log.WriteLog(results);
	return results;
}

void Game::ClearHands()
{
	playersHand.ClearHand();
	dealersHand.ClearHand();
}

void Game::EndGame()
{
	stringstream ss;
	ss << "Player wins: " << wins
		<< "\nDealer wins: " << losses
		<< "\nTies: " << ties
		<< "\nNumber of hands: " << numberOfHands;
	string summary = ss.str();
	log.CloseLog(summary);
}