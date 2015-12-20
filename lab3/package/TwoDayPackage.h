// TwoDayPackage.h
// inherits from package

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H


#include <iostream>
#include "Package.h"

//using namespace std;

class TwoDayPackage : public Package {
    public:
        TwoDayPackage(); // constructor
        TwoDayPackage(double); 
        double calcCost(void); // inherited? from Package??
//        virtual void calcCost(); // virtual void function
    private:
        double twoDayCost;

};

#endif
