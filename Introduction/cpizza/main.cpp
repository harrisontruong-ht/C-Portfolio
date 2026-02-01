// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/30/25
// Project: CPizza Destructors
//
// Description:
//      In this proogram we created a CPizza class and practice using
//              constructors, destructors, and dynamic memory allocation.
//
// ============================================================================

#include <iostream>
#include <cstring>
#include "cpizza.h"
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        // Member variables
        CPizza  Order1; // default
        int LPizza;
        int MPizza;
        int SPizza;
        char name[256];
        char input;

        // prompt the user for their pizzas and assign to private members
        cout << "Will this be for delivery (Y/N)? ";
        cin >> input;
        if(toupper(input) == 'Y')
        {
                Order1.SetDelivery(true);
        }
        else
        {
                Order1.SetDelivery(false);
        }

        cout << "How many large pizzas? ";
        cin >> LPizza;
        Order1.SetLPizza(LPizza);

        cout << "How many medium pizzas? ";
        cin >> MPizza;
        Order1.SetMPizza(MPizza);

        cout << "How many small pizzas? ";
        cin >> SPizza;
        Order1.SetSPizza(SPizza);

        cout << "What is your name? ";
        cin.ignore();
        cin.getline(name, 256);
        Order1.SetName(name);

        // calculate the cost for order 1
        Order1.CalcCost();

        // create a second object by calling the type constructor
        // and only providing a name as an argument
        CPizza  Order2("Thanos");

        // create a third object by calling the copy constructor and providing
        // order1 as an argument
        CPizza  Order3(Order2);

        // change the name and set 1 for each size of the pizza and no delivery
        Order3.SetName("Deadpool");
        Order3.SetLPizza(1);
        Order3.SetMPizza(1);
        Order3.SetSPizza(1);

        // display the orders
        cout << "Order 1: \n\n";
        Order1.DispOrder();

        cout << "Order 2: \n\n";
        Order2.DispOrder();

        cout << "Order 3: \n\n";
        Order3.DispOrder();

        return 0;
}  // end of "main"
