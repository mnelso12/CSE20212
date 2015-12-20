// Package.h

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

using namespace std;

//class TwoDayPackage; // do I need this?

// BASE CLASS
class Package {
    public:
        Package();
        Package(double);
        double calcCost(void);
//        virtual void calcCost(void) = 0; // virtual void function

        double getCostPerOunce();
        double getWeight();
    private:
        string name_sender;
        string name_rec;
        int zip_sender;
        int zip_rec;
        string adr_sender;
        string adr_rec;
        double weight; // can't be negative
        double costPerOunce; 

};

#endif
