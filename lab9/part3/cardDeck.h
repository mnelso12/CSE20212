// cardDeck.h

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
#include <cstdlib>
#include "NDVector.cpp"

using namespace std;

class CardDeck{
    friend ostream &operator<< (ostream &, CardDeck);
    public:
        CardDeck(); // default constructor, assumes n=52
        CardDeck(int); // non-default, int = number of cards
        int getSize(); // returns size of current deck
        void shuffle(); // shuffles deck
        int inOrder(); // returns 1 if elements are in non-dec order, else 0
        void printDeck(ostream &); // prints deck
    private:
        int n; // number of cards
        NDVector<int> myVec; // deque of cards
};

#endif
