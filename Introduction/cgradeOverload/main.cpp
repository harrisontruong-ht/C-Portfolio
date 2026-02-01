// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/16/25
// Project: Classes
// Description:
//      The program calculates the grade of students (based on quizes, midterm,
// and final exam).  It uses classes to allocate the space for each student,
// prompts the user for the info, calculates the grade, and displays it on the
// screen. In addition, it introduces the idea of the 3 special constructors.
// This also includes an implmentation of overloading operators and streams.
//
// ============================================================================

#include <iostream>
#include <cstring>
#include "cgradeOverload.h"
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        CGrade  S1;                     // first student
        CGrade  S2("Edgar Allen Poe");  // second student
        CGrade  S3(S2);                 // copy of the second student

        // Display the default constructor info
        cout << "\n The grades of S1 (default constructor):\n";
        cout << S1;

        // prompt the user for name/grades
        cout << "\nEnter student's full name, Quiz 1 grade (out of " << QUIZ1
                 << "),\n" << "Quiz 2 grade (out of " << QUIZ2
                 << "), midterm grade (out of " << MIDTERM << "),\n"
                 << "and final exam grade (out of " << FINAL
                 << "). \n(HIT ENTER AFTER EACH ONE!!!)\n";

        cin >> S1;

        // call the function to calculate percent/grade
        S1.CalcGrade();

        // check if S1 == S2 and S2 == S3
        if (S1 == S2)
        {
                cout << "\nS1 == S2\n";
        }
        else
        {
                cout << "\nS1 != S2\n";
        }

        if (S2 == S3)
        {
                cout << "\nS2 == S3\n";
        }
        else
        {
                cout << "\nS2 != S3\n";
        }

        // display their grades
        cout << "\n The grades of the students are:\n";
        cout << S1;
        cout << S2;
        cout << S3;

        return 0;
}   // end of "main"
