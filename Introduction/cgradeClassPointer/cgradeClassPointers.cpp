// ============================================================================
// file: cgradeClassPointers.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/30/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: CGrade
//
// Description:
//      This file contains the implementation of the CGrade class. It defines
//      constructors and member functions to input student information,
//      calculate weighted percentages, determine letter grades, and display
//      results. The program models a simple grading system based on quizzes,
//      a midterm, and a final exam.
//
// ============================================================================

#include "cgradeClassPointers.h"
#include <cstring>
#include <iostream>
using namespace std;



// ==== Default Constructor ===================================================
//
// Description:
//      Initializes a CGrade object with default values. The student’s name
//      is set to “NULL,” all numeric fields are zeroed, and the letter grade
//      is set to ‘F.’
//
// Input:
//      None
//
// Output:
//      None
//
// ============================================================================

CGrade::CGrade(void)
{
        cout << "\nDefault Constructor!" << endl;

        strcpy(m_name, "NULL"); //default values
        m_quiz1 = 0.0;
        m_quiz2 = 0.0;
        m_midterm = 0.0;
        m_finalExam = 0.0;
        m_percent = 0.0;
        m_grade = 'F';
} //end of default constructor



// ==== Type Constructor ======================================================
//
// Description:
//      Initializes a CGrade object with specific values provided for each
//      member variable.
//
// Input:
//      name       -- student's name
//      quiz1      -- first quiz score
//      quiz2      -- second quiz score
//      midterm    -- midterm exam score
//      finalExam  -- final exam score
//      percent    -- overall percentage
//      grade      -- letter grade
//
// Output:
//      None
//
// ============================================================================

CGrade::CGrade(const char name[], double quiz1, double quiz2, double midterm,
           double finalExam, double percent, char grade)
{
        cout << "\nType Constructor!" << endl;

        strcpy(m_name, name); //set values
        m_quiz1 = quiz1;
        m_quiz2 = quiz2;
        m_midterm = midterm;
        m_finalExam = finalExam;
        m_percent = percent;
        m_grade = grade;
} // end of type constructor




// ==== CalcGrade =============================================================
//
// Description:
//      Determines the student’s letter grade based on the calculated percent
//      returned by CalcPercent. Uses standard grading scale (A–F).
//
// Input:
//      None
//
// Output:
//      None
//
// ============================================================================

void CGrade::CalcGrade(void)
{
        CalcPercent(); //calculates percent
        if(m_percent >= 90.0) //if condition to check grade
        {
                m_grade = 'A';
        }
        else if(m_percent >= 80.0)
        {
                m_grade = 'B';
        }
        else if(m_percent >= 70.0)
        {
                m_grade = 'C';
        }
        else if(m_percent >= 60.0)
        {
                m_grade = 'D';
        }
        else
        {
                m_grade = 'F';
        }
} // end of CalcGrade Function



// ==== CalcPercent ===========================================================
//
// Description:
//      Calculates the student’s overall weighted percentage based on the
//      grading policy: quizzes = 25%, midterm = 25%, final exam = 50%.
//
// Input:
//      None
//
// Output:
//      None
//
// ============================================================================

void CGrade::CalcPercent(void)
{
        double final = 0.5*(m_finalExam/100); //weighted average calculation
        double midterm = 0.25*(m_midterm/100);
        double quiz = 0.25*((m_quiz1+m_quiz2)/20);

        m_percent = (final + midterm + quiz)*100;
} //end of CalcPercent function



// ==== DispGrade =============================================================
//
// Description:
//      Displays the student’s name, overall percentage (formatted to one
//      decimal place), and letter grade.
//
// Input:
//      None
//
// Output:
//      Displays student’s grade information to the console.
//
// ============================================================================

void CGrade::DispGrade(ostream &output) const
{
        output.setf(ios::showpoint); //set decimal point to 1
        output.setf(ios::fixed);
        output.precision(1);

        //display output
        output << "\t" << m_name << ": " << m_percent << "% " << m_grade << endl;

}//end of DispGrade function



//=============================================================================
//MakeCGrade
//
//      Input: name[], quiz1, quiz2, midterm, finalExam
//
//      Output: Finds a memory address for the object
//============================================================================
CGrade* MakeCGrade(char name [], double quiz1, double quiz2,
                                   double midterm, double finalExam)
{
        CGrade *ptr = new CGrade(name, quiz1, quiz2, midterm, finalExam);

        if(nullptr == ptr)
        {
                cerr << "Memory Allocation failed";

                delete ptr;
                return nullptr;
        }


        return ptr;
}//end of MakeCGrade



//==============================================================================
//ShowGrade
//
//      Input: *ptr
//
//      Output: Displays the grades of the student(s)
//==============================================================================
void    ShowGrade(CGrade *ptr)
{
        cout << "(Using the Showgrade function...)" << endl;
        ptr->CalcGrade();
        ptr->DispGrade();


}//end of ShowGrade
