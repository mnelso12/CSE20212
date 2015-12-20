// main.cpp for rational
// Madelyn Nelson
// CSE20212 Lab2

#include <iostream>
#include "rational.h"

using namespace std;

int main(void) {

    int tempnum, tempdenom;
    char input;
    while (1) {
        // user inputs A

            cout << "Enter a rational number." << endl;
            cout << "Numerator: ";
            cin >> tempnum;
            cout << "Denomerator: ";
            cin >> tempdenom;

            Rational fractionC(tempnum,tempdenom); // creates first object

            // inputs B

            cout << "Enter a rational number." << endl;
            cout << "Numerator: ";
            cin >> tempnum;
            cout << "Denomerator: ";
            cin >> tempdenom;

             Rational fractionD(tempnum,tempdenom); // creates second object

                        cout << "Rational A: ";
                          fractionC.play(); // simplifies fractions, checks for /0, displays
                          cout << "Rational B: ";
                          fractionD.play();

        if (fractionC.checkDenomZero()==1 || fractionD.checkDenomZero()==1) {
            // error message is displayed in play method
            // this forces the user to enter different values
            continue; // jumps to next iteration of while loop
            // avoids menu because 0 denomerator would be a mess
        }

        char c;
        // menu of user options
        cout << endl << "Press..." << endl;
        cout << "'a' to add rationals A and B" << endl;
        cout << "'p' for product of reciprocals A and B" << endl;
        cout << "'l' for limit as rational A  is raised to inf" << endl;
        cout << "'d' for alternately dividing and subtracting the rationals" << endl;
        cout << "'q' to quit" << endl;
        cout << "'e' to set rational A equal to rational B" << endl << endl;
        cin >> c;

        if (c=='q') { // quit option
            break;
        }
        else if (c=='a') {
            fractionC.addRational(fractionD); // a/b + c/d -> (ad+bc)/bd
            fractionC.play();
        }
        else if (c=='p') { // a/b and c/d -> bd/ac
            fractionC.recipProd(fractionD);
            fractionC.play();
        }
        else if (c=='l') {
            double lim;
            lim = fractionC.limit(fractionD);
            cout << "limit: " << lim << endl;
        }
        else if (c=='d') {
            double ans;
            ans = fractionC.difDivRational(fractionD); // this function
            // displays the rational through each iteration
            cout << endl << "Approximation:" <<  ans << endl;
        }
        else if (c=='e') {
            fractionC.setEqual(fractionD);
            cout << "rational A: ";
            fractionC.play();
        }
        else {
            cout << "Error. Invalid input." << endl;
            break; // prompts user to re-enter values, start while loop again
        }
        cout << endl << "Again! Again!" << endl << endl;

    }
}

