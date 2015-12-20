// monkeySort.cpp

#include <iostream>
#include <deque>
#include "monkeySort.h"
#include <cstdlib>
#include <algorithm> // random_shuffle
#include <ctime> // srand()

using namespace std;

CardDeck::CardDeck(){
    srand(time(0));
    n = 52; // default number of cards = 52
    int i; // counter
    for (i=0;i<n;i++){
        myDeque.push_back(i); // cards numbered from 0 to 51
    }
}

CardDeck::CardDeck(int n){ // user picks number of cards
    srand(time(0)); // changes random number seed for shuffle()
    if (n<1) {
        n=52; // in case user inputs 0 or a negative number
    }
    int i; // counter
    for (i=0;i<n;i++){
        myDeque.push_back(i); // cards numbered from 0 to (n-1)
    }
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
