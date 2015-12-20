// blackjack.h

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <deque>
#include <cstdlib>

using namespace std;

class CardDeck{
    friend ostream &operator<< (ostream &, CardDeck); // overloaded
    // operator, calls printDeck method
    public:
        CardDeck(); // default constructor, assumes n=52, sets equal to real deck
        CardDeck(int); // non-default, int = number of cards
        int getSize(); // returns size of current deck
        void shuffle(); // shuffles deck
        int inOrder(); // returns 1 if elements are in non-dec order, else 0
        void printDeck(ostream &); // prints deck
        int getCard(int); // gets cards
        void printMenu(); // prints info for user
        int sumDeck(); // counts sum of card values in deck
        void addCard(int); // adds card to deck
    private:
        int n; // number of cards
        deque<int> myDeque; // deque of cards
};

#endif
