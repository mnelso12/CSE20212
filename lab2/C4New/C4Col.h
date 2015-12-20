// C4Col.h

#ifndef C4Col_H
#define C4Col_H

#include <iostream>

using namespace std;

class C4Col {
    public:
        C4Col(); // constructor
//        ~C4Col(); // deconstructor, don't need because overloading instead
        int isFull(void); // column is full
        char getDisc( int); // gets the disc in that spot
        int getMaxDiscs( void); // returns the max number of iscs, max number of rows
        int addDisc(char); // adds char representing disc to next open spot in array
        C4Col operator +=(char);  
    private:
        int numDiscs; // number of discs in each column
        int maxDiscs; // same as number of rows
        char *discs;  // pointer because memory allocation, new/delete in .cpp
};
#endif
