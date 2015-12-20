// main.cpp
// Madelyn Nelson, CSE20212 Lab9

#include <iostream>
#include "NDVector.cpp"

using namespace std;

int main() {
    
    NDVector<int> myVec;
    myVec.push_front(5);
    myVec.push_front(4);
    myVec.printVec();

    cout << endl << endl;
    myVec.push_back(8);
    myVec.printVec();
    
    cout << endl << endl;
    myVec.pop_back();
    myVec.printVec();

    cout << endl << endl;
    cout << "first = " << myVec.accessFront() << endl;
    cout << "last = " << myVec.accessLast() << endl;

    myVec.printVec();

    myVec.clear();
    myVec.printVec();

    cout << endl << endl;
    myVec.push_front(1);
    myVec.printVec();

    return 0;
}
