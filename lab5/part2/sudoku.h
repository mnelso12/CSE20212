// sudoku.h, also has .cpp methods

#ifndef SUDOKU_H
#define SUDOKU_H

#include<algorithm>
#include<iostream>
#include<fstream> // file input and output
#include<vector>

using namespace std;

template<typename T> // templated class
class Puzzle {
    public:
        Puzzle(); // default constructor
        //        ~Puzzle(); // deconstructor
        void printBoard(); // prints current board
        int isDone(); // board is completed successfully
        int inputIsValid(int,int,int); // checks if user input fits into the board
        int rowValid(int,int); // checks if row is valid
        int colValid(int,int); // checks if columm is valid
        int boxValid(int,int,int); // checks if box is valid
        int addVal(int,int,int); // adds value to board
        void startOver(); // turns board back into original grid
    private:
        vector<vector <T> > grid; // from Sakai
        vector<vector <T> > startGrid; // copy of original grid
};

#endif

template<typename T>
Puzzle<T>::Puzzle(){ // default constructor

    //user inputs file name
    string fileName;
    cout << "Please enter a file name: ";
    cin >> fileName;

    T value; // temporary variable, value of each
    // location on grid, of type T

    // code from Sakai
    fstream infile;
    infile.open(fileName.c_str());

    // checks if file opened correctly.
    if (infile.is_open() == 0){
        cout << "File could not open correctly." << endl;
    }

    // reads value from file
    int rowNum=0; // counts number of rows
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            infile >> value;
            vector <T> row; // row on grid
            grid.push_back(row); // got this from cplusplus.com
            startGrid.push_back(row);
            grid.at(rowNum).push_back(value); // because the Piazza code doesn't work
            startGrid.at(rowNum).push_back(value); // copy of original grid
        }
        rowNum++;
    }

    infile.close();
    // closes inputted file
}

template<typename T>
void Puzzle<T>::startOver(){
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            grid[i][j]=startGrid[i][j];
        }
    }
}

template<typename T>
int Puzzle<T>::inputIsValid(int rowNum, int colNum, int input){
    if (rowValid(rowNum,input) && colValid(colNum,input) && boxValid(rowNum,colNum,input)) {
        addVal(rowNum,colNum,input); // if correct, adds value to grid    
        return 1; // added successfully
    }
    return 0;
}


template<typename T>
int Puzzle<T>::addVal(int rowNum, int colNum, int input){ // adds input to location on grid
    grid[rowNum][colNum] = input;
    return 1; // returns 1 if value is added successfully
}

template<typename T>
int Puzzle<T>::rowValid(int rowNum, int input){ // returns 1 if row is correct
    vector <T> tempvec;
    for (int j=0; j<9; j++) { // column
        tempvec.push_back(grid[rowNum][j]); // stores values of inputted row
    }

    sort(tempvec.begin(), tempvec.begin()+9); // sorts tempvec from 0 to 9
    for (int k=0; k<9; k++){
//        cout << tempvec[k];
        if(input == tempvec[k]){ // checks if input matches other values in row
            cout << "Error. Row check failed." << endl;
            return 0;
        }
    }
    return 1; // else, returns 1 
}

template<typename T>
int Puzzle<T>::colValid(int colNum, int input){ // returns 1 if col is correct
    vector <T> tempvec;
    for (int j=0; j<9; j++) { // row changes
        tempvec.push_back(grid[j][colNum]); // stores values of inputted row
    }

    sort(tempvec.begin(), tempvec.begin()+9); // sorts tempvec from 0 to 9
    for (int k=0; k<9; k++){
//        cout << tempvec[k];
        if(input == tempvec[k]){ // checks if input matches other values in row
            cout << "Error. Column check failed." << endl;
            return 0;
        }
    }
    return 1; // else, returns 1
}

template<typename T>
int Puzzle<T>::boxValid(int rowNum, int colNum, int input){ // returns 1 if box is correct
    vector <T> tempvec;
    // tests a 3x3 box starting at inputted row,col as the top left corner
    // test to see if input is a valid square

    // determines which box to check
    if (rowNum<3) {
        rowNum = 0;
    }
    else if (rowNum<6) {
        rowNum = 3;
    }
    else {
        rowNum = 6;
    }

    if (colNum<3) {
        colNum = 0;
    }
    else if (colNum<6) {
        colNum = 3;
    }
    else {
        colNum = 6;
    }


//    if (((rowNum)%3 != 0)||((colNum)%3 != 0)||(rowNum>9)||(colNum>9)){
//        cout << "Error. Box input invalid." << endl;
//        return 0;
//    }

    for (int i=0; i<3; i++) { // row changes
        for (int j=0; j<3; j++) { // column changes
            tempvec.push_back(grid[rowNum+i][colNum+j]); // stores values of inputted row
        }
    }

    sort(tempvec.begin(), tempvec.begin()+9); // sorts tempvec from 0 to 9
    for (int k=0; k<9; k++){
//        cout << tempvec[k];
        if(input == tempvec[k]){ // checks if input matches other values in row
            cout << "Error. Box check failed." << endl;
            return 0;
        }
    }
    return 1;
}

template<typename T>
int Puzzle<T>::isDone(){ // returns 1 if board is correct
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if(grid[i][j]==0){ // checks if each is 0
                return 0;
            }
        }
    }
    return 1;
}

/*
   template<typename T>
   Puzzle::~Puzzle() {

   }
   */

template<typename T>
void Puzzle<T>::printBoard(){ // prints sudoku board
    cout << "=========================" << endl;
    for (int i=0; i<9; i++) {
        if (i%3 == 0 && i!=0) {
            cout << "-------------------------" << endl;
        }
        cout << "| ";
        for (int j=0; j<9; j++) {
            cout << grid[i][j] << " "; // prints that value of the vector
            if ((j+1)%3 == 0 && j!=8) {
                cout << "| ";
            }
        }
        cout << "|" << endl; // new line every 9 numbers
    }
    cout << "=========================" << endl;
}

