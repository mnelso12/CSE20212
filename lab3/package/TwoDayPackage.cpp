// TwoDayPackage.cpp

#include <iostream>
#include "TwoDayPackage.h"
#include "Package.h"

using namespace std;

TwoDayPackage::TwoDayPackage() : Package() {
    twoDayCost = 5.00;
}


TwoDayPackage::TwoDayPackage(double weight)  : Package( weight )
{
    twoDayCost = 5.00; // two day cost initialized at $5
}


double TwoDayPackage::calcCost(void) {
//    cout << "twoDayCost=" << twoDayCost << endl;
//    cout << "Package::calcCost=" << Package::calcCost() << endl;
    double temp = twoDayCost+Package::calcCost();
    return temp;
//    return 3.00;
}

/*
void TwoDayPackge::calcCost() {
    cout << "cost per ounce equals " << getCostPerOunce() << endl;
    cout << "weight equals " << getWeight() << endl;
    double temp = getCostPerOunce()*getWeight();
    cout << "total cost = " << temp << endl;
}
*/
