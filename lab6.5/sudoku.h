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
        int checkValid(); // loops through each cell, checks if possiblities are
        // vaid for that spot
        int checkDoneRow(); // checks if any new rows are complete, updates board
        int singletonRow();
        int singletonCol();
        int singletonBox();
    private:
        vector<vector <T> > grid; // from Sakai
        vector<vector <T> > startGrid; // copy of original grid
        vector<vector<vector <int> > > possible; // 3D vector of 0's and 1's
};

#endif
template<typename T>
int Puzzle<T>::singletonBox(){

    int single=0,xval=0,yval=0;
    for (xval=0;xval<3;xval++) { // varies which box is considered
        for (yval=0;yval<3;yval++){ 
            vector <int> tempVec; // vector of stored values
            for (int i=(2*xval); i<(3*xval); i++) { // makes vector of all possible values in spots in box
                for (int j=(2*yval); j<(3*yval); j++) { 
                    //    cout << "grid[" << j << "][" << i << "]";
                    for (int k=0; k<9; k++) {
                        if (possible[j][i][k]==1 && grid[j][i]==0){
                            tempVec.push_back(k+1); // pushes back possible value in this row
                        }
                    }
                }
            }
            for (int g=0; g<tempVec.size();g++) {
                //       cout << " " << tempVec[g] << " ";
            }
            //    cout << endl << endl;
            int count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0;
            for (int p=0; p < tempVec.size(); p++) {
                if (tempVec[p]==1) count1++;
                else if (tempVec[p]==2) count2++;
                else if (tempVec[p]==3) count3++;
                else if (tempVec[p]==4) count4++;
                else if (tempVec[p]==5) count5++;
                else if (tempVec[p]==6) count6++;
                else if (tempVec[p]==7) count7++;
                else if (tempVec[p]==8) count8++;
                else if (tempVec[p]==9) count9++;
                else {
                    //      cout << "There is an issue with your tempVec." << endl;
                }
            }
            if (count1==1) {
                //    cout << "count1=" << count1 << endl;
                single=1;
            }
            else if (count2==1) {
                //    cout << "count2=" << count2 << endl;
                single=2;
            }
            else if (count3==1) {
                //   cout << "count3=" << count3 << endl;
                single=3;
            }
            else if (count4==1) {
                //   cout << "count4=" << count4 << endl;
                single=4;
            }
            else if (count5==1) {
                //  cout << "count5=" << count5 << endl;
                single=5;
            }
            else if (count6==1) {
                //    cout << "count6=" << count6 << endl;
                single=6;
            }
            else if (count7==1) {
                //      cout << "count7=" << count7 << endl;
                single=7;
            }
            else if (count8==1) {
                //        cout << "count8=" << count8 << endl;
                single=8;
            }
            else if (count9==1) {
                //          cout << "count9=" << count9 << endl;
                single=9;
            }
            else {
                //            cout << "single=0" << endl;
                single=0;
            }

            for (int m=(2*xval); m<(3*xval); m++) {
                for (int n=(2*yval); n<(3*yval); n++) {
                    if (possible[m][n][single-1]==1){ // if the unique value is a possibility for this spot, 
                        grid[m][n]=single; // the grid is updated accordingly
                        //                cout << "grid[" << n << "][" << i << "] is updated to " << single << " SINGLETON COL" << endl;
                        return 1;
                    }
                }
            }
        }
    }
}
template<typename T>
int Puzzle<T>::singletonCol(){

    int single=0;
    // check row
    for (int i=0; i<9; i++) { // makes vector of all possible values in spots of row
        vector <int> tempVec; // vector of stored values
        for (int j=0; j<9; j++) { 
            //            cout << "grid[" << j << "][" << i << "]";
            for (int k=0; k<9; k++) {
                if (possible[j][i][k]==1 && grid[j][i]==0){
                    tempVec.push_back(k+1); // pushes back possible value in this row
                }
            }

            //            cout << endl << "tempVec= ";
            /*        vector<int>::const_iterator g;
                      for (int g = tempVec.begin(); g != tempVec.end(); ++g) {
                      cout << " " << *g << " ";
                      }
                      */
            for (int g=0; g<tempVec.size();g++) {
                //                cout << " " << tempVec[g] << " ";
            }
            //            cout << endl << endl;
        }
        int count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0;
        for (int p=0; p < tempVec.size(); p++) {
            if (tempVec[p]==1) count1++;
            else if (tempVec[p]==2) count2++;
            else if (tempVec[p]==3) count3++;
            else if (tempVec[p]==4) count4++;
            else if (tempVec[p]==5) count5++;
            else if (tempVec[p]==6) count6++;
            else if (tempVec[p]==7) count7++;
            else if (tempVec[p]==8) count8++;
            else if (tempVec[p]==9) count9++;
            else {
                //        cout << "There is an issue with your tempVec." << endl;
            }
        }
        if (count1==1) {
            //      cout << "count1=" << count1 << endl;
            single=1;
        }
        else if (count2==1) {
            //     cout << "count2=" << count2 << endl;
            single=2;
        }
        else if (count3==1) {
            //       cout << "count3=" << count3 << endl;
            single=3;
        }
        else if (count4==1) {
            //         cout << "count4=" << count4 << endl;
            single=4;
        }
        else if (count5==1) {
            //         cout << "count5=" << count5 << endl;
            single=5;
        }
        else if (count6==1) {
            //         cout << "count6=" << count6 << endl;
            single=6;
        }
        else if (count7==1) {
            //         cout << "count7=" << count7 << endl;
            single=7;
        }
        else if (count8==1) {
            //         cout << "count8=" << count8 << endl;
            single=8;
        }
        else if (count9==1) {
            //         cout << "count9=" << count9 << endl;
            single=9;
        }
        else {
            //        cout << "single=0" << endl;
            single=0;
        }

        for (int n=0; n<9; n++) {
            if (possible[n][i][single-1]==1){ // if the unique value is a possibility for this spot, 
                grid[n][i]=single; // the grid is updated accordingly
                //              cout << "grid[" << n << "][" << i << "] is updated to " << single << " SINGLETON COL" << endl;
                return 1;
            }
        }
    }
}


