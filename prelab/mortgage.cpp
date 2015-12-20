// Mortgage.cpp

#include <iostream>
#include <cmath> // math functions
#include "mortgage.h"
#include <iomanip> // library for setwidth function in display table, etc.

using namespace std;

Mortgage::Mortgage() // default constructor
{
    principal = 100000; // initialize at 100k
    rate = 5; // initialize at %5
    payment = 500; // initialize at $500 monthly

}    

Mortgage::Mortgage(double p, double r, double pay) // constructor when user 
{
    if (( pay > (.01*r*p)) && r>=0) {
        principal = p;
        rate = r;
        payment = pay;
    }
    else {
        cout << "Fool you will die of debt, try again" << endl << endl;
    }
}

void Mortgage::amortize() // means once through payment and once through interest
{
    cout << "Month    Payment    Interest   Balance" << endl;

    int month=1; // initialize at the first month
    for(month=1;principal>0;month++) {
        
        cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << month; // month
        cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << payment; // payment
        cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << .01*rate*principal; // interest
        principal += .01*rate*principal; // adds interest
        principal -= payment; // subtracts payment
        cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << principal; // balance
        cout << endl;

        if (payment >= principal) { // this is to prevent negative balances

            float balance = principal;
            float interest = .01*rate*balance;

            // last payment, last row in chart. payment=balance plus last interest

            cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << month+1; // month++ again
            cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << balance+.01*rate*balance; // payment = old principal + new interest
            cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << balance*.01*rate; // interest
            cout << fixed << setprecision(2) << left << setw(10) << setfill(' ') << "0.00" << endl; // last balance = 0
            cout << endl;
            break;
        }
    }    
}

double Mortgage::getPrincipal(void) // accesses private variable
{
    return principal;
}

void Mortgage::credit(double value) // subtracts one payment from balance
{
    principal -= value;
}
