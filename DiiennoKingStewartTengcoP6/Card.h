/* Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 *
 * File: Card.h
 * Purpose: Header file for Card object
 * Last modified: 12 Nov 2020
 */


#ifndef _CARD_H
#define _CARD_H

#include <string>
using namespace std;

class Card
{
public:
	Card() = default;
	Card(int n);
	void SetIValue(int val) { iValue = val; } // Set points value
	int GetIValue() const { return iValue; } // Get points value
	string GetValue() const { return value; } // Get pip/face
	string GetSuit() const { return suit; }
private:
	int iValue; // int points value
	string value; // face value (name)
	string suit;
};


#endif /* _CARD_H */