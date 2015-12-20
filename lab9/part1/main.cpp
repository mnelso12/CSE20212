// main.cpp

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "cardDeck.h"

using namespace std;

int main() {

    srand(time(NULL));

    CardDeck a; // uses default constructor
    cout << "Before shuffle:" << endl;
    cout << a;
    
    // Checks if a is in order
    if (a.inOrder() == 1 ){
        cout << "A is in order." << endl;
    }
    else {
        cout << "A is NOT in order." << endl << endl;
    }
    // shuffles a
    a.shuffle();

    cout << "After shuffle:" << endl;
    cout << a;
    /*
    CardDeck b(10);
    cout << "Deck B, non-default constructor of 10 cards." << endl;
    cout << "Before shuffle:" << endl;
    cout << b; // demonstrates overloaded << operator
    b.shuffle(); // shuffles deck
    cout << "After shuffle:" << endl;
    cout << b; // demonstrates overloaded << operator

    cout << endl << endl;
*/
    // Checks if A is in order
    if (a.inOrder() == 1 ){
        cout << "A is in order." << endl;
    }
    else {
        cout << "A is NOT in order." << endl << endl;
    }
    /*
    if (b.inOrder() == 1 ){
        cout << "B is in order." << endl;
    }
    else {
        cout << "B is NOT in order." << endl << endl;
    }
    */
    return 0;

}
