// rational.h
// Madelyn Nelson 
// CSE20212 Lab2

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational {
    friend ostream& operator<<(ostream &, Rational &); // global because part of iostream

    public:
        Rational(); // constructor
        Rational(int,int); // constructor
        void simplify(void);
        void play(void);
        int checkDenomZero(void);
        
        void operator+=(Rational); // overloading add
        void operator-=(Rational); // overloading sub
        void operator*=(Rational); // overloading mult
        void operator/=(Rational); // overloading div
        void operator==(Rational); // overloading set first equal to second

        void addRational(Rational); // uses +=
        void divRational(Rational); // uses /=
        double difDivRational(Rational); // uses -= and /=
        //float distance(Rational); // just for fun, only for future use
        void recipProd(Rational); // uses *=, finds reciprocal of product
        double limit(Rational); // limit (of product) as approaches inf, uses *=
        void setEqual(Rational); // sets object equal to inputted object's num and den 

    private:
        int numer;
        int denom;
};

#endif
