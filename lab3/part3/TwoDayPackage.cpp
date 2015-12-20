// TwoDayPackage.cpp

#include <iostream>
#include "TwoDayPackage.h"
#include "Package.h"

using namespace std;

TwoDayPackage::TwoDayPackage() : Package() {
    twoDayCost = 5.00;
}


TwoDayPackage::TwoDayPackage(string sendName, string recName, int sendZip, int recZip, string sendAdr, string recAdr, double weight)  : Package( sendName, recName, sendZip, recZip, sendAdr, recAdr, weight )
{
    twoDayCost = 5.00; // two day cost initialized at $5
}


double TwoDayPackage::calcCost(void) {
    double temp = twoDayCost+Package::calcCost();
    return temp;
}

double TwoDayPackage::print() {

    cout << endl << "Package Cost: $" << calcCost() << endl; // these variables are accesible
    cout << "================================" << endl;      // because we use protected instead
    cout << "Sender Name: " << name_sender << endl;          // of private in Package.h
    cout << "Zip Code: " << zip_sender << endl;
    cout << "Address: " << adr_sender << endl << endl;
    cout << "Recipient Name: " << name_rec << endl;
    cout << "Zip Code: " << zip_rec << endl;
    cout << "Address: " << adr_rec << endl << endl;
    cout << "Package Weight: " << weight << "oz "<< endl;
    cout << "================================" << endl << endl;
    cout << endl;
    return calcCost(); // returns calcCost so can be added to total cost in main

}