template<typename T>
int Puzzle<T>::singletonRow(){
    // cout << "ENTERS SINGLETON ROW!" << endl;
    int single=0;
    // check row
    for (int i=0; i<9; i++) { // makes vector of all possible values in spots of row
        vector <int> tempVec; // vector of stored values
        for (int j=0; j<9; j++) { 
            //    cout << "grid[" << i << "][" << j << "]";
            for (int k=0; k<9; k++) {
                //       cout << "k=" << k << endl;
                if (possible[i][j][k]==1 && grid[i][j]==0){
                    tempVec.push_back(k+1); // pushes back possible value in this row
                    //           cout << "pushes back " << (k+1) << endl;
                }
            }
            // PRINTS TEMPVEC
            //     cout << endl << "tempVec= ";
            for (int g=0; g<tempVec.size();g++) {
                //       cout << " " << tempVec[g] << " ";
            }
            //     cout << endl << endl;
        }
        // CHECKS FOR REPEATS/UNIQUE VALUES
        int count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0;
        for (int p=0; p < tempVec.size(); p++) {
            if (tempVec[p]==1) count1++;
            else if (tempVec[p]==2) count2++;
            else if (tempVec[p]==3) count3++;
            else if (tempVec[p]==4) count4++;
            else if (tempVec[p]==5) count5++;
            else if (tempVec[p]==6) count6++;
            else if (tempVec[p]==7) count7++;
            else if (tempVec[p]==8) count8++;
            else if (tempVec[p]==9) count9++;
            else {
                //    cout << "There is an issue with your tempVec." << endl;
            }
        }
        if (count1==1) {
            //  cout << "count1=" << count1 << endl;
            single=1;
        }
        else if (count2==1) {
            //    cout << "count2=" << count2 << endl;
            single=2;
        }
        else if (count3==1) {
            //      cout << "count3=" << count3 << endl;
            single=3;
        }
        else if (count4==1) {
            //        cout << "count4=" << count4 << endl;
            single=4;
        }
        else if (count5==1) {
            //          cout << "count5=" << count5 << endl;
            single=5;
        }
        else if (count6==1) {
            //            cout << "count6=" << count6 << endl;
            single=6;
        }
        else if (count7==1) {
            //            cout << "count7=" << count7 << endl;
            single=7;
        }
        else if (count8==1) {
            //            cout << "count8=" << count8 << endl;
            single=8;
        }
        else if (count9==1) {
            //            cout << "count9=" << count9 << endl;
            single=9;
        }
        else {
            //            cout << "single=0" << endl;
            single=0;
        }

        for (int n=0; n<9; n++) {
            //            cout << "n=" << n << endl;
            if (possible[i][n][single-1]==1 && grid[i][n]==0){ // if the unique value is a possibility for this spot, 
                grid[i][n]=single; // the grid is updated accordingly
                //                cout << "grid[" << i << "][" << n << "] is updated to " << single << " SINGLETON ROW" << endl;
                return 1;
            }
        }
    }
}


