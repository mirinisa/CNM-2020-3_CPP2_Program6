#include "Card.h"

Card::Card()
{

}

Card::Card(int n)
{
	// n is integer 0-51 corresponding to position
	// in the deck; calculate which card it is here
	// (points value, face value/type and suit)

	switch (n)
	{
	case 0:
		value = "Ace";
		iValue = 1;
		suit = "H";
		break;
	case 1:
		value = "Ace";
		iValue = 1;
		suit = "C";
		break;
	case 2:
		value = "7";
		iValue = 7;
		suit = "S";
		break;
	case 3:
		value = "King";
		iValue = 10;
		suit = "D";
		break;
	}
}