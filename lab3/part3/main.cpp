// main.cpp

#include "OvernightPackage.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include <iostream>
#include <vector> 

using namespace std;

int main(void) {

    TwoDayPackage G; // uses default values
    TwoDayPackage H("Charlie Geary", "Satan", 46556, 66666, "115 Cavanaugh Hall, Notre Dame, IN", "Hell", 6);
    TwoDayPackage J("Susie Q.", "Santa", 12345, 60148, "1 Pleasant Street, Smalltown, Sunshine State", "North Pole", 1.76);
    OvernightPackage A; // uses default values
    OvernightPackage B("Fr. Jenkins", "Jesus", 46556, 33333, "700 Hesburgh Library, Notre Dame, IN", "Heaven", 100.2);
    OvernightPackage C("Manti Teo", "Girlfriend",46556, 32953, "315 Duncan Hall, Notre Dame, IN", "Nowhere", -1*.5); // tests the negative input
    // changes negative weight input to positive version
    // error message is displayed right at the beginning of the output

    vector<Package*>  dayArr(6); // vector of packages
    dayArr[0] = &G;
    dayArr[1] = &H;
    dayArr[2] = &J;
    dayArr[3] = &A;
    dayArr[4] = &B;
    dayArr[5] = &C;

    double totalCost=0;

    for(int i=0; i<6; i++) { // loops through vector of packages
        totalCost+= (*dayArr[i]).print(); // calls print function of each
        // calculates totalCost
    }

    cout << "Total Cost: $" << totalCost << endl; // displays total cost
    return 0;
}
