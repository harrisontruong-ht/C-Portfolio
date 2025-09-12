//=============================================================================
//file: cashRegisterFunc.cpp
//=============================================================================
//Programmer: Harrison Truong
//Date: 09/09/25
//Class: CSCI 123 ("Introduction to Programming using C++")
//Time: Online
//Instructor: Dr. Rodriguez
//Project: Cash Register Function
//Description:
//
//
//
//=============================================================================

#include <iostream>
#include <cctype>
using namespace std;

//function prototypes
double ItemScan(int numItems);
void Payment(char paymentType);

double total;

//===== main ==================================================================
//
//=============================================================================

int main()
{
    int numItems;
    char paymentType;

    cout << "How many items?: ";
    cin >> numItems;
    total = ItemScan(numItems);

    //set output two decimal places
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "\nSubtotal: $" << total << endl;
    cout << "Tax(7.75%): $" << total * 0.0775 << endl;
    cout << "Total: $" << total * 1.0775 << endl << endl;
    cout << "Cash or credit? Enter 'C' for Cash or 'T' for Credit: ";
    cin >> paymentType;

    Payment(paymentType);

} //end of "main"



//=== ItemScan ================================================================
//
// This function will take the number of items scanned as input. It will then
// calculate and return the total(double datatype).
//
// Input:
//         numItems [In] == an integer value that contains the numbere of items
//                          the user is paying for
//
// Output:
//         The total cost of all the items added together and rounded to two
//         decimal values.(will return a double datatype)
//=============================================================================

double ItemScan(int numItems)
{
    double total = 0.0;
    double price;
    int itemCount = 1;

    while(itemCount <= numItems)
    {
        cout << "Please enter the cost of item #" << itemCount << ": $";
        cin >> price;
        total += price;
        itemCount++;
    }

    return total;
} //end of "Item Scan"



//=== Payment =================================================================
//
// This function will take the payment type as input. It will then display a
// message based on the payment type.
//
// Input:
//         paymentType [In] == a character value that contains the type of
//                             payment the user is using. (C for cash and T
//                             for credit card)
// Output:
//         A message that corresponds to the payment type.
//=============================================================================

void Payment(char paymentType)
{


    if(toupper(paymentType) == 'C')
    {
        double cash;

        cout << "\nCash: $";
        cin >> cash;

                if(cash < total * 1.0775)
                {
                        do
                    {
                        cout << "Please enter the correct amount of cash: $";
                        cin >> cash;
                    } while (cash < total * 1.0775);
                }

        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(2);

        cout << "Change: $" << cash - (total * 1.0775) << endl;
    }
    else if(toupper(paymentType) == 'T')
    {
        cout << "Card Payment: $" << total * 1.0775 << endl;
    }
    else
    {
        cout << "Incorrect selection..." << endl;
    }
} //end of "Payment"
