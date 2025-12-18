// ============================================================================
// file: studentGrades.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/2/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: CGrade
//
// Description:
//      This program calculates and displays students’ final grades based on
//              two quizzes, a midterm, and a final exam. Using the `CGrade` class,
//              it takes input, computes weighted percentages, assigns letter grades,
//              and outputs each student’s name, percentage, and grade.
//
// ============================================================================

#include <iostream>
#include "cgrade.h"
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
        char name[] = "Edgar Allen Poe";
        CGrade  S1;             // first student
        CGrade  S2(name, 0.0, 0.0, 0.0, 0.0, 0.0, 'F'); // second student
        CGrade  S3(S2);                 // copy of the second student

        // Display the default constructor info
        cout << "\n The grades of S1 (default constructor):\n";
        S1.DispGrade();

        // prompt the user for name/grades
        cout << "\nInfo for S1:\n";
        S1.GetInfo();

        // call the function to calculate percent/grade
        S1.CalcGrade();

        // display their grades
        cout << "\n The grades of the students are:\n";
        S1.DispGrade();
        S2.DispGrade();
        S3.DispGrade();

        return 0;
}   // end of "main"
