// main.cpp 
// Madelyn Nelson
// CSE20212 Lab 10

#include"docClass.h"
#include <iostream>

int main(){
    // user enters two file names, either plain .txt or HTML
    string file1,file2;
    cout << "Enter two file names." << endl << "file 1 : ";
    cin >> file1;
    cout << "file 2 : ";
    cin >> file2;
    
    // instantiates file1
    docClass d(file1);
    d.countWords(); // counts words, prints results
    d.printMap();
    
    // instantiates file2
    docClass e(file2);
    e.countWords(); // counts words, prints results
    e.printMap();

    d.jaccard(e.getMap()); // finds jaccard similarity and prints answer
}


