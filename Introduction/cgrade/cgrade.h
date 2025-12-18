// ============================================================================
// File: cgrade.h
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/2/2025
//
// Description:
//      The file defines the `CGrade` class, which stores and manages a
//              student’s grades. It includes functions to input data, calculate
//              percentages and letter grades, and display results, serving as the
//              blueprint for a student grading system.
//
// ============================================================================

#ifndef CGRADE_HEADER
#define CGRADE_HEADER

class   CGrade
{
        public:
        // constructors
        CGrade();       // default constructor
                CGrade(char   name[],
                           double quiz1,
                           double quiz2,
                           double midterm,
                           double finalExam,
                           double percent,
                           char grade);         // type constructor
                CGrade(CGrade &obj);            // copy constructor

                // member functions
                void GetInfo(void);
                void CalcGrade(void);
                void CalcPercent(void);
                void DispGrade(void);

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

#endif  // CGRADE_HEADER
