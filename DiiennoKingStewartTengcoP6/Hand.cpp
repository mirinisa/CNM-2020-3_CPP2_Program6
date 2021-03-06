/* Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 * 
 * File: Hand.cpp
 * Purpose: Construct a hand of cards
 * Last modified: 12 Nov 2020
 */


#include "Hand.h"
#include <sstream>

 // assign c to array using index of numCards
void Hand::AddCard(Card c)
{
	// do I need to check max cards here?
	if (numCards < MAX_CARDS)
	{
		cards[numCards] = c;
		// increment numCards
		++numCards;
	}
}


// put either Dealer: or Player: at beginning
// of the string, then add cards held to string
// if hideFirstCard is true, then first card is hidden
string Hand::Show(bool isDealer, bool hideFirstCard)
{
	stringstream ss;
	// index in array of card to be added
	int currentCard{ 0 };

	if (isDealer)
	{
		// first card value if hidden
		if (hideFirstCard)
		{
			ss << "\r\n1. Hidden";
			++currentCard;
		}
	}

	// go through cards array
	for (; currentCard < numCards; ++currentCard)
	{
		// add face value of card
		ss << "\r\n" << (currentCard + 1) << ". " << cards[currentCard].GetValue();
		
		// add suit of card
		ss << " of " << cards[currentCard].GetSuit();
	}

	// Shows best score if not the dealer
	// mainly for debugging purposes, but also
	// helpful for calculating the game
	if (!isDealer)
	{
		ss << "\r\nBest score: " << BestScore();
		if (Busted())
		{
			ss << ". YOU BUSTED!";
		}
	}

	showHand = ss.str();
	return showHand;
}


// "blackjack" is achieved if hand has a total points
// value of 21 with only 2 cards (points value of 21
// on first turn, i.e. Ace + a face card)
bool Hand::BlackJack()
{
	// if hand has only 2 cards and score is 21, hand is Blackjack
	if (numCards == 2 && BestScore() == 21)
	{
		return true;
	}
	
	// if more than 2 cards in hand, or
	// hand total is not 21, no Blackjack
	return false;
}


// add up points in hand and see if they are under n
bool Hand::Under(int n)
{
	if (BestScore() < n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// add up score, check if there is an ace/are aces
// in case >1 ace. add up points with ace = 11
// if hand does not bust, that's a best score
// if it does bust, recalculate with ace = 1
int Hand::BestScore()
{
	// temporary values
	int points{ 0 };
	int numAces{ 0 };
	bool haveAce{ false };

	for (int i = 0; i < numCards; ++i)
	{
		// if card is an ace, increment number of aces
		// and also calculate score using iValue of 11
		if (cards[i].GetValue() == "Ace")
		{
			haveAce = true;
			++numAces;
			points += 11;
		}
		else
		{
			points += cards[i].GetIValue();
		}
	}

	// if busted, recalculate with aces at 1
	if (Busted(points))
	{
		// new variable so we still know how many
		// Aces are in the hand
		int remainingAces = numAces;
		while (remainingAces > 0)
		{
			// change one Ace value to 1
			points -= 10;
			// if this gets us below 22, break the loop
			if (!Busted(points))
			{
				break;
			}
			// otherwise, decrement the remaining aces
			// and loop through again
			else
			{
				--remainingAces;
			}
		}
	}

	return points;
}

// if best score < 17, hit
// should only be called if hand is held by Dealer
// but the spec didn't specify that this method
// should test for that, so I won't
bool Hand::MustHit()
{
	if (BestScore() < 17)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand::Busted()
{
	// busted if score is 22 or over
	return (BestScore() > 21);
}

// overloaded method that tests if a specific 
// score is busted (called in BestScore)
bool Hand::Busted(int score)
{
	return (score > 21);
}

// delete all cards, reset showHand string
// and set number of cards to 0
void Hand::ClearHand()
{
	// reset string
	showHand = "";
	// reset number of cards
	numCards = 0;
}