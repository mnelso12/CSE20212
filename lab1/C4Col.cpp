// C4Col.cpp
// Madelyn Nelson

#include <iostream>
#include "C4Col.h"
#include "C4Board.h"
#include <cstdlib> // for rand function in computer player

using namespace std;

C4Col::C4Col() { // constructor
    maxDiscs = 6;
    numDiscs = 0;
    discs = new char[6];

    for (int i=0; i<maxDiscs; i++) {
        discs[i]=' ';
    }
}

C4Col::~C4Col() { // deconstructor needed because new and delete are used
    delete[] discs;
}


int C4Col::isFull(void) { // column is full

    if ( numDiscs == maxDiscs ) {
        return 1; // full returns 1
    }
    else {
        return 0;
    }
}

char C4Col::getDisc(int a) { // returns disc in that locationi
    if (discs[a] == ' ') {
        // error message for this function is accounted for instead in the if
        // loops inside didWin() below.
    }
    return discs[a]; // returns disc[a] whether or not there is a disc
}

int C4Col::getMaxDiscs(void) { // returns number of rows
    return maxDiscs;
}

int C4Col::addDisc(char newDisc) {
    if (isFull()) {
        cout << " Error in addDisc. Row is full." << endl;
        return 0;
    }
    else {
        discs[numDiscs] = newDisc;
        numDiscs++;
        return 1;
    }
}

// board methods

C4Board::C4Board() {
    columns = 7;
}

void C4Board::display(void) { // c++ lets us initialize variables in a for loop! yay!
    cout << endl << "Enter -1 to end the game." << endl; 
    cout << "0   1   2   3   4   5   6" << endl; // number labels
    cout << "===========================" << endl; // aesthetics
    for (int j = myBoard[0].getMaxDiscs() - 1; j>=0; j--) {
        for (int k=0;k<columns;k++) {
            cout << myBoard[k].getDisc(j) << " | ";
        }
        cout << endl;
    }
    cout << "===========================" << endl;
}

int C4Board::didWin(int player) { // if 4 in a row, return 1; else return 0
    int g, col; // local variables

    // Horizontal
    for (col=0; col<(columns-3); col++ ) { // accounts for first(left) 4 columns
        for (g=0; g<myBoard[0].getMaxDiscs(); g++ ) { // runs through each row
            if (myBoard[col].getDisc(g) == myBoard[col+1].getDisc(g) && 
                    myBoard[col].getDisc(g) == myBoard[col+2].getDisc(g) 
                    && myBoard[col].getDisc(g) == myBoard[col+3].getDisc(g) 
                    && myBoard[col].getDisc(g) != ' '){
                return 1; 
            }
        }
    }

    // Vertical
    for (col=0; col<(columns); col++ ) { // accounts for all columns
        for (g=0; g<myBoard[0].getMaxDiscs()-3; g++ ) { // checks bottom four rows
            if (myBoard[col].getDisc(g) == myBoard[col].getDisc(g+1) && 
                    myBoard[col].getDisc(g) == myBoard[col].getDisc(g+2) 
                    && myBoard[col].getDisc(g) == myBoard[col].getDisc(g+3)
                    && myBoard[col].getDisc(g) != ' '){
                return 1; 
            }
        }
    }

    // Diagonal North West
    for (col=0; col<(columns-3); col++ ) { // accounts for first 4 columns
        for (g=0; g<myBoard[0].getMaxDiscs()-3; g++ ) { // runs through bottom three rows
            if (myBoard[col].getDisc(g) == myBoard[col+1].getDisc(g+1) && 
                    myBoard[col].getDisc(g) == myBoard[col+2].getDisc(g+2) 
                    && myBoard[col].getDisc(g) == myBoard[col+3].getDisc(g+3)
                    && myBoard[col].getDisc(g) != ' '){
                return 1; 
            }
        }
    }

    // Diagonal South West
    for (col=0; col<(columns-3); col++ ) { // accounts for first 4 columns
        for (g=3; g<myBoard[0].getMaxDiscs(); g++ ) { // runs through top three rows
            if (myBoard[col].getDisc(g) == myBoard[col+1].getDisc(g-1) && 
                    myBoard[col].getDisc(g) == myBoard[col+2].getDisc(g-2) 
                    && myBoard[col].getDisc(g) == myBoard[col+3].getDisc(g-3)
                    && myBoard[col].getDisc(g) != ' '){
                return 1; 
            }
        }
    }
    return 0;
}


void C4Board::play() {

    int turn = 0;
    int player, col, disc, error;

    while (1) { // every iteration is a turn

        display();
        player = (turn % 2) + 1; // player is incremented


        cout << "It's Player " << player << "'s turn." << endl; // player enters move

        if (player == 1) { // human player
            cin >> col;
        }
        else { // computer player
            col = rand() % 7; // range from 0 to 6
            // possible error of row being full is accounted for later
        }

        if (col == -1) { // -1 quits the game
            break;
        }

        while (col < 0 || col > 6) { // error message loop if input is invalid
            // this can only happen on the human player's turn, so cin works
            cout << endl << "Error. Invalid input. Must be between 0 and 6." << endl;
            cout << "It's Player " << player << "'s turn." << endl;
            cin >> col;
        }

        if ( player == 1 ) {
            disc = 'X'; 
        }
        else {
            disc = 'O';
        }

        error = myBoard[col].addDisc(disc); // equals 0 if addDisc didn't work
        if ( error == 0 ) {
            cout << endl << "Error. Could not add disc. Enter again." << endl;
            turn--; // same player's turn again
        }

        // Checks to see if player's last move won the game
        // only if turn >= 7, first time either player can win
        if ( turn >=7 ) {
            if ( didWin(player) ) {
                cout << "PLAYER " << player << " IS VICTORIOUS!!!!!!" << endl;          
                display(); // display winning board
                break;
            }
        }

        if ( turn == 42 ) { // all spaces are full
            cout << "Tie. No winner" << endl;
            break;
        }
        turn++;

    }
}
