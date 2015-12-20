// OvernightPackage.h

#ifndef OVERNIGHTPACKAGE_H 
#define OVERNIGHTPACKAGE_H 
#include "Package.h"
#include <iostream> 

class OvernightPackage : public Package {

    public:
        OvernightPackage(); // default constructor
        OvernightPackage(double);
        double calcCost(void);
    
    private:
        double overnightCost;
};

#endif
