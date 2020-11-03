#include "Deck.h"
#include "Hand.h"
#include "Logger.h"
#include <string>
using namespace std;


class Game
{
public:
	Game();
	bool SetBet();
	// pass-through methods
	bool PlayerContinues();
	void PlayerHits();
	string PlayerWins();
	bool DealerContinues();
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