// CreditCard.h

#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <iostream>
#include "BankAccount.h"

using namespace std;

class CreditCard {

    public:
        CreditCard();

    private:
        BankAccount arrayOfAccounts[]; // array of bank account objects

};

#endif
