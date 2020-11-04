#include "Card.h"

Card::Card()
{

}

// n is integer 0-51 corresponding to position
// in the deck; calculate which card it is in
// this constructor (initialize points value,
// face value/type and suit)
iValue = n % 13 + 1;
    if (iValue > 10) {
        iValue == 10;
    }
Card::Card(int n)
{
	/* Testing */
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
	stringstream ss;
	ss << iValue << "-" << suit;
	string result(ss.str());
}
