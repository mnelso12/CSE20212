// OvernightPackage.h

#ifndef OVERNIGHTPACKAGE_H 
#define OVERNIGHTPACKAGE_H 
#include "Package.h"
#include <iostream> 

class OvernightPackage : public Package {

    public:

        OvernightPackage(); // default constructor
        OvernightPackage(string, string, int, int, string, string, double); // non-default constructor
        double calcCost(void);
        virtual double print(); // print function 

    private:

        double overnightCost;

};

#endif