template<typename T>
int Puzzle<T>::checkDoneRow(){

    int sum=0,value=0;
    for (int m=0; m<9; m++) {
        for (int n=0; n<9; n++) {
            for (int p=0; p<9; p++){
                sum += possible[m][n][p];
                if (possible[m][n][p]==1) {
                    value=p+1;
                }
                //                                cout << "possible[" << m << "][" << n << "][" << p << "]= " << possible[m][n][p];
                //                                cout << " sum=" << sum << endl;

            }
            if (sum==1 && grid[m][n]==0) {
                grid[m][n]=value;
                //                cout << "grid[" << m << "][" << n << "]"; 
                //                cout << "is changed to =" << (value) << endl;
            }

            sum=0; // reset sum
        }
    }

}

template<typename T>
int Puzzle<T>::checkValid(){

    for (int m=0; m<9; m++) {
        for (int n=0; n<9; n++) {
            for (int p=0; p<9; p++){
                if (grid[m][n]==0) {
                    if (!rowValid(m,p+1)){ // SWITCHED M AND N
                        possible[m][n][p]=0;        
                        //                        cout << "possible[" << m << "][" << n << "][" << p << "]= " << possible[m][n][p];
                        //                        cout << endl << endl;
                    }
                    else if (!colValid(n,p+1)){ // SWITCHED M and N
                        possible[m][n][p]=0;        
                        //                        cout << "possible[" << m << "][" << n << "][" << p << "]= " << possible[m][n][p];
                        //                        cout << endl << endl;
                    }
                    else if (!boxValid(m,n,p+1)){
                        possible[m][n][p]=0;        
                        //                        cout << "possible[" << m << "][" << n << "][" << p << "]= " << possible[m][n][p];
                        //                        cout << endl << endl;
                    }
                }
            }
        }
    }
    // prints updated possible 3D grid
    for (size_t m=0; m < possible.size(); m++){
        for (size_t n=0; n < possible.size(); n++){
            for (size_t p=0; p < possible.size(); p++){
                //                cout << "possible[" << m << "][" << n << "][" << p << "]= " << possible[m][n][p] << endl;
            }
        }
    }


}

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
    // NEW CODE
    for (int m=0; m<9; m++) {
        vector < vector <int> > w;
        possible.push_back(w);
        for (int n=0; n<9; n++) {
            vector <int> v;
            possible[m].push_back(v);
            for (int p=0; p<9; p++){
                if (grid[m][n]==0) { // if value on grid is 0, push back 1 for all
                    possible[m][n].push_back(1);
                }
                else if (grid[m][n]==(p+1)){ // if value on grid is set already
                    possible[m][n].push_back(1);
                }
                else { // value on grid is set already, but is not =p now
                    possible[m][n].push_back(0); 
                }
            }
        }
    }

    for (size_t m=0; m < possible.size(); m++){
        for (size_t n=0; n < possible.size(); n++){
            for (size_t p=0; p < possible.size(); p++){
                //                cout << "possible[" << m << "][" << n << "][" << p << "]= " << possible[m][n][p] << endl;
            }
        }
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
            //            cout << "Error. Row check failed." << endl;
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
            //            cout << "Error. Column check failed." << endl;
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

    for (int i=0; i<3; i++) { // row changes
        for (int j=0; j<3; j++) { // column changes
            tempvec.push_back(grid[rowNum+i][colNum+j]); // stores values of inputted row
        }
    }

    sort(tempvec.begin(), tempvec.begin()+9); // sorts tempvec from 0 to 9
    for (int k=0; k<9; k++){
        //        cout << tempvec[k];
        if(input == tempvec[k]){ // checks if input matches other values in row
            //          cout << "Error. Box check failed." << endl;
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

