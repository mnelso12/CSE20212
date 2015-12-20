// main.cpp CSE20212 Lab9, Part3

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "cardDeck.h"
#include <exception>

using namespace std;

int main() {

    try { // tries to create an array that is way too big
        NDVector<int> bazillion(100000000000000000000);
    }
    catch(exception& e) {
        NDVector<int> bazillion(10);
    }

    NDVector<int> Empty(0);

    try { // tries pop_back on empty array
        Empty.pop_back();
    }
    catch(int j) {
        if (j == 20) {
            cout << "Tried to remove element from empty array" << endl;
        }
    }

    try { // tries accessLast on empty array
        Empty.accessLast();
    }
    catch(int l) {
        if ( l == 20 ) {
            cout << "Tried to access last element of empty array" << endl;
        }
    }
    
    try { // tries accessFront on empty array
        Empty.accessFront();
    }
    catch(int k) {
        if ( k == 20 ) {
            cout << "Tried to access front element of empty array" << endl;
        }
    }
    return 0;
}
