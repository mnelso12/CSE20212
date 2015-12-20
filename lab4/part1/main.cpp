// Vector.h
// Part 1
// Determines if user inputted value is a palindrome

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> intVec;
    vector<int> tempVec;

    int a,b,c,d,e,pal=1; // user input integers, pal for palindrome tester

    cout << "Enter your five digit integer:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;

    intVec.push_back(a);
    intVec.push_back(b);
    intVec.push_back(c);
    intVec.push_back(d);
    intVec.push_back(e);
    
    cout << endl;
    
    // compares backwards vector to forwards vector
    vector<int>::const_iterator i;
    vector<int>::const_reverse_iterator s;
    s = intVec.rbegin();
    for (i = intVec.begin(); i != intVec.end(); ++i) {
        if (*i == *s) { // if backwards term = forwards term 
            pal*=1; // keeps pal = 1;
        }
        else {
            pal*=0; // makes pal permanently = 0
        }
        ++s;
    } 
    if (pal==1) {
        cout << "Is palindrome" << endl; // is this how you spell it?
    }
    else {
        cout << "Is NOT palindrome" << endl;
    }
}
