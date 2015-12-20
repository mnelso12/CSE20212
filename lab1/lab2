// connectfour.h

#ifndef C4Col_H
#define C4Col_H

using namespace std;

class C4Col {
    public:
        C4Col(); // constructor
        ~C4Col(); // deconstructor
        int isFull(void); // column is full
        char getDisc(int); // gets the disc in that spot
        int getMaxDiscs(void); // returns the max number of discs, max number of rows
        int addDisc(char); // adds char representing disc to next open spot in array
    private:
        int numDiscs; // number of discs in each column
        int maxDiscs; // same as number of rows
        char *discs;  // pointer because memory allocation, new/delete in .cpp
};
#endif
