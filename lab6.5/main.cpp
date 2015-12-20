// main.cpp

#include<iostream>
#include"sudoku.h"
#include<fstream>

using namespace std;

int main(){

    Puzzle<int> a; // sudoku puzzle of ints
    a.printBoard(); // prints board

    int count,f;

    for (f=0; f<10; f++) {
        
        count=0;
        while (count<50) {
            a.checkValid();
            a.checkDoneRow();
            a.printBoard();
            count++;
        }

        count=0;
        while (count<50) {
            a.singletonRow();
            a.printBoard();
            count++;
        }

        count=0;
        while (count<50) {
            a.checkValid();
            a.checkDoneRow();
            a.printBoard();
            count++;
        }

        count=0;
        while (count<50) {
            a.singletonCol();
            a.printBoard();
            count++;
        }
        
        count=0;
        while (count<50) {
            a.checkValid();
            a.checkDoneRow();
            a.printBoard();
            count++;
        }
        count=0;
        while (count<50) {
        //    a.singletonBox();
            a.printBoard();
            count++;
        }

        count=0;
        while (count<50) {
            a.checkValid();
            a.checkDoneRow();
            a.printBoard();
            count++;
        }
    }
    return 1;
}

