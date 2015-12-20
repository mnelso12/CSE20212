// OvernightPackage.cpp

#include<iostream>
#include "OvernightPackage.h"
#include "Package.h"
using namespace std;

OvernightPackage::OvernightPackage() : Package(){
}

OvernightPackage::OvernightPackage(double weight) : Package(weight){
    overnightCost = 10.00;
}

double OvernightPackage::calcCost(void){
    double temp = overnightCost + Package::calcCost();
    return temp;
}

