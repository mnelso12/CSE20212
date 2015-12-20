// main.cpp

#include <iostream>
#include <cstdlib>
#include "monkeySort.h"
#include <deque>
#include <algorithm> // random_shuffle
#include <ctime> // srand

using namespace std;

int main() {
    
    int count=0; // count of shuffles performed
    
    // monkey throws cards into wooden tub
    // aka, the cards are initialized and shuffled
    CardDeck cards(7); // 7 cards

    do { 
    // monkey stirs with spoon to ensure mixing
    // aka, cards are shuffled
    cards.shuffle();
    count ++;
    // cards are tested to see if in order
    } while (cards.inOrder()==0);


    return 0;
}
