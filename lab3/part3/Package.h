// Package.h

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

using namespace std;

// BASE CLASS
class Package {

    public:
    
        Package(); // default constructor
        Package(string,string,int,int,string,string,double); // constructor with input values
        double calcCost(void);
        double getCostPerOunce();
        double getWeight();
        virtual double print() = 0; // prints package information without cost

    protected: // so child classes can access them easily
        
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
