/* Mirinisa Stewart-Tengco mstewarttengco@cnm.edu & Sean King cking66@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 *
 * File: Game.h
 * Purpose: Header file for Game object
 * Last modified: 5 Nov 2020
 */


#include "Deck.h"
#include "Hand.h"
#include "Logger.h"
#include <string>
#include <sstream>
using namespace std;


class Game
{
public:
	Game();
	bool SetBet(int b);
	void InitialDeal();
	string ShowPlayerHand() { return playersHand.Show(false, false); }
	string ShowDealersHand(bool hide) { return dealersHand.Show(true, hide); }
	bool isBlackJack() { return playersHand.BlackJack(); }
	bool PlayerBusted() { return playersHand.Busted(); }
	bool PlayerContinues();
	void PlayerHits();
	string PlayerWins();
	bool DealerContinues(); // Dealer has less than 17 points
	string DealerWins();
	string Tie(); // no one wins, no one loses money
	string ShowResults();
	void ClearHands();
	bool IsLogOpened() { return log.IsLogOpen(); }
	void EndGame();
private:
	int bet{ 0 };
	double money{ 1000.0 };
	int wins, losses, ties, numberOfHands;
	Deck deck;
	Hand playersHand, dealersHand;
	Logger log;
};