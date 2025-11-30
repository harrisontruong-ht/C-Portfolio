// ============================================================================
// file: cpizza.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/23/25
// Class: CSCI 123 ("Introduction to Programming using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: Class CPizza Implementation
// Description:
//      This file implements the CPizza class methods, including
//      constructors, order prompting, cost calculation, and order display.
// ============================================================================

#include <iostream>
#include <cstring>
#include "cpizza.h"
using namespace std;




//=== CPizza::CPizza (default constructor) =====================================
//
// This constructor will initialize a CPizza object with default quantities
// for large, medium, and small pizzas.
//
// Input:
//         [IN] == none
//
// Output:
//         The object fields will be initialized to default values.
//         A message "Default Constructor!" will be printed to the console.
//==============================================================================
CPizza::CPizza() //default constructor
{
        cout << "Default Constructor!" << endl;
        m_large = 2;
        m_medium = 1;
        m_small = 3;

} //end of default CTOR




//=== CPizza::CPizza (type constructor) ========================================
//
// This constructor will initialize a CPizza object with the quantities
// provided by the caller.
//
// Input:
//         large  [IN] == number of large pizzas
//         medium [IN] == number of medium pizzas
//         small  [IN] == number of small pizzas
//
// Output:
//         The object fields will be initialized to the provided values.
//         A message "Type Constructor!" will be printed to the console.
//==============================================================================
CPizza::CPizza(int large, int medium, int small) //type constructor
{
        cout << "\nType Constructor!" << endl;
        m_large = large;
        m_medium = medium;
        m_small = small;
} //end of type CTOR




//=== CPizza::CPizza (copy constructor) ========================================
//
// This constructor will create a CPizza object by copying another CPizza
// object's pizza quantities.
//
// Input:
//         cpy [IN] == reference to an existing CPizza object to copy
//
// Output:
//         The object fields will be initialized to the copied values.
//         A message "Copy Constructor!" will be printed to the console.
//==============================================================================
CPizza::CPizza(CPizza &cpy)
{
        cout << "\nCopy Constructor!" << endl;
        m_large = cpy.m_large;
        m_medium = cpy.m_medium;
        m_small = cpy.m_small;
} // end of cpy CTOR




//=== CPizza::promptOrder ======================================================
//
// This function will prompt the user for delivery preference, pizza
// quantities, and the customer's name, and store them in the object.
//
// Input:
//         [IN] == user keyboard input for delivery (Y/N),
//                  large/medium/small quantities, and name
//
// Output:
//         The object's fields (m_delivery, m_large, m_medium, m_small, m_name)
//         will be populated with the user's input.
//==============================================================================
void CPizza::promptOrder()
{
        char input;
        cout << "\nWill this be for delivery (Y/N)? ";
        cin >> input;
        if(toupper(input) == 'Y')
        {
                m_delivery = true;
        }

        cout << "How many large pizzas? ";
        cin >> m_large;

        cout << "How many medium pizzas? ";
        cin >> m_medium;

        cout << "How many small pizzas? ";
        cin >> m_small;

        cout << "What is your name? " ;
        cin.ignore();
        cin.getline(m_name, 256);
} // end of promptOrder




//=== CPizza::calcCost =========================================================
//
// This function will calculate the total cost of the order based on the
// pizza quantities, sales tax, and optional delivery fee.
//
// Input:
//         [IN] == current object state (m_large, m_medium, m_small, m_delivery)
//
// Output:
//         [OUT] == m_cost will be updated with the computed total.
//                  Tax rate applied: 7.75% (1.0775 multiplier)
//                  Delivery fee: $5.00 if delivery is selected.
//==============================================================================
void CPizza::calcCost()
{
        m_cost += ((m_large*20)+(m_medium*15)+(m_small*10))*1.0775;

        if(m_delivery)
        {
                m_cost += 5.00;
        }
} //end of calcCost




//=== CPizza::dispOrder ========================================================
//
// This function will display the customer's name, pizza quantities,
// delivery selection, and total cost to the console.
//
// Input:
//         [IN] == current object state (m_name, m_large, m_medium,
//                  m_small, m_delivery, m_cost)
//
// Output:
//         The formatted order details will be printed to the console,
//         with the total cost shown to two decimal places.
//==============================================================================
void CPizza::dispOrder()
{
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << m_name << endl;
        cout << "\t" << m_large << " Large Pizza(s)" << endl;
        cout << "\t" << m_medium << " Medium Pizza(s)" << endl;
        cout << "\t" << m_small << " Small Pizza(s)" << endl;
        cout << "\t" << "Delivery: ";
        if(m_delivery)
        {
                cout << "Yes" << endl;
        }
        else
        {
                cout << "No" << endl;
        }

        cout << "\n\tTotal Cost: $" << m_cost << endl;
}//end of dispOrder
