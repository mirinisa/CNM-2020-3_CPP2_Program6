//Donald DiIenno ddiienno@cnm.edu
//Program #6: BlackJack
// Card.cpp

#include "Card.h"

Card::Card()
{

}

// n is integer 0-51 corresponding to position
// in the deck; calculate which card it is in
// this constructor (initialize points value,
// face value/type and suit)
Card::Card(int n)
{
	 int iSuit = n / 13;
	iValue = n % 13 + 1;
	if (iValue > 10) {
		iValue = 10;
	}
	
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
	switch (iValue) {
	case 0:
		value = "Ace";
		break;
	case 1:
		value = "Two";
		iValue = 2;
		break;
	case 2:
		value = "Three";
		iValue = 3;
		break;
	case 3:
		value = "Four";
		iValue = 4;
		break;
	case 4:
		value = "Five";
		iValue = 5;
		break;
	case 5:
		value = "Six";
		iValue = 6;
		break;
	case 6:
		value = "Seven";
		iValue = 7;
		break;
	case 7:
		value = "Eight";
		iValue = 8;
		break;
	case 8:
		value = "Nine";
		iValue = 9;
		break;
	case 9:
		value = "Ten";
		iValue = 10;
		break;
	case 10:
		value = "Jack";
		iValue = 11;
		break;
	case 11:
		value = "Queen";
		iValue = 12;
		break;
	case 12:
		value = "King";
		iValue = 13;
		break;

	}
	
}
