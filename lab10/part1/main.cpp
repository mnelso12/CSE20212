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
    CardDeck cards7(7); // 7 cards
    CardDeck cards8(8); // 8 cards
    CardDeck cards9(9); // 9 cards

    do { 
    // monkey stirs with spoon to ensure mixing
    // aka, cards are shuffled
    cards7.shuffle();
    count ++;

    // cards are tested to see if in order
    } while (cards7.inOrder()==0);

    cout << "Number of shuffles for 7 cards = " << count << endl;
    
    count=0;
    do { 
    // monkey stirs with spoon to ensure mixing
    // aka, cards are shuffled
    cards8.shuffle();
    count ++;

    // cards are tested to see if in order
    } while (cards8.inOrder()==0);

    cout << "Number of shuffles for 8 cards = " << count << endl;
    
    count=0;
    do { 
    // monkey stirs with spoon to ensure mixing
    // aka, cards are shuffled
    cards9.shuffle();
    count ++;

    // cards are tested to see if in order
    } while (cards9.inOrder()==0);

    cout << "Number of shuffles for 9 cards = " << count << endl;

    return 0;
}
