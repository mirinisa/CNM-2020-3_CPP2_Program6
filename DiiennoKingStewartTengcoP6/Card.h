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
	string GetValue() const { return value; } // Get face value
	string GetSuit() const { return suit; }
private:
	int iValue; // int points value
	string value; // face value (name)
	string suit;
};


#endif /* _CARD_H */