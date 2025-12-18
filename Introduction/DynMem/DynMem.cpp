#include <iostream>
#include "DynMem.h"
using namespace std;

int* AllocArray(int numElements)
{
        int *ptr;
        ptr = new int[numElements];

        return ptr;
}



void InitArray(int *ptr, int numElements)
{
        cout << "Enter 7 ints for the array: " << endl;
        for(int i = 0; i < numElements; i++)
        {
                cout << "\t[" << i + 1 << "]: ";
                cin >> *(ptr + i);
                //can also use ptr[i];
        }
}



void DispArray(int *ptr, int numElements)
{
        for(int i = 0; i < numElements; i++)
        {
                cout << ptr[i] << " ";
                //look at *(ptr + i) above
        }
        cout << endl;
}



void SortArray(int *ptr, int numElements)
{
        //insertion sort
        for(int i = 0; i < numElements; i++)
        {
                //nested for loops to check if value is less
                //than previous ones.
                for(int a = i; a >= 0; a--)
                {
                        if((a - 1) < 0)
                        {
                                //check if out of bounds
                                break;
                        }
                        if(ptr[a] < ptr[a-1])
                        {
                                //swap values
                                int temp;
                                temp = ptr[a-1];
                                ptr[a-1] = ptr[a];
                                ptr[a] = temp;
                        }
                }
        }
}
