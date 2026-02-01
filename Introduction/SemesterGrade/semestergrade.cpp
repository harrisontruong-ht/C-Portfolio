// =============================================================
// file: semestergrade.cpp
// =============================================================
// Programmer: Harrison Truong
// Date: 11/05/25
// Project: Semester Grade
// Description:
//      This program reads student information from a file and
//      identifies students who are failing all their classes.
//
// =============================================================

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//struct declarations
struct Name
{
    char first[256];
    char last[256];
};

struct Grades
{
    char math;
    char science;
    char english;
};

struct StudentInfo
{
    int ID;
    Name name;
    Grades grade;
};

//function prototypes
void ReadFile(ifstream &inFile, StudentInfo students[], int elements);
void isFailing(StudentInfo students[], int elements);



//===== main ==================================================================
//
//=============================================================================
int main()
{
    StudentInfo students[30]; //array of StudentInfo structures
    ifstream inputFile;
    inputFile.open("StudentInfo.txt"); //open input file
    ReadFile(inputFile, students, 30); //call ReadFile function
    isFailing(students, 30); //call isFailing function
    inputFile.close(); //close input file
    return 0;

} //end of "main"



//=== ReadFile ================================================================
//
// This function will read student information from an input file
// and store it in an array of StudentInfo structures.
// Input:
//         inFile [IN] == an input file stream to read the student information
//         students [IN] == an array of StudentInfo structures to store
//                           the student information
//         elements [IN] == the number of elements in the students array
// Output:
//         [OUT] == the students array will be populated with the
//                   student information read from the file.
//=============================================================================
void ReadFile(ifstream &inFile, StudentInfo students[], int elements)
{

    inFile.ignore(41);
    for(int i = 0; i < elements; i++)
    {
        //read student information from file
        inFile >> students[i].name.first;
        inFile >> students[i].name.last;
        inFile >> students[i].ID;
        inFile >> students[i].grade.math;
        inFile >> students[i].grade.science;
        inFile >> students[i].grade.english;
        }
} //end of "ReadFile"



//=== isFailing ================================================================
// This function will identify and display the names of students
// who are failing all their classes.
// Input:
//         students [IN] == an array of StudentInfo structures containing
//                           the student information
//         elements [IN] == the number of elements in the students array
// Output:
//         The names of students failing all their classes will be
//         displayed to the console.
//=============================================================================
void isFailing(StudentInfo students[], int elements)
{
    cout << "The following student(s) are failing: " << endl; //header
    int numFail = 0; //counter for failing students
    for(int i = 0; i < elements; i++)
    {
        //check if student is failing all classes
        if((students[i].grade.math == 'F') &&
           (students[i].grade.science == 'F') &&
           (students[i].grade.english == 'F'))
            {
                ++numFail;
                cout << students[i].name.first << " "
                     << students[i].name.last << endl;
            }
    }

    //if no students are failing, display message
    if(numFail == 0)
    {
        cout << "No students are failing!" << endl;
    }

} //end of "isFailing"
