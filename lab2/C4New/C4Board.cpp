// C4Board.cpp
// Madelyn Nelson

#include <iostream>
#include "C4Col.h"
#include "C4Board.h"
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;


C4Board::C4Board() {
    columns = 7;
}

ostream &operator<<(ostream &output, C4Board &B){
    output << endl << "Enter -1 to end the game." << endl;
    output << "0   1   2   3   4   5   6" << endl; // number labels
    output << "===========================" << endl; // aesthetics
    for (int j = B.myBoard[0].getMaxDiscs() - 1; j>=0; j--) {
        for (int k=0;k<B.columns;k++) {
            output << B.myBoard[k].getDisc(j) << " | ";
        }
        output << endl;
    }
    output << "===========================" << endl;
    return (output);
}

/*
   86 void C4Board::display(void) { // c++ lets us initialize variables in
   87     cout << endl << "Enter -1 to end the game." << endl; 
   88     cout << "0   1   2   3   4   5   6" << endl; // number labels
   89     cout << "===========================" << endl; // aesthetics
   90     for (int j = myBoard[0].getMaxDiscs() - 1; j>=0; j--) {
   91         for (int k=0;k<columns;k++) {
   92             cout << myBoard[k].getDisc(j) << " | ";
   93         }
   94         cout << endl;
   95     }
   96     cout << "===========================" << endl;
   97 }
   98 */

int C4Board::didWin(int player) { // if 4 in a row, return 1; else r
    int g, col; // local variables

    // Horizontal
    for (col=0; col<(columns-3); col++ ) { // accounts for first(lef
        for (g=0; g<myBoard[0].getMaxDiscs(); g++ ) { // runs throug
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
        for (g=0; g<myBoard[0].getMaxDiscs()-3; g++ ) { // checks bo
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
        for (g=0; g<myBoard[0].getMaxDiscs()-3; g++ ) { // runs thro
            if (myBoard[col].getDisc(g) == myBoard[col+1].getDisc(g+1) &&
                    myBoard[col].getDisc(g) == myBoard[col+2].getDisc(g+2)
                    && myBoard[col].getDisc(g) == myBoard[col+3].getDisc(g+3)
                    && myBoard[col].getDisc(g) != ' '){
                return 1;
            }
        }
    }

    // Diagonal South West
    for (col=0; col<(columns-3); col++ ) { // accounts for first 4 c
        for (g=3; g<myBoard[0].getMaxDiscs(); g++ ) { // runs throug
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

        //        display();
        cout << *this; // calls the display function
        player = (turn % 2) + 1; // player is incremented

        cout << "It's Player " << player << "'s turn." << endl; // p

        if (player == 1) { // human player
            cin >> col;
        }
        else { // computer player
            col = rand() % 7; // range from 0 to 6
            // possible error of row being full is accounted for lat
        }

        if (col == -1) { // -1 quits the game
            break;
        }

        while (col < 0 || col > 6) { // error message loop if input 
            // this can only happen on the human player's turn, so c
            cout << endl << "Error. Invalid input. Must be between 0 and 6" << endl;
            cout << "It's Player " << player << "'s turn." << endl;
            cin >> col;
        }

        if ( player == 1 ) {
            disc = 'X';
        }
        else {
            disc = 'O';
        }

        error = myBoard[col].addDisc(disc); // equals 0 if addDisc d
        if ( error == 0 ) {
            cout << endl << "Error. Could not add disc. Enter again." << endl;
                turn--; // same player's turn again
        }

        // Checks to see if player's last move won the game
        // only if turn >= 7, first time either player can win
        if ( turn >=7 ) {
            if ( didWin(player) ) {
                cout << "PLAYER " << player << " IS VICTORIOUS!!!!!!" << endl;
                //                display(); // display winning board
                cout << *this; // calls display function
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


