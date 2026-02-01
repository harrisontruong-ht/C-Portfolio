// ============================================================================
// file: main.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/30/25
// Project: Classes
//
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
#include "cgradeClassPointers.h"
using namespace std;



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
                char name[256];
                double quiz1;
                double quiz2;
                double midterm;
                double finalExam;
        CGrade  *S1;                     // first student

                cout << "\tEnter student's full name: ";
                cin.getline(name, 256);
                cout << "\tEnter Quiz 1 grade (out of 10): ";
                cin >> quiz1;
                cout << "\tEnter Quiz 2 grade (out of 10): ";
                cin >> quiz2;
                cout << "\tEnter midterm grade (out of 100): ";
                cin >> midterm;
                cout << "\tEnter final exam grade (out of 100): ";
                cin >> finalExam;

                S1 = MakeCGrade(name, quiz1, quiz2, midterm, finalExam);

                ShowGrade(S1);

                cout << "\nThe grades of the student(s) are:" << endl;
                S1->DispGrade();

                delete S1;
                S1 = nullptr;



        // display their grades
       // cout << "\n The grades of the students are:\n";
       // cout << S1


        return 0;
}   // end of "main"
