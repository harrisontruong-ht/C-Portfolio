//=============================================================================
//file: cashRegisterFile.cpp
//=============================================================================
//Programmer: Harrison Truong
//Date: 10/04/25
//Class: CSCI 123 ("Introduction to Programming using C++")
//Time: Online
//Instructor: Dr. Rodriguez
//Project: Cash Register File
//Description:
//         This program will read item prices from a file,
//         calculate the subtotal, tax, and total,
//         and handle payment processing.
//         It will also generate a receipt and write it to a file.
//
//=============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//function prototypes
void DisplayItems(double item1, double item2, double item3, ofstream &outFile);
double ItemTotal(double item1, double item2, double item3);
void Payment(char response, double total, ofstream &outFile);


//===== main ==================================================================
//
//=============================================================================

int main()
{

        double item1,item2, item3;
        double total;
        char response;
        ifstream inputFile;
        ofstream outFile;


        outFile.setf(ios::showpoint);
    outFile.setf(ios::fixed);
    outFile.precision(2);
    cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(2);

        inputFile.open("items.txt");
        if(inputFile.fail())
        {
                cout << "Failed to open the input file" << endl;
                exit(EXIT_FAILURE);
        }
        inputFile >> item1 >> item2 >> item3;

        outFile.open("receipt.txt");
        if(outFile.fail())
        {
                cout << "Failed to open the output file" << endl;
                exit(EXIT_FAILURE);
        }

        outFile << "###########################################################\n"
                           << "                          Receipt                          \n"
                           << "###########################################################"
                           << endl;

        DisplayItems(item1, item2, item3, outFile);

        total = ItemTotal(item1, item2, item3);

        cout << "\nSubtotal: $" << total << endl;
        cout << "Tax(7.75%): $" << total*0.0775 << endl;
        cout << "Total: $" << total*1.0775 << endl;

        outFile << "\nSubtotal: $" << total << endl
                           << "Tax(7.75%): $" << total*0.0775 << endl
                           << "Total: $" << total*1.0775 << endl;

        cout << "\nCash or credit? Enter 'C' for Cash or 'T' for Credit: ";
        cin >> response;

        Payment(response, total, outFile);

        outFile.close();
        inputFile.close();
        return 0;
} //end of "main"



//=== DisplayItems ================================================================
//
// This function will take three item prices and an output file stream
// as input. It will display the item prices to the console and
// write them to the output file.
// Input:
//         item1, item2, item3,  [IN] == three double values representing
//                                     the prices of the items
//         outFile [IN] == an output file stream to write the item
//                           prices to
// Output:
//         The item prices will be displayed to the console and written
//         to the output file.
//=============================================================================

void DisplayItems(double item1, double item2, double item3, ofstream &outFile)
{
        cout << "Items:\n";
        outFile << "Items:\n";

        for(int i = 1; i <= 3; i++)
        {
                switch(i)
                {
                        case 1:
                                cout << "\t#1: $" << item1 << endl;
                                outFile << "\t#1: $" << item1 << endl;
                                break;
                        case 2:
                                cout << "\t#2: $" << item2 << endl;
                                outFile << "\t#2: $" << item2 << endl;
                                break;
                        case 3:
                                cout << "\t#3: $" << item3 << endl;
                                outFile << "\t#3: $" << item3 << endl;
                                break;
                }
        }

} //end of "DisplayItems"



//=== ItemTotal ================================================================
//
// This function will take three item prices as input and calculate
// their total. It will then return the total.
//
// Input:
//         item1, item2, item3 [IN] == three double values representing
//                                   the prices of the items
// Output:
//         The total cost of the three items added together and rounded
//         to two decimal values.(will return a double datatype)
//=============================================================================

double ItemTotal(double item1, double item2, double item3)
{
        return (item1 + item2 + item3);
} //end of "ItemTotal"



//=== Payment ================================================================
//
// This function will take a payment type and total amount as input.
// It will then display a message based on the payment type.
//
// Input:
//         response [In] == a character value that contains the type of
//                           payment the user is using. (C for cash and T
//                           for credit card)
//         total [In] == a double value that contains the total amount
//                        the user needs to pay.
//         outFile [In] == an output file stream to write the payment
//                           information to
// Output:
//         A message that corresponds to the payment type.
//=============================================================================

void Payment(char response, double total, ofstream &outFile)
{
        do
        {
                if(toupper(response) == 'C')
                {
                        double cash = 0.0;
                        cout << "Cash: $";
                        cin >> cash;
                        outFile << "\nCash: $" << cash << endl;
                        while(cash < total)
                        {
                                cout << "\nPlease enter the correct amount of cash: $";
                                cin >> cash;
                        }
                        cout << "\nChange: $" << cash - (total*1.0775) << endl;
                        outFile << "Change: $" << cash - (total*1.0775) << endl;

                }
                else if(toupper(response) == 'T')
                {
                        cout << "Card Payment: $" << (total*1.0775) << endl;
                        outFile << "\nCard Payment: $" << total*1.0775 << endl;
                }
                else
                {
                        cout << "Please select the correct options!" << endl;
                        cout << "\n Cash or Credit? Enter 'C' for cash or 'T' for Credit : ";
                        cin >> response;
                }
        } while((toupper(response) != 'C') && (toupper(response) != 'T'));
}
