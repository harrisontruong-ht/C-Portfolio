// ============================================================================
// File: cgradeOverload.h
// ============================================================================
// Programmer: Luciano Rodriguez
// Date: 11/16/25
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
        CGrade(); // default constructor
        CGrade(char sName[], double quiz1 = 0, double quiz2 = 0, double midterm = 0,
                   double finalExam = 0, double percent = 0, char grade = 'F'); // type
        CGrade(CGrade &object); // copy constructor

        // member functions
        void    GetInfo(istream &input = cin);
        void    CalcGrade(void);
        void    CalcPercent(void);
        void    DispGrade(ostream &output = cout) const;

        // overloaded operators (==)
        bool    operator==(const CGrade &obj) const
        {
                for(int i = 0; i < 256; i++)
                {
                        if(m_name[i] != obj.m_name[i])
                        {
                                return false;
                        }
                        if(obj.m_name[i] == '\0')
                        {
                                break;
                        }
                }

                if(obj.m_quiz1 == m_quiz1
                &&      obj.m_quiz2 == m_quiz2
                &&      obj.m_midterm == m_midterm
                &&      obj.m_finalExam == m_finalExam
                &&      obj.m_percent == m_percent
                &&  obj.m_grade == m_grade)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }

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

// overloaded streams

inline ostream& operator<<(ostream &output, const CGrade &obj)
{
        obj.DispGrade(output);
        return output;
}

inline istream& operator>>(istream &input, CGrade &obj)
{
        obj.GetInfo(input);
        return input;
}

#endif  // CGRADE_HEADER
