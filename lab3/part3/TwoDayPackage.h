// TwoDayPackage.h
// inherits from package

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H


#include <iostream>
#include "Package.h"

class TwoDayPackage : public Package {

    public:
    
        TwoDayPackage(); // constructor
        TwoDayPackage(string, string, int, int, string, string, double); 
        double calcCost(void); // also exists in Package.h and OvernightPackage.h
        virtual double print(); // virtual print function

    private:
    
        double twoDayCost;

};

#endif
