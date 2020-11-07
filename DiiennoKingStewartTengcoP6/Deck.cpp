#include "Deck.h"
#include<chrono>
Deck::Deck()
{
	//seed the random_engine object
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->cards.begin(), this->cards.end(), std::default_random_engine(seed));
	topCard = 0;
    //initialize the cards from 0 to 52
    for (int i = 0; i < 52; i++) {
        cards[i] = i;
    }
    //shuffle
    Shuffle();
}

void Deck::Shuffle()
{
	for (int i = 0; i < 52; i++) {
        int j = i + (RandomCard() % (52 - i));
        swap(cards[i], cards[j]);
	}
}

int Deck::RandomCard()
{
	//returns a random int using uniform distributuion
    //needs more work
    uniform_int_distribution<int> distribution(0, 51);
	return distribution(engine);
}

void Deck::Deal(Card& c)
{
	c = cards[topCard];
    topCard++;
    if (topCard <= 34) {
        Shuffle();
        topCard = 0;
    }
}
