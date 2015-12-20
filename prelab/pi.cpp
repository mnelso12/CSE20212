/* Madelyn Nelson, Fund Comp II CSE20212 Prelab, 1-19-2015
User enters term number, program outputs corresponding estimation of pi using
Taylor Series */

#include <iostream>
#include <cmath> // for pow function

using namespace std;

int main() {

    int term;
    int i=1; // variable in for loop, hence boring name
    float pi=4; // first value for pi is 4

    cout << "Enter term number you want: "; // user prompted to enter a number of terms
    cin >> term;

    while (term<2) { // error message loop if user enters a number <= 2
        cout << "Error! Provided value must be >= 2. Enter again" << endl;
        cin >> term;
    }
        cout << "Estimate after 1 term(s): " << pi << endl;   

    for(i=1;i<=term;i++) { // calculates pi term by term
        pi += 4/(pow(-1,i)*(1+2*i));    // pow function alternates sign   
        cout << "Estimate after " << (i+1) << " term(s): " << pi << endl;   
    }

    return 0;
}

