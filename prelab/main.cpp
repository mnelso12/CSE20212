// main.cpp

#include <iostream>
#include "mortgage.h"

using namespace std;

int main() {
    
    Mortgage first(2000,5.0,500); // non-default initialization for 2b

    cout << endl;

    Mortgage fail(2000,5.0,5); // payment is too small, displays error message

    Mortgage second; // default constructor initialization, mortgage of $100k for 2c

    cout << endl << endl; // separates parts of rubric

    // demonstrate functions requested in 2d
    second.credit(10000); // credit 10,000 
    cout << "Current balance after crediting second mortgage 10k: " << second.getPrincipal() << endl;
    cout << "Amortization schedule for first mortgage:" << endl;
    first.amortize();

}
