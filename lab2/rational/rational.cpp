// rational.cpp
// Madelyn Nelson
// CSE20212 Lab2

#include <iostream>
#include "rational.h"
#include <cmath> // for mod function

using namespace std;

Rational::Rational(void){ // default constructor
    numer = 1;
    denom = 1;
}

Rational::Rational(int numerator, int denomerator){ // other constructor
    numer = numerator;
    denom = denomerator;
}

// Operator Overloading

ostream &operator<<(ostream &output, Rational &B){ // would be display function
    output << "(" << B.numer << "/" << B.denom << ")" << endl;
    return (output);
}

void Rational::operator-=(Rational frac) { // subtracts inputted fraction from given fraction
    int comDenom;
    comDenom = denom*frac.denom;
    numer = denom*frac.numer-numer*frac.denom; // a/b - c/d = (ad-bc)/bd
    denom = comDenom;
}

void Rational::operator+=(Rational frac) { // adds inputted fraction to given fraction
    int comDenom;
    comDenom = denom*frac.denom;
    numer = numer*frac.denom + denom*frac.numer; // a/b + c/d = (ad+bc)/bd
    denom = comDenom;
}

void Rational::operator*=(Rational frac) { // adds inputted fraction to given fraction
    numer = numer*frac.numer; // a/b + c/d = (ad+bc)/bd
    denom = denom*frac.denom;
}

void Rational::operator/=(Rational frac) { // adds inputted fraction to given fraction
    numer = numer*frac.denom; // times by reciprocal
    denom = denom*frac.numer;
    int temp;
    temp = numer;
    numer = denom;
    denom = temp;
}

void Rational::operator==(Rational frac) { // sets A equal to B
    numer = frac.numer; // fraction A's num = B's num
    denom = frac.denom; // fraction A's den = B's den
}

/*
// this function is for future use, I left it here just in case I come back to
// it someday
float Rational::distance(Rational frac) {
    float dist,x,y;
    x = numer/denom;
    y = frac.numer/frac.denom;
    dist = pow(pow(x,2)+pow(y,2),.5);
    return dist;
}
*/


// Mathematical Functions that use Overloaded Operators

void Rational::recipProd(Rational frac) { // reciprocal of product
    (*this)*=frac; // finds product of two rationals
    int temp;
    temp = numer; // switches numerator and denomerator
    numer = denom;
    denom = temp;
}

double Rational::difDivRational(Rational frac) { // calculates the difference
    int count=0;
    while (count < 10) { // 10 is fast and sufficient
        if (count%2 == 0) { // every other time
            (*this)-=frac; // subtracts other fraction
            cout << "(" << numer << "/" << denom << ")" << endl;
        }
        else {
            (*this)/=frac; // divides by other fraction
            cout << "(" << numer << "/" << denom << ")" << endl;
        }
        count++;
    } 
    return (numer/denom);
}

double Rational::limit(Rational frac) {
    int count=0;
    frac.numer = numer; // sets values of inputted frac equal to 
    frac.denom = denom; // those from current object
    while (count<5) { // raises fraction to power of count
        (*this)*=frac; // uses *= overloaded operator
        count++; // pretty inefficient, but accurate
    }
    if (numer/denom < 1 &&  numer/denom > -1){ // should be very small or very large
        return 0;
    }   
    else if (numer/denom > 1) {
        return 10000000; // arbitrarily large number, ~= inf
    }
    else {
        return 1; // only other possibility of what a limit can equal here
    }
}

void Rational::addRational(Rational frac) {
    (*this)+=frac; // uses +=
}

void Rational::divRational(Rational frac) {
    (*this)/=frac; // uses /=
}

void Rational::setEqual(Rational frac) {
    (*this)==frac; // uses ==
}

void Rational::simplify(void){
    for (int i=numer; i>=2; i--) { // starts at top and works down
        if (numer%i==0 && denom%i==0) { // gets rid of factors
            numer/=i;
            denom/=i;
        }
    }
}

int Rational::checkDenomZero(void) {
   if (denom==0) {
       return 1; // returns 1 if denomerator equals zero
    }
   else {
        return 0;
   }
}
// Play method: checks div/0, simplifies, and displays fractions

void Rational::play(){
    
    if (checkDenomZero() == 1) {
        cout << "Error. Divide by Zero." << endl;
    }
    simplify();
    cout << (*this); // equivalent of would be display function
}
