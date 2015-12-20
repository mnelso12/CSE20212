// sudoku.cpp
// this file will eventually be put at the end of sudoku.h

#include <iostream>
#include "sudoku.h"
#include <fstream>

using namespace std;

template<typename T>
Puzzle<T>::Puzzle(){

    //user inputs file name
    string fileName;
    cout << "Please enter a file name: ";
    cin >> fileName;

    int value; // temporary variable, value of each
    //                location on grid
    // code from Sakai
    ifstream infile;
    infile.open(fileName.c_str());
    for (int i=0; i<9; i++) {
        for (int j=0; j<0; j++) {
            infile >> value;
            puzzle[i][j] = value;
        }
    }

    infile.close();
    // closes inputted file

}

/*
   template<typename T>
   Puzzle::~Puzzle() {

   }
   */

template<typename T>
void Puzzle<T>::printBoard(){ // prints sudoku board
    for (int i=0; i<9; i++) {
        for (int j=0; j<0; j++) {
            cout << puzzle[i][j]; // prints that value of the vector
        }
        cout << endl; // new line every 9 numbers
    }
}
