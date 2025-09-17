// ============================================================================
// file: piCalc.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 09/20/25
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: Pi Calculation
//
// Description:
//      This program calculate the value of pi through iteration or
// approximation.
//
// ============================================================================

#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

// Function Prototypes
void    Iterate(int iter);
void    DecimalApprox(int approx);
void    DisplayPi(int signif, double pi);

// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        char calcType; // variables
        int numIterations;
        int numApprox;

        // Prompt the user if they want to iterate or have a decimal approx.
        cout << "\nThis program calculates the number Pi.\n\n";

        // Create a do while loop to prompt the user for Iteration or Approx.
        // Loop until the user enters the correct selection
        
        do
        {
            cout << "Would you like to calculate it through I>teration or ";
            cout << "A>pproximation: ";
            cin >> calcType;
            if(toupper(calcType) != 'I' && toupper(calcType) != 'A')
            {
                cout << "Incorecct Selection. Try again..." << endl;
            }
        } while (toupper(calcType) != 'I' && toupper(calcType) != 'A');


        // If it is iteration, ask how many iterations and call the
        // Iterate function.
        if (toupper(calcType) == 'I')
        {
                // Prompt the user of how many iterations
                cout << "How many iterations?: ";
                cin >> numIterations;

                // Call the Iterate function
                Iterate(numIterations);
        }
        // If it is approximation, ask the number of approximation and call
        // the DecimalApprox function
        else if (toupper(calcType) == 'A')
        {
                // Prompt the user of decimal approximation
                cout << "How many decimals of approximation?: ";
                cin >> numApprox;

                // Call the DecimalApprox function
                DecimalApprox(numApprox);
        }
        return 0;
}   // end of "main"



// ==== Iterate ===============================================================
//
// This function calcuates pi through iteration
//
// Input:
// iter [IN] -- an integer value containing the number of iterations
//
// Output:
// The value of pi.
//
// ============================================================================

void    Iterate(int iter)
{
        int counter = 0; // variables
        double total = 0.0;

        // do a loop to calculate pi based on the number of iterations
        while(counter < iter)
        {
            total += 4*(pow(-1,0)/((2*(counter))+1)); // calculate PI

            // increment counter
            counter++;
        }

        // Call the DisplayPi function.
        // default to 5 digit significance for iteration
        DisplayPi(5, total);

} // end of "Iterate"



// ==== DecimalApprox ==========================================================
//
// This function calcuates pi through decimal approximation
//
// Input:
// approx [IN] -- an integer value containing the approximation
//
// Output:
// The value of pi.
//
// ============================================================================

void    DecimalApprox(int approx)
{
        // variables
        double  piVal = 0.0;              // Pi value
        double  previousPi = piVal;     // Previous pi value
        int i = 0;

        // loop to calculate pi based on the approx value of signif. digits.
        do{
            piVal += 4*(pow(-1,0)/((2*(i))+1));// calculate PI
            
                // check if the significance has changed within 1 decimial approx.
                // if so break out of the loop
                if (abs(piVal - previousPi) <= pow(10.0, -1.0 * approx))
                {
                    break;
                }

            // update previousPi and increment i
            previousPi = piVal;
            i++;
        } while (true);

        // Call the DisplayPi function.
        // default to approx digit significance for iteration
        DisplayPi(approx, piVal);

} // end of "DecimalApprox"



// ==== DisplayPi =============================================================
//
// This function displays the value of pi.
//
// Input:
// signif [IN] -- an integer value containing the number of digit significance
// pi     [IN] -- a double value containing the value of pi.
//
// Output:
// void
//
// ============================================================================

void    DisplayPi(int signif, double pi)
{
        // settings for digit precision
        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(signif);

        // display the value of pi
        cout << "The value of Pi is: " << pi << endl << endl;
} // end of "DisplayPi"
