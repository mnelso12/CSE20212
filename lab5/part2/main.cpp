// main.cpp

#include<iostream>
#include"sudoku.h"
#include<fstream>

using namespace std;

int main(){
    cout << "Hello user. Time to play sudoku." << endl << endl;
    cout << "Type '10' to start over." << endl;
    cout << "File name: test.txt" << endl;
    Puzzle<int> a; // sudoku puzzle of ints
    a.printBoard(); // prints board
    int row,column,value;

    while (1) {
        cout << "Enter a move (row, column, value): " << endl;
        cout << "row: ";
        cin >> row;
        if (row == 10){
            a.startOver(); // sets board equal to original
            a.printBoard(); // prints original board
            continue;
        }
        cout << "column: ";
        cin >> column;
        cout << "value: ";
        cin >> value;

        if (a.inputIsValid(row,column,value)) {
            cout << "Input successful." << endl;
        }
        else {
            cout << "Input unsuccessful." << endl;
        }

        a.printBoard(); // prints new board
        if (a.isDone()) {
            cout << "Congratulations! You are correct." << endl;
            break;
        }

    }
}
/* // wordoku commented out
    cout << "File Names: test.txt for sudoku, testword.txt for wordoku." << endl;
    Puzzle<char> b; // wordoku
    b.printBoard();

    cout << "Hello user. Time to play sudoku." << endl << endl;
    cout << "Type '10' to start over." << endl;
    cout << "File name: test.txt" << endl;
    Puzzle<int> a; // sudoku puzzle of ints
    a.printBoard(); // prints board
    int row,column,value;

    while (1) {
        cout << "Enter a move (row, column, value): " << endl;
        cout << "row: ";
        cin >> row;
        if (row == 10){
            b.startOver(); // sets board equal to original
            b.printBoard(); // prints original board
            continue;
        }
        cout << "column: ";
        cin >> column;
        cout << "value: ";
        cin >> value;

        if (b.inputIsValid(row,column,value)) {
            cout << "Input successful." << endl;
        }
        else {
            cout << "Input unsuccessful." << endl;
        }

        b.printBoard(); // prints new board
        if (b.isDone()) {
            cout << "Congratulations! You are correct." << endl;
            break;
        }

    }
}
*/

