//package.cpp
//Madelyn Nelson and Vanice Cheung

#include <iostream>
#include <iomanip>
#include "Package.h"

using namespace std;

Package::Package() {
    name_sender = "Vanice Cheung";
    name_rec = "Madelyn Nelson";
    zip_sender = 60137;
    zip_rec = 46556;
    adr_sender = "2S151 Churchill Lane, Glen Ellyn, IL";
    adr_rec = "328 Badin Hall, Notre Dame, IN";
    costPerOunce = .50; // initialized at $.50
    weight = 4.; // default is >0, needs no test
}

Package::Package( string sendName, string recName, int sendZip, int recZip, string sendAdr, string recAdr, double w) {
    if (w<0) { // error checks
        cout << "You entered weight = " << w << ". We changed it to " << -1*w << ". You're welcome." << endl;
        w=(-1)*w; // clearly the user meant a positive version of the weight
                    //  instead of negative
    }
    name_sender = sendName;
    name_rec = recName;
    zip_sender = sendZip;
    zip_rec = recZip;
    adr_sender = sendAdr;
    adr_rec = recAdr;
    weight = w;
    costPerOunce = .50; // cost per ounce cannot be inputted by user
                        // is set by company instead
}

double Package::calcCost(void) {
    return costPerOunce*weight;
}

double Package::getCostPerOunce(void) {
    return costPerOunce;
}

double Package::getWeight(void) {
    return weight;
}




double Package::print(void) {
    /*
    cout << "================================" << endl;
    cout << "Sender Name: " << name_sender << endl;
    cout << "Zip Code: " << zip_sender << endl;
    cout << "Address: " << adr_sender << endl << endl;

    cout << "Recipient Name: " << name_rec << endl;
    cout << "Zip Code: " << zip_rec << endl;
    cout << "Address: " << adr_rec << endl << endl;

    cout << "Package Weight: " << weight << "oz "<< endl;
    cout << "================================" << endl << endl;

    cout << endl;
*/

	return 0;
}
