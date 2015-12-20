// main.cpp

#include "OvernightPackage.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include <iostream>

using namespace std;

int main(void) {

    // Two Day Package tests
    TwoDayPackage A(3.); // tests constructor for Two Day Package
    TwoDayPackage B; // tests default constructor for Two Day Package
    cout << "Total cost of Package A= $" << A.calcCost() << endl;
    cout << "Total cost of Package B= $" << B.calcCost() << endl;

    // Overnight Package tests
    OvernightPackage D(4.); // tests non-default constructor for Overnight Package
    OvernightPackage C; // tests default constructor of Overnight Package
    cout << "Total cost of Package C= $" << C.calcCost() << endl;
    cout << "Total cost of Package D= $" << D.calcCost() << endl;

    return 0;
}
