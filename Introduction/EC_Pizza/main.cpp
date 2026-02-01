// =============================================================
// file: main.cpp
// =============================================================
// Programmer: Harrison Truong
// Date: 11/23/25
// Project: CPizza Demonstration
// Description:
//      This program demonstrates the CPizza class by creating
//      multiple CPizza objects using different constructors,
//      prompting the user for an order, calculating costs,
//      and displaying the order details.
// =============================================================
#include <iostream>
#include "cpizza.h"
using namespace std;

int main()
{
        CPizza  order1; // default CTOR

        order1.promptOrder();

        CPizza order2(2,1,3); // type CTOR
        CPizza order3(order2); //copy CTOR

        order1.calcCost();
        order2.calcCost();
        order3.calcCost();

        cout << "\nOrder 1:\n\n";
        order1.dispOrder();

        cout << "\nOrder 2:\n\n";
        order2.dispOrder();

        cout << "\nOrder 3:\n\n";
        order3.dispOrder();

        return 0;
}
