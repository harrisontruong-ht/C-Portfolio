//=============================================================================
//file: Calc.cpp
//=============================================================================
//Programmer: Harrison Truong
//Date: 09/28/25
//Class: CSCI 123 ("Introduction to Programming using C++")
//Time: Online
//Instructor: Dr. Rodriguez
//Project: Calc
//Description:
//       This program will perform basic arithmetic operations
//       (addition, subtraction, multiplication, and division)
//       on two integer values provided by the user.
//
//=============================================================================

#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

//function prototypes
void Sum(int first, int second, int &sum);
void Difference(int first, int second, int &difference);
void Product(int first, int second, int &product);
void Quotient(int first, int second, int &quotient, int &remainder);

//===== main ==================================================================
//
//=============================================================================

int main()
{
    int first; //local variables
    int second;
    int total;
    int remainder;
    char continueCalc;

    do
    {
        cout << "Please enter two integer values seperated by whitespace: ";
        cin >> first;
        cin >> second;
        cout << "\nHere are the results: " << endl;

        Sum(first, second, total); //function calls
            cout << first << " + " << second << " = " << total << endl;

        Difference(first, second, total);
        cout << first << " - " << second << " = " << total << endl;

        Product(first, second, total);
            cout << first << " * " << second << " = " << total << endl;

            Quotient(first, second, total, remainder);
                if(second != 0)
                {
                        cout << first << " / " << second << " = " << total
                                 << " with a remainder of " << remainder << endl;
                }


        cout << "\nWould you like to try different numbers (Y/N)? ";
        cin >> continueCalc;

    } while (toupper(continueCalc) == 'Y');

    exit(0);


} //end of "main"



//=== Sum =====================================================================
//
// This function will take two integer values as input and calculate
// their sum. It will then display the result.
//
// Input:
//         first, second, sum [IN] == two integer values provided by the user
//                                 and an integer variable to store the sum
//                                                                      (reference variable)
//
// Output:
//         [OUT] == the sum of the two integer values will be displayed
//=============================================================================

void Sum(int first, int second, int &sum)
{
    sum = first + second;
}



//=== Difference ===============================================================
//
// This function will take two integer values as input and calculate
// their difference. It will then display the result.
//
// Input:
//        first, second, difference [IN] == two integer values provided by the
//                                                              user and an integer variable to store the
//                                                              difference (reference variable)
//
// Output:
//         [OUT] == the difference of the two integer values will be displayed
//==============================================================================
void Difference(int first, int second, int &difference)
{
    difference = first - second;
}



//=== Product ==================================================================
//
// This function will take two integer values as input and calculate
// their product. It will then display the result.
//
// Input:
//         first, second, product [IN] == two integer values provided by the user
//                                   and an integer variable to store the product
//                                                                      (reference variable)
//
// Output:
//         [OUT] == the product of the two integer values will be displayed
//==============================================================================
void Product(int first, int second, int &product)
{
    product = first * second;
}



//=== Quotient =================================================================
//
// This function will take two integer values as input and calculate
// their quotient and remainder. It will then display the result.
//
// Input:
//         first, second, quotient, remainder [IN] == two integer values
//                                               provided by the user and
//                                               two integer variables to store
//                                               the quotient and remainder
//                                                                             (reference variables)
//
// Output:
//         [OUT] == the quotient and remainder of the two integer values
//                   will be displayed
//==============================================================================
void Quotient(int first, int second, int &quotient, int &remainder)
{
        if(second == 0)
        {
                cout << "Division by 0 is undefined..." << endl;
        }
        else
        {
                quotient = first / second;
        remainder = first % second;
        }
}
