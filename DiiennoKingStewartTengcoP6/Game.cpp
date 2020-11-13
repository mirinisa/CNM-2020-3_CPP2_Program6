//Sean King cking66@cnm.edu
//Program 6: Blackjack
//Game.cpp


#include "Game.h"
#include <iomanip>

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
		numberOfHands += 2;
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
	// If the player's hand is not busted and the score is under 22, continue.
	if (!playersHand.Busted() && playersHand.Under(22))
		return true;

	// Otherwise, the player doesn't continue.
	return false;
}

void Game::PlayerHits()
{
	// Create empty card object
	Card c;
	// Deal from the deck into the empty card object
	deck.Deal(c);
	// Add the card to the player's hand.
	playersHand.AddCard(c);
}

string Game::PlayerWins()
{
	// Initialize the winnings variable to bet.
	double winnings{ double(bet) };

	// If the player's hand is a Black Jack,
	if (playersHand.BlackJack())
	{
		winnings = 1.5 * bet;
	}

	// Add the winnings to money and increase wins by 1.
	money += winnings;
	++wins;
	// Return results string
	stringstream ss;
	ss << "Player wins!"
		<< "\r\nYou just won $" << setprecision(2) << fixed << winnings
		<< "\r\nYou now have: $" << setprecision(2) << fixed << money;
	return ss.str();
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
	++losses;
	stringstream ss;
	ss << "Dealer wins this round!"
		<< "\r\nYou lost $" << setprecision(2) << fixed << bet
		<< "\r\nYou now have: $" << setprecision(2) << fixed << money;
	return ss.str();
}

string Game::Tie()
{
	ties += 1;
	stringstream ss;
	ss << "Tied."
		<< "\r\nYou have: $" << setprecision(2) << fixed << money;
	return ss.str();
}

string Game::ShowResults()
{
	string results;
	// both player and dealer bust, or scores are equal
	// According to several different websites, if the
	// dealer and player have the same score, then no
	// money changes hands and it is essentially a tie
	// (that is, PlayerWins() should not be called)
	if (playersHand.Busted() && dealersHand.Busted() 
		|| (playersHand.BestScore() == dealersHand.BestScore())) 
	{
		results = Tie();
	}
	// only player busts
	else if (playersHand.Busted()) 
	{
		results = DealerWins();
	}
	// only dealer busts
	else if (dealersHand.Busted() ) 
	{
		results = PlayerWins();
	}
	// neither busts and dealer wins
	else if (playersHand.BestScore() < dealersHand.BestScore())
	{
		results = DealerWins();
	}
	// neither busts and player wins
	else if (playersHand.BestScore() > dealersHand.BestScore())
	{
		results = PlayerWins();
	}
	else 
	{
		return "Error, no results.";
	}

	// only write to log if it's open
	if (IsLogOpened())
	{
		log.WriteLog(results);
	}
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
	ss << "\n\n\n-----------GAME OVER------------"
		<< "\nPlayer's wins: " << wins
		<< "\nDealer's wins: " << losses
		<< "\nTies: " << ties
		<< "\nRounds played: " << (numberOfHands/2);

	// report how much money player won/lost
	double winnings = money - 1000;
	if (winnings > 0) 
	{
		ss << "\nYou won $" << setprecision(2) << fixed << winnings << " this game.";
	}
	else if (winnings < 0)
	{
		ss << "\nYou lost $" << setprecision(2) << fixed << (winnings * -1) << " this game.";
	}
	else
	{
		ss << "\nYou didn't win or lose any money.";
	}
	
	string summary = ss.str();
	
	// only write to log if it's open
	if (IsLogOpened())
	{
		log.CloseLog(summary);
	}
}