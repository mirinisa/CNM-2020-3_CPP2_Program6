//Donald DiIenno ddiienno@cnm.edu
//Program #6: BlackJack
//Card.cpp

#include "Card.h"

// n is integer 0-51 corresponding to position
// in the deck; calculate which card it is in
// this constructor (initialize points value,
// face value/type and suit)
Card::Card(int n)
{
	// gives 0-3
	int iSuit = n / 13;
	
	switch (iSuit)
	{
	case 0:
		suit = "Spades";
		break;
	case 1:
		suit = "Hearts";
		break;
	case 2:
		suit = "Clubs";
		break;
	case 3:
		suit = "Diamonds";
	}

	// gives 1-13
	iValue = n % 13 + 1;

	// give face cards a name and change
	// Jack-King iValue to 10
	switch (iValue) {
	case 1:
		value = "Ace";
		break;
	case 2:
		value = "Two";
		break;
	case 3:
		value = "Three";
		break;
	case 4:
		value = "Four";
		break;
	case 5:
		value = "Five";
		break;
	case 6:
		value = "Six";
		break;
	case 7:
		value = "Seven";
		break;
	case 8:
		value = "Eight";
		break;
	case 9:
		value = "Nine";
		break;
	case 10:
		value = "Ten";
		break;
	case 11:
		value = "Jack";
		iValue = 10;
		break;
	case 12:
		value = "Queen";
		iValue = 10;
		break;
	case 13:
		value = "King";
		iValue = 10;
		break;
	}
}
