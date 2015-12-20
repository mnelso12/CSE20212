// mortage.h
// Madelyn Nelson CSE20212 Prelab

#include <iostream>

class Mortgage { //  Mortgage class definition
    public:
        Mortgage(); // constructor that uses default values
        Mortgage(double,double,double); // constructor with other values
        void credit(double);
        double getPrincipal(void);
        void amortize(void);
    private:
        double principal; // private variables
        double rate;
        double payment;
};
