// Madelyn Nelson
// C4Board.h

#ifndef C4BOARD_H
#define C4BOARD_H

#include "C4Col.h"
#include <iostream>

using namespace std;

class C4Board {
    friend ostream& operator<<(ostream &, C4Board &);
    public:
        C4Board(); // constructor
//        void display(); // displays current board
        void play(); // allows player and computer to play a game
        int didWin(int); // checks if given player got 4 in a row
    private:
        int columns;
        C4Col myBoard[7]; // array of objects of type column
};

#endif

