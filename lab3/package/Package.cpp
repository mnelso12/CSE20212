//package.cpp
//Madelyn Nelson and Vanice Cheung

#include <iostream>
#include <iomanip>
#include "Package.h"

using namespace std;

Package::Package() {
    costPerOunce = .50; // initialized at $.50
    weight = 4.;
}

Package::Package(double w) {
    weight = w;
    costPerOunce = .50; 
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
