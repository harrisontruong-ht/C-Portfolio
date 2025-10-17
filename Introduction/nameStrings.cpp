//============================================================
// File: namestrings.cpp
//============================================================
// Programmer: Harrison Truong
// Date: 10/17/25
// Class: CSCI 123 ("Introduction to Programming using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: Name Strings
// Description:
//         This program will prompt the user to enter their full name.
//         It will then parse the name into first, middle, and last names
//         (if applicable) and display them separately.
//         Finally, it will count and display the total number of characters
//         in the full name, excluding spaces.
//============================================================

#include <iostream>
#include <cstring>
using namespace std;


//===== main ==================================================================
//
//==========================================================================

int main()
{
    char name[100]; //array declarations
    char firstName[50];
    char middleName[50];
    char lastName[50];
    int firstSpace = 0; // variables
    int secondSpace = 0;
    int characterCount = 0;
    int spaceCounter = 0; //counts spaces

    cout << "Enter your name: "; //prompt user for full name
    cin.getline(name, 100); //read full name with spaces

        cout << endl;

    //loop to find spaces in the name
    for(int index = 0; name[index] != '\0' ; index++)
    {
        if(name[index] == ' ')
        {
            spaceCounter++; //count spaces
            if(firstSpace == 0)
            {
                //store index of first space
                firstSpace = index;
            }
            else
            {
                //store index of second space
                secondSpace = index;
            }
        }
    }

    //calculate character count excluding spaces
    characterCount = strlen(name) - spaceCounter;

    //parse and display names based on number of spaces
    if(firstSpace == 0 && secondSpace == 0)
    {
        //copy full name to firstName if no spaces
        strcpy(firstName, name);
        cout << "First name: " << firstName << endl;
    }
    else if(firstSpace != 0 && secondSpace == 0)
    {
        //parse first and last names
        strncpy(firstName, name, firstSpace);

        // Manual Null termination
        firstName[firstSpace]= '\0';

        //copy last name
        strcpy(lastName, name + firstSpace + 1);

        //display first and last names
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
    }
    else if(firstSpace != 0 && secondSpace != 0)
    {
        //parse first name
        strncpy(firstName, name, firstSpace);

        //null terminate first name
        firstName[firstSpace] = '\0';

        //parse middle name
        int middleStart = firstSpace + 1;

        //calculate middle name length
        int middleLen = secondSpace - middleStart;

        //copy middle name
        strncpy(middleName, name + middleStart, middleLen);

        //null terminate middle name
        middleName[middleLen] = '\0';

        //copy last name
        strcpy(lastName, name + secondSpace + 1);

        //display first, middle, and last names
        cout << "First name: " << firstName << endl;
        cout << "Middle name: " << middleName << endl;
        cout << "Last name: " << lastName << endl;

    }

    //display total character count
    cout << "The total number of characters in your name is: " << characterCount << endl;

    return 0;
}
