// blackjack.cpp

#include <iostream>
#include <deque>
#include "blackjack.h"
#include <cstdlib>
#include <algorithm> // random_shuffle
#include <ctime> // srand()

using namespace std;

CardDeck::CardDeck(){ // default creates real deck of cards
    srand(time(0));
    n = 52; // default number of cards = 52
    int i,cardVal; // counter

    for (cardVal=2;cardVal<10;cardVal++){ // each card between 2 and 9 inclusive
        for (i=0;i<4;i++){ // has four copies of it for each suit
            myDeque.push_back(cardVal);
        }
    }
    for (i=0;i<15;i++) {
        myDeque.push_back(10); // there are sixteen cards per deck that
        // have a value of ten
    }
    for (i=0;i<4;i++) {
        myDeque.push_back(11); // four aces, always valued at 11
    }

}

CardDeck::CardDeck(int n){ // user picks number of cards
    srand(time(0)); // changes random number seed for shuffle()
    if (n<1) {
        n=52; // in case user inputs 0 or a negative number
    } // this no longer pushes any integers back, only in main
}

int CardDeck::getSize() {
    return myDeque.size();
}

void CardDeck::shuffle() {
    random_shuffle(myDeque.begin(),myDeque.end()); // built-in random generator
}

int CardDeck::inOrder() {
    int ans=1; // answer to be returned
    deque<int>::const_iterator i; // forward iterators
    deque<int>::const_iterator temp;
    for (i=myDeque.begin();i!=myDeque.end();++i) {
        if((i+1)==myDeque.end()) {
            temp=i; // if last term, doesn't compare to 0
        }
        else {
            temp=i+1; // temp = next term
        }
        if (*i<=*temp) {
            ans*=1;
        }
        else {
            ans*=0;
        }
    }
    return ans; // =1 if in non-decreasing order, =0 if not
}

void CardDeck::printDeck(ostream & out) { // prints deck
    deque<int>::const_iterator i; // forward iterator
    for (i=myDeque.begin();i!=myDeque.end();++i) {
        if ((i+1)==myDeque.end()) {
            cout << *i << endl;
        }
        else {
            cout << *i << ", ";
        }
    }
}

ostream &operator<< (ostream &out, CardDeck c) {
    c.printDeck(out);
}

int CardDeck::getCard(int cardNum) { // cardNum starts at 0
    deque<int>::const_iterator count; // forward iterator
    count=myDeque.begin(); // starts count at beginning of deck
    int temp=0;
    while (temp<cardNum) {
        ++count;
        temp++;
    }

    return *count; // returns first value of deck
}

void CardDeck::printMenu() {
    cout << endl << "===========================================" << endl;
    cout << "Let's play blackjack. " << endl;
    cout << "Rules:" << endl;
    cout << "1. Aces are always 11" << endl;
    cout << "2. Dealer takes up cards until 17 or higher" << endl;
    cout << "3. Enter q to quit" << endl;
    cout << "4. In a push, keep bet but dealer wins" << endl;
    cout << "5. All bets are assumed to be $5" << endl;
    cout <<  "===========================================" << endl;
}

int CardDeck::sumDeck() { // calculates sum of values of cards in deck
    int sum=0;
    deque<int>::const_iterator i; //forward iterator
    for (i=myDeque.begin();i!=myDeque.end();++i) {
        sum += *i; // adds each card value in deck
    }
    return sum;
}

void CardDeck::addCard(int card) { // adds card to deck
    myDeque.push_back(card);
}
