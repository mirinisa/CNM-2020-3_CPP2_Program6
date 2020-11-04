#include "Deck.h"

Deck::Deck()
{
	//seed the random_engine object
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->cards.begin(), this->cards.end(), std::default_random_engine(seed));
    //initialize the cards from 0 to 51
    for (int i = 0; i < 51; i++) {
        cards[i];
    }
    //shuffle
    Shuffle();
}

void Deck::Shuffle()
{
	for (int i = 0; i < (52 - 1); i++) {
        int j = i + (rand() % (52 - i));
        swap(cards[i], cards[j]);

        //if both cards are the same reshuffle again
        if (i == j) {
            Shuffle(); 
        }
	}
}

int Deck::RandomCard()
{
	//returns a random int using uniform distributuion
    //needs more work
    uniform_int_distribution<int> distribution(0, 51);
	return 0;
}

void Deck::Deal(Card& c)
{
	 Card deal;
    deal = cards[topCard];
    topCard++;
    if (topCard <= 34) {
        Shuffle();
        topCard = 0;
    }
}
