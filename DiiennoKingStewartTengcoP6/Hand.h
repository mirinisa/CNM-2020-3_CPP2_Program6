#ifndef _HAND_H
#define _HAND_H

#include "Card.h"
#include <array>
#include <string>
using namespace std;

const int MAX_CARDS{ 12 };

class Hand
{
public:
	Hand() { ; }
	void AddCard(Card c);
	string Show(bool isdealer, bool hideFirstCard);
	bool BlackJack();
	bool Under(int n);
	int BestScore();
	bool MustHit();
	bool Busted(); // checks BestScore() against 22
	bool Busted(int score); // checks parameter against 22
	void ClearHand();
private:
	int numCards{ 0 };
	string showHand;
	array<Card, MAX_CARDS> cards;
	//int SumPoints(); // adds points in hand, always aces = 1
};

#endif /* _HAND_H */