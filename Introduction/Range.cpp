//=============================================================================
//file: range.cpp
//=============================================================================
//Programmer: Harrison Truong
//Date: 09/17/25
//Class: CSCI 123 ("Introduction to Programming using C++")
//Time: Online
//Instructor: Dr. Rodriguez
//Project: Range
//Description:
//             This program will display even numbers from 1 to 25
//             even numbers within a specified range and numbers divisible by 
//             a given divisor within a range.
//
//=============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

//function prototypes
void Range();
void Range(int lower, int upper);
void Range(int lower, int upper, int divisor);
void DispVal(int value);

int lower; //global variables
int upper;
int divisor;

//===== main ==================================================================
//
//=============================================================================

int main()
{ 
    cout << "Enter an integer lower and upper boundaries and divisor ";
    cout << "of the range seperated by white space: ";
    cin >> lower;
    cin >> upper;
    cin >> divisor;

    if(static_cast <int> (lower) > static_cast <int> (upper))
    {
        cout << "\nLower number is greater than upper\nExiting...";
        exit(0);
    }

    //calling Range functions
    Range();
    Range(lower, upper);
    Range(lower, upper, divisor);

    return 0;
} //end of "main"



//=== Range ================================================================
//
// This function will take no input and display all even numbers
// between 1 and 25 using the DispVal function.
//
// Input:
//          [IN] == none
//
// Output:
//          [OUT] == All even numbers from 1 to 25 will be displayed
//
//=============================================================================

void Range()
{
    cout << "\nCalling the Range function with no arguments" << endl;
    for(int i = 1; i <= 25; i++)
    {
        if((i % 2) == 0)
        {
            DispVal(i);
        }
    }
    cout << endl;
} //end of "Range"



//=== Range ================================================================
//
// This function will take a lower and upper boundary as input and
// display all even numbers between the two boundaries using
// the DispVal function.
//
// Input:
//          lower, upper [IN] == an integer lower boundary and an 
//                               integer upper boundary
//
// Output:
//          [OUT] == all even numbers between the two boundaries 
//                   will be displayed
//
//=============================================================================

void Range(int lower, int upper)
{
    cout << "\nCalling the Range function with upper and lower arguments" << endl;
    for(int i = lower; i <= upper; i++)
    {
        if((i % 2) == 0)
        {
            DispVal(i);
        }
    }
    cout << endl;
} //end of "Range"



//=== Range ================================================================
//
// This function will take a lower and upper boundary and a divisor.
// It will display all numbers between the two boundaries that are
// divisible by the divisor using the DispVal function.
//
// Input:
//         lower, upper, divisor [IN] == an integer lower boundary, an 
//                                       integer upper boundary, and an 
//                                       integer divisor value to be used 
//                                       for each number in the range
// 
// Output:
//         [OUT] == all numbers between the two boundaries that are
//         divisible by the divisor will be displayed
//
//=============================================================================

void Range(int lower, int upper, int divisor)
{
    cout << "\n Calling the Range function with upper, lower, & divisor arguments" << endl;
    for(int i = lower; i <= upper; i++)
    {
        if((i % divisor) == 0)
        {
            DispVal(i);
        }
    }
} //end of "Range"



//=== DispVal =================================================================
//
// This function will display the value passed to it seperated by a space.
//
// Input:
//         value [IN] == an integer value
//
// Output:
//         [OUT] == the integer value will be displayed
//
//=============================================================================

void DispVal(int value)
{
    cout << value << " ";
} //end of "DispVal"

