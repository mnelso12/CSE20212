// cardDeck.cpp edited for lab9

#include <iostream>
#include "cardDeck.h"
#include <cstdlib>
#include <algorithm> // random_shuffle
#include <ctime> // srand()

using namespace std;

CardDeck::CardDeck(){
    srand(time(0));
    n = 52; // default number of cards = 52
    int i; // counter
    for (i=0;i<n;i++){
        myVec.push_back(i); // cards numbered from 0 to 51
//        cout << "myVec.push_back(" << i << ") successful" << endl;
    }
}

CardDeck::CardDeck(int num){ // user picks number of cards
    if (num<1) {
        n=52; // in case user inputs 0 or a negative number
    }
    int i; // counter
    for (i=0;i<num;i++){
        myVec.push_back(i); // cards numbered from 0 to (n-1)
    }
    n=num;
}

int CardDeck::getSize() {
    return myVec.getSize();
}

void CardDeck::shuffle() {
    myVec.random_shuffle();
}
/*
void CardDeck::shuffle() {
    //cout << "enters shuffle method" << endl;
    //cout << "n=" << n << endl;
    n=52; // I don't know why I need this
    //cout << "n=" << n << endl;
    NDVector<int> temp;
    for ( int i = 0; i < n; i++ ){ // n default = 52
        temp.push_back(i);  // adds values 0 to 51 to temp vec
    }
    //cout << endl << endl << "prints temp vector: " << endl;
    //temp.printVec(); // prints temp vector to see if it worked
    
    //cout << endl << "myVec has new stuff pushed into it" << endl;

    //cout << "myVec.getSize()=" << myVec.getSize() << endl;
    while (myVec.getSize() < (2*n)) { // keeps going until myVec has all 52 ints
        int randNum = rand()%n; // selects random number
        if (temp[randNum] != -1) { // checks if that num was already used
        //    cout << "myVec.push_back(" << randNum << ")" << endl;
            myVec.push_front(temp[randNum]); // myVec takes this random integer
            temp[randNum]=-1; // marks this value as used
      //      cout << "myVec.getSize()=" << myVec.getSize() << endl;
        }
    }
    //myVec.printVec();
    while(myVec.getSize() > (n)) {
    //    cout << "myVec.getSize()=" << myVec.getSize() << endl;
        myVec.pop_front(); // deletes first n elements
     //   myVec.printVec();
     //   cout << endl;
    }
    //cout << endl << "finished myVec: " << endl;
    //cout << "myVec.getSize()=" << myVec.getSize() << endl;
    //myVec.printVec();
}
*/

int CardDeck::inOrder() {
    int ans=1; // answer to be returned
    int i;
    int temp;
    for (i=0;(i)!=myVec.getSize();++i) {
        if((i+1)==myVec.getSize()) {
            temp=i; // if last term, doesn't compare to 0
        }
        else {
            temp=i+1; // temp = next term
        }
        //        if (*i<=*temp) {
        if ( myVec[i] <= myVec[temp] ) {
            ans*=1;
        }
        else {
            ans*=0;
        }
    }
    return ans; // =1 if in non-decreasing order, =0 if not
}

void CardDeck::printDeck(ostream & out) { // prints deck
    int i;
    //deque<int>::const_iterator i; // forward iterator
    //for (i=myVec.accessFront();(i-1)!=myVec.accessLast();++i) {
/*    for (i=myVec.accessFront();(i-1)!=myVec.accessLast();++i) {
        cout << "last=" << myVec.accessLast() << endl;
        cout << "first=" << myVec.accessFront() << endl;
        if ((i)==myVec.accessLast()) {
                //            cout << *i << endl;
            cout << "myVec[" << i << "]=" << myVec[i] << endl;
        }
        else {
                //            cout << *i << ", ";
            cout << "myVec[" << i << "]=" << myVec[i] << endl ;
        }
    }
*/
    myVec.printVec();

}

ostream &operator<< (ostream &out, CardDeck c) {
    c.printDeck(out);
}
