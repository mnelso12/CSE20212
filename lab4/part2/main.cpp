// main.cpp

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "cardDeck.h"

using namespace std;

int main() {

    CardDeck a; // uses default constructor
    cout << "Deck A, default constructor:" << endl;
    cout << a; 

    cout << endl << endl; 

    CardDeck b(10); // non-default constructor
    cout << "Deck B, non-default constructor of 10 cards." << endl;
    cout << "Before shuffle:" << endl;
    cout << b; // demonstrates overloaded << operator
    b.shuffle(); // shuffles deck
    cout << "After shuffle:" << endl;
    cout << b; // demonstrates overloaded << operator

    cout << endl << endl;

    // Checks if A and B are in order
    if (a.inOrder() == 1 ){
        cout << "A is in order." << endl;
    }
    else {
        cout << "A is NOT in order." << endl << endl;
    }
    
    if (b.inOrder() == 1 ){
        cout << "B is in order." << endl;
    }
    else {
        cout << "B is NOT in order." << endl << endl;
    }
    
    return 0;
}
