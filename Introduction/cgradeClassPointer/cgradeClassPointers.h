// ============================================================================
// File: cgradeClassPointers.h
// ============================================================================
// Programmer: Luciano Rodriguez
// Date: 11/30/25
//
// Description:
//      This is the header file for the CGrade class.
// ============================================================================

#ifndef CGRADE_HEADER
#define CGRADE_HEADER
#include <iostream>
using namespace std;

// constant grade values
const double QUIZ1 = 10;
const double QUIZ2 = 10;
const double MIDTERM = 100;
const double FINAL = 100;

class   CGrade
{
public:
        // constructors
        CGrade();// defualt constructor;
        CGrade(const char name[], double quiz1 = 0.0, double quiz2 = 0.0, double midterm = 0.0,
            double finalExam = 0.0, double percent = 0.0, char grade = 'F'); // type
        CGrade(CGrade &object); // copy constructor

        // member functions
                void    CalcGrade(void);
                void    CalcPercent(void);
                void    DispGrade(ostream &output = cout) const;

private:
        // data members
        char    m_name[256];
        double  m_quiz1;
        double  m_quiz2;
        double  m_midterm;
        double  m_finalExam;
        double  m_percent;
        char    m_grade;
};



CGrade* MakeCGrade(char name[], double quiz1, double quiz2, double midterm, double finalExam);

void    ShowGrade(CGrade *ptr);

#endif  // CGRADE_HEADER
