// ============================================================================
// File: ordered_array.hpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 3/14/25
//
// Description:
//      This is the header file ordered_array.hpp. Our goal is to create
//      a data structure that keep an array in ascending order when new or 
//      old values are inserted or removed. 
// ============================================================================
#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
 * ordered_array.hpp
 * Definition of the ordered_array class. You can either create a separate
 * ordered_array.cpp and put the method definitions there, or replace the
 * method declarations below with definitions. E.g., replace
 *
 *     int size();
 *
 * with
 *
 *     int size()
 *     {
 *         // Your code here...
 *     }
 *
 * and similarly for all the other functions
 */

class ordered_array {
  public:
    /* constructor
       Construct a new ordered_array with the given capacity (maximum size).
       The size of a new ordered_array should be 0.
    */
//==================================================================================
//  ordered_array (Default Constructor)
//==================================================================================
    ordered_array(int cap)
    {
        v.resize(s);
        c = cap;
    } //end of default constructor

    /* destructor
       Note that you only need a destructor if you're using a dynamic array.
       If you're using a vector, you should delete or comment this out.
    */
//    ~ordered_array();

    /* This assignment does not require you to implement the copy constructor
       or copy assignment operator, even if you are using dynamic memory.
    */

    /* size()
       Returns the size (number of elements in the array).
    */
//==================================================================================
// size
//   
//    Input[in] = void
//
//    Output[out] = returns size data type int(# values inside array)
//==================================================================================
    int size()
    {
        return s;
    } //end of size() function

    /* capacity()
       Returns the maximum size of the array.
    */
//==================================================================================
// capacity
//   
//    Input[in] = void
//
//    Output[out] = returns capacity of array data type int
//                  (max values array can hold)
//==================================================================================
    int capacity()
    {
        return c;
    } //end of capacity function()

    /* insert(e)
       Insert e into the array. Note that it is OK to insert duplicates; if n
       copies of a value are inserted into the array then n copies should appear
       in the array.

       If size() == capacity() then this does nothing.

       If e == -2147483648 then this does nothing (i.e., -2147483648 is not a
       valid value to insert).
    */

//==================================================================================
// size
//   
//    Input[in] = value of type int
//
//    Output[out] = void(inserts element into array)
//==================================================================================
    void insert(int elem)
    {
        if(c == 0) //if array is empty
            return;                                                 
        if(s == c) //if array is full
            return;
        else if(elem == -2147483648)
            return;

        //insert element
        v.push_back(elem);
        s++;
      
        if(s == 1) //exit if array only has 1 element after inserting
            return;
        else
        {
            for(int i = s-1; i > 0; i--) //traverse array(vector pushbacks insert at the end)
            {
                if(v[i] < v[i-1]) //move index element to proper spot
                {
                    int a = v[i-1];
                    v[i-1] = v[i];
                    v[i] = a;
                }
            }
        }
    } //end of insert() function

    /* remove(e)
       Remove e from the array, if it exists. (If it does not exist, the
       array should be unchanged.) If multiple copies of e are present, only
       one should be removed.

       If e = -2147483648 then this does nothing.
    */
//==================================================================================
// remove
//   
//    Input[in] = int
//
//    Output[out] = returns void(removes element within array)
//==================================================================================
    void remove(int elem)
    {
        if(s == 0) //if array is empty
            return;
      
        int index = 0;
        if(!exists(elem)) //check if value does not exist
            return;
        for(int i = 0; i < s; i++) //traverse array to find element index
        {
            if(v[i] == elem)
            {
                index = i;
                break;
            }
        }
        while(index < s-1) //move element to the end
        {
            int a = v[index+1];
            v[index+1] = v[index];
            v[index] = a;
            index++;
        }
        v.pop_back(); //remove element
        s--;
    } //end of remove() function

    /* exists(e)
       Returns true if e is present at least once in the array.

       If e == -2147483648 then this returns false.
    */
//==================================================================================
// exists
//   
//    Input[in] = element value int
//
//    Output[out] = boolean value to check if element exists in array
//==================================================================================
    bool exists(int elem)
    {
        if((s == 0) || (c == 0)) //check if array is empty
        {
                return false;
        }
      
        int i = 0;
        while(i < s) //move through existing values
        {
                if(v[i] == elem) //check if element exists
                {
                        return true;
                }
                        i++;
        }
        return false;
    }// end of exists() function

    /* at(i)
       Returns a *reference* to the element at index i. If i < 0 or i >= size(),
       then the function should throw a std::out_of_range exception (this is the
       same exception that std::vector::at would throw in this situation).

       Note that at() should *never* return -2147483648.
    */
//==================================================================================
// at
//   
//    Input[in] = index value of type int
//
//    Output[out] = returns int value at specificed index
//==================================================================================
    int& at(int i)
    {
        if((s == 0) || (c == 0))
            throw std::out_of_range("array is empty");
        if((i < 0) || (i > size()))
            throw std::out_of_range("index our of range");

        return v[i];
    } //end of at() funcntion

  private:

    // Add private members as needed
        vector<int> v;
        int c = 0;
        int s = 0;




};
