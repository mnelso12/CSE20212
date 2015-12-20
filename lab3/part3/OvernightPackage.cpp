// OvernightPackage.cpp

#include<iostream>
#include "OvernightPackage.h"
#include "Package.h"
using namespace std;

OvernightPackage::OvernightPackage() : Package(){
}

OvernightPackage::OvernightPackage(string sendName, string recName, int sendZip, int recZip, string sendAdr, string recAdr, double weight) : Package(sendName, recName, sendZip, recZip, sendAdr, recAdr, weight){
    overnightCost = 10.00;
}

double OvernightPackage::calcCost(void){
    double temp = overnightCost + Package::calcCost();
    return temp;
}

double OvernightPackage::print() {

    cout << endl;
    cout << "Package Cost: $" << calcCost() << endl;    // these variables are accessible
    cout << "================================" << endl; // by using protected instead of private
    cout << "Sender Name: " << name_sender << endl;     
    cout << "Zip Code: " << zip_sender << endl;
    cout << "Address: " << adr_sender << endl << endl; 
    cout << "Recipient Name: " << name_rec << endl;
    cout << "Zip Code: " << zip_rec << endl;
    cout << "Address: " << adr_rec << endl << endl;
    cout << "Package Weight: " << weight << "oz "<< endl;
    cout << "================================" << endl << endl;
    cout << endl;
    return calcCost(); // returns calcCost so can be counted as part of total cost in main

}
