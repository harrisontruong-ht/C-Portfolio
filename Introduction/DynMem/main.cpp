#include <iostream>
#include "DynMem.h"
using namespace std;

int main()
{
        int numElems;
        int *arr;
        cout << "Enter the number of elements: ";
        cin >> numElems;
        arr = AllocArray(numElems);
        InitArray(arr, numElems);
        cout << "\nThe array you entered is: \t ";
        DispArray(arr, numElems);
        SortArray(arr, numElems);
        cout << "\nThe sorted array is: \t ";
        DispArray(arr, numElems);
        cout << "\nReleasing memory..." << endl;
        delete [] arr;

        return 0;
}
