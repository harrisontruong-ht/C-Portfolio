// ============================================================================
// File: cpizza.cpp
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/30/25
//
// Description:
//      This is the implementation file for the CPizza class. It uses the
//              cpizza.h file.
// ============================================================================

#include <cstring>
#include <iostream>
#include "cpizza.h"
using namespace std;


//=============================================================================
//Default Constructor
//=============================================================================
CPizza::CPizza()
{
        cout << "Default" << endl;
        m_name = NULL;
        m_LPizza = new int; //can be initialized this way
        *m_LPizza = 0;
        m_MPizza = new int(0); //can be both allocate and initialize
        m_SPizza = new int(0);
        m_cost = new double(0.0);
        m_delivery = new bool(false);
        m_deliveryFee = new double(DFEE);
} // end of default constructor



//==============================================================================
//Type Constructor
//==============================================================================
CPizza::CPizza(const char *ptrName, int LPizza, int MPizza, int SPizza,
           double cost,  bool delivery, double deliverFee)
{
        m_name = new char[strlen(ptrName)+1];
        if(m_name != NULL)
        {
                strcpy(m_name, ptrName);
        }
        else
        {
                m_name = NULL;
        }

        m_LPizza = new int(LPizza);
        m_MPizza = new int(MPizza);
        m_SPizza = new int(SPizza);
        m_cost = new double(cost);
        m_delivery = new bool(delivery);
        m_deliveryFee = new double(deliverFee);

}//end of Type Constructor



//================================================================================
//Copy Constructor
//================================================================================
CPizza::CPizza(CPizza &cpy)
{
        m_LPizza = new int(cpy.GetLPizza());
        m_MPizza = new int(cpy.GetMPizza());
        m_SPizza = new int(cpy.GetSPizza());
        m_cost = new double(cpy.GetTotal());
        m_delivery = new bool(cpy.GetDelivery());
        m_deliveryFee = new double(cpy.GetDeliveryFee());
        m_name = new char[strlen(cpy.GetName())+1];
        if(m_name != NULL) //checks if space was found for the name
        {
                SetName(cpy.GetName());
        }

} // end of copy constructor



//=================================================================================
//Destructor
//=================================================================================
CPizza::~CPizza()
{
        cout << "\nDestructor!" << endl;
        delete m_LPizza;
        delete m_MPizza;
        delete m_SPizza;
        delete m_cost;
        delete m_delivery;
        delete m_deliveryFee;
        delete []m_name;
} // end of Destructor



//==================================================================================
//SetName
//
//      Input[IN]: name pointer of const type so original value is not modified
//
//      Output[OUT]: changes the value of the member variable for name
//==================================================================================
void CPizza::SetName(const char *name)
{
        delete []m_name;//free old memory
        m_name  = new char[strlen(name)+1];     //allocate new memory for new size
        if(NULL != m_name) //if room is able to be found
        {
                strcpy(m_name, name);
        }

} // end of SetName



//==================================================================================
//CalcCost
//
//      Input[IN]: void
//
//      Output[OUT]: Calculates the total cost including tax and delivery fee(adjusts
//                               m_cost member variable)
//==================================================================================
void CPizza::CalcCost()
{
        double subtotal = ((LPIZZA*GetLPizza()) +(MPIZZA*GetMPizza()) +
                                          (SPIZZA*GetSPizza()));
        double tax = subtotal*TAX;
        *m_cost = tax + subtotal;
        if(GetDelivery())
        {
                *m_cost += GetDeliveryFee();
        }
} // end of CalcCost



//==================================================================================
//DispOrder
//
//      Input[IN]: void
//
//      Output[OUT]: displays the order to the terminal(# large, # medium, #small,
//                               Delivery, Total Cost)
//==================================================================================
void CPizza::DispOrder()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

        cout << GetName() << endl;
        cout << "\t" << GetLPizza() << " Large Pizza(s)" << endl;
        cout << "\t" << GetMPizza() << " Medium Pizza(s)" << endl;
        cout << "\t" << GetSPizza() << " Small Pizza(s)" << endl;
        cout << "\tDelivery: ";
        if(*m_delivery == true)
        {
                cout << "Yes";
        }
        else
        {
                cout << "No";
        }

        CalcCost();

        cout << "\n\nTotal Cost: $" << GetTotal() << endl << endl;
} //end of DispOrder
