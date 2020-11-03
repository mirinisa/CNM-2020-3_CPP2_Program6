#ifndef _DECK_H
#define _DECK_H

#include "Card.h"
#include <array>
#include <random>

class Deck
{
public:
	Deck();
	void Shuffle();
	int RandomCard();
	void Deal(Card& c);
private:
	array<int, 52> cards;
	int topCard;
	default_random_engine engine;
};

#endif