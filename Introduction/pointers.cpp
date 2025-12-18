// ============================================================================
// File: pointers.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/16/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: Online
// Instructor: Dr. Rodriguez
// Project: Pointer Practice (Arrays & Functions)
//
// Description:
//      This program demonstrates basic pointer usage with arrays. It allocates
//      a fixed-size array of 5 doubles on the stack, assigns a pointer to the
//      first element, and displays three addresses: the array's address, the
//      address the pointer points to (same as the array), and the address of
//      the pointer variable itself.
// ============================================================================
#include <iostream>
using namespace std;

// Function prototypes
void InitArray(double* ptr, int n);
void DispRevArray(const double* ptr, int n);



// ==== InitArray =============================================================
//
// Description:
//      Prompts the user to input n double values and initializes the target
//      array via the pointer provided. Elements are written using pointer
//      arithmetic (i.e., *(ptr + i)) rather than subscript notation.
//
// Input:
//      ptr -- pointer to the first element of array.
//      n   -- number of elements to read and store in array.
//
// Output:
//      None
//
// ============================================================================



void InitArray(double* ptr, int n)
{
    cout << "\nPlease enter " << n << " values for the array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> *(ptr + i);
    }
} //end of InitArray



// ==== DispRevArray ==========================================================
//
// Description:
//      Displays the contents of the array, addressed by ptr, in reverse order.
//
// Input:
//      ptr -- pointer to the first element of a readable double array
//      n   -- number of elements in the array
//
// Output:
//      Prints the array values in reverse, separated by single spaces, then a
//      trailing newline.
//
// ============================================================================
void DispRevArray(const double* ptr, int n)
{
    cout << "\nThe array you entered in reverse is: ";

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(1);

    for (int i = n - 1; i >= 0; --i)
    {
        cout << *(ptr + i);
        if (i > 0)
            cout << ' ';
    }
    cout << '\n';
}//end of DispRevArray



// ==== main ==================================================================
// ============================================================================
int main()
{
    const int SIZE = 5;

    double arr[SIZE];

    double* p = arr;

    cout << "This is the address of the array: "
         << arr << endl;
    cout << "This is the address of where the pointer is pointing to: "
         << p << endl;
    cout << "This is the address of the pointer: "
         << &p << endl;

    InitArray(p, SIZE);
    DispRevArray(p, SIZE);



    return 0;
}//end of main
