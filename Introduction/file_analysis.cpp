//=============================================================================
// File: fileAnalysis.cpp
//=============================================================================
// Programmer: Harrison Truong
// Date: 10/13/25
// Class: CSCI 123 ("Introduction to Programming using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: File Analysis
// Description:
//         This program will read a text file and analyze its contents.
//         It will count the number of uppercase letters, lowercase letters,
//         digits, punctuation characters, whitespace characters, lines,
//         periods, and question marks.
//         Finally, it will display the results to the console.
//
//=============================================================================

#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

//function prototype
int ReadFile(ifstream &inFile, int &totalUpper, int &totalLower,
int &totalDigits, int &totalPunct, int &totalSpace,
int &totalLines, int &totalPeriods, int &totalQuestion);



//===== main ==================================================================
//
//=============================================================================

int main()
{
        int totalChar = 0; //variables
        int totalUpper = 0;
        int totalLower = 0;
        int totalDigits = 0;
        int totalPunct = 0;
        int totalSpace = 0;
        int totalLines = 0;
        int totalPeriods = 0;
        int totalQuestion = 0;

        ifstream inputFile("dracula.txt"); //open the input file

        //call the ReadFile function
        //and store the returned total characters
        totalChar += ReadFile(inputFile, totalUpper, totalLower, totalDigits,
        totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion);

        //display the results
        cout << "File \"dracula.txt\" contains the following:" << endl;
        cout << "Uppercase letters: " << setw(19) << totalUpper << endl;
        cout << "Lowercase letters: " << setw(19) << totalLower << endl;
        cout << "Digits: " << setw(30) << totalDigits << endl;
        cout << "Punctuation characters: " << setw(14) << totalPunct << endl;
        cout << "Whitespace characters: " << setw(15) << totalSpace << endl;
        cout << "Lines: " << setw(31) << totalLines << endl;
        cout << "Total Periods: " << setw(23)<< totalPeriods << endl;
        cout << "Total Question Marks: " << setw(16) << totalQuestion << endl;
        cout << "Total Characters Read: " << setw(15) << totalChar << endl;

        return 0;
} //end of "main"



//=== ReadFile ================================================================
//
// This function will read a text file and analyze its contents.
// It will count the number of uppercase letters, lowercase letters,
// digits, punctuation characters, whitespace characters, lines,
// periods, and question marks.
// Input:
//         inFile [IN] == an input file stream to read the text file
//         totalUpper, totalLower, totalDigits, totalPunct,
//         totalSpace, totalLines, totalPeriods, totalQuestion
//
// Output:
//         [OUT] == integer reference variables to store the counts of
//                   uppercase letters, lowercase letters, digits,
//                   punctuation characters, whitespace characters,
//                   lines, periods, and question marks
//         The total number of characters read from the file will be
//         returned as an integer.
//
//=============================================================================

int ReadFile(ifstream &inFile, int &totalUpper, int &totalLower,
int &totalDigits, int &totalPunct, int &totalSpace,
int &totalLines, int &totalPeriods, int &totalQuestion)
{
    char readChar; //variables
    int totalChar = 0;

    while(inFile.get(readChar))
    {
        totalChar++; //count total characters

        if(readChar == '\n')
        {
                totalLines++; //count total lines
        }
        else if(isupper(readChar))
        {
                totalUpper++; //count total uppercase letters
        }
        else if(islower(readChar))
        {
                totalLower++; //count total lowercase letters
        }
        else if(isdigit(readChar))
        {
                totalDigits++; //count total digits
        }
        else if(isspace(readChar))
        {
                totalSpace++; //count total whitespace characters
        }
        else if(readChar == '.')
        {
                totalPeriods++; //count total periods
        }
        else if(readChar == '?')
        {
                totalQuestion++; //count total question marks
        }

        if(ispunct(readChar))
        {
                totalPunct++; //count total punctuation characters
        }
    }

    return (totalChar); //return total characters read
} //end of "ReadFile"
