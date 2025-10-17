//=============================================================================
// File: matrices.cpp
//=============================================================================
// Programmer  : Harrison Truong
// Date        : 10/17/25
// Class       : CSCI 123 ("Introduction to Programming using C++")
// Time        : Online
// Instructor  : Dr. Rodriguez
// Project     : Matrices
// Description :
//         This program will prompt the user to enter two 3x3 matrices.
//         It will then display the matrices, their sum, their transposes,
//         and their determinants.
//=============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void InitMatrix(int inputArray[][3], int numRows);
void DispMatrix(int inputArray[][3], int numRows);
void AddMatrix(int firstArray[][3], int secondArray[][3], int numRows);
void TMatrix(int inputArray[][3], int numRows);
int DetMatrix(int inputArray[][3], int numRows);


//===== main ==================================================================
//
//=============================================================================
int main()
{
        int array1[3][3]; //array declarations
    int array2[3][3];

    //prompt user to enter matrices
    cout << "Please enter 9 integer values for the first matrix:" << endl;
    InitMatrix(array1, 3);

    //prompt user to enter second matrix
    cout << "Please enter 9 integer values for the second matrix:" << endl;
    InitMatrix(array2, 3);

    //display the matrices
    cout << "The matricies you've entered are: " << endl;
    DispMatrix(array1, 3);
    DispMatrix(array2, 3);

    //call AddMatrix function
    AddMatrix(array1, array2, 3);


    //call TMatrix function
    cout << "The transpose of the matricies are: " << endl;
    TMatrix(array1, 3);
    TMatrix(array2, 3);

    //call DetMatrix function
    cout << "The determinant of the matrices are: " <<
    DetMatrix(array1, 3) << " and " << DetMatrix(array2, 3) << endl;

    return 0;

} //end of "main"



//=== InitMatrix ==============================================================
//
// This function will initialize a 3x3 matrix by prompting the user
// to enter integer values for each element.
// Input:
//         inputArray [IN] == a 2D array to store the matrix values
//         numRows [IN] == the number of rows in the matrix (should be 3)
// Output:
//         The matrix will be initialized with user-provided values.
//=============================================================================

void InitMatrix(int inputArray[][3], int numRows)
{
        for (int row = 0; row < numRows; ++row)//nested loop to traverse matrix
    {
        for (int col = 0; col < 3; ++col)
        {
                //prompt user for input
            cout << "[" << row << "]" << "[" << col << "]: ";
            cin >> inputArray[row][col];
        }
    }
    cout << endl;
} //end of "InitMatrix"



//=== DispMatrix ==============================================================
//
// This function will display a 3x3 matrix.
// Input:
//         inputArray [IN] == a 2D array containing the matrix values
//         numRows [IN] == the number of rows in the matrix (should be
//                        3)
// Output:
//         The matrix will be displayed to the console.
//=============================================================================

void DispMatrix(int inputArray[][3], int numRows)
{
        for(int row = 0; row < numRows; ++row)//nested loop to traverse matrix
    {
        for(int col = 0; col < 3; ++col)
        {
                //display matrix element with formatting
            cout << setw(5) << inputArray[row][col];
        }
        cout << endl;
    }
    cout << endl;
} //end of "DispMatrix"



//=== AddMatrix ==============================================================
//
// This function will add two 3x3 matrices and display the result.
// Input:
//         firstArray, secondArray [IN] == two 2D arrays containing the
//                                        matrix values
//         numRows [IN] == the number of rows in the matrices (should be 3)
// Output:
//         The sum of the two matrices will be displayed to the console.
//============================================================================

void AddMatrix(int firstArray[][3], int secondArray[][3], int numRows)
{
        //display message
    cout << "The sum of the matricies are: " << endl;

        int arraySum[3][3];//array to store sum

    //nested loop to traverse matrices and calculate sum
    for(int row = 0; row < numRows; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
                //calculate sum of corresponding elements
            arraySum[row][col] = (firstArray[row][col] +
            secondArray[row][col]);
        }
    }

        //call DispMatrix to display the sum
        DispMatrix(arraySum, 3);

} //end of "AddMatrix"



//=== TMatrix ================================================================
//
// This function will calculate and display the transpose of a 3x3 matrix.
// Input:
//         inputArray [IN] == a 2D array containing the matrix values
//         numRows [IN] == the number of rows in the matrix (should be 3)
// Output:
//         The transpose of the matrix will be displayed to the console.
//=============================================================================

void TMatrix(int inputArray[][3], int numRows)
{
        int tarray[3][3]; //array to store transpose

    //nested loop to calculate transpose
    for(int row = 0; row < numRows; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
                //swap rows and columns
            tarray[row][col] = inputArray[col][row];
        }
    }

    //call DispMatrix to display the transpose
    DispMatrix(tarray, 3);

} //end of "TMatrix"



//=== DetMatrix ================================================================
//
// This function will calculate the determinant of a 3x3 matrix.
// Input:
//         inputArray [IN] == a 2D array containing the matrix values
//         numRows [IN] == the number of rows in the matrix (should be 3)
// Output:
//         The determinant of the matrix will be returned as an integer.
//=============================================================================

int DetMatrix(int inputArray[][3], int numRows)
{
        int v[3][3]; //makes calculations easier

    //nested loop to copy inputArray to v
    for(int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
                //copy element
            v[row][col] = inputArray[row][col];
        }
    }

    //calculate determinant using formula
    int a = v[0][0];
    int b = v[0][1];
    int c = v[0][2];
    int d = v[1][0];
    int e = v[1][1];
    int f = v[1][2];
    int g = v[2][0];
    int h = v[2][1];
    int i = v[2][2];

    //return determinant value
    return (a*((e*i) - (f*h))) - (b*((d*i)-(f*g))) + (c*((d*h) - (e*g)));

} //end of "DetMatrix"
