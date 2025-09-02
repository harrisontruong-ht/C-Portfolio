#include <iostream>
using namespace std;

int main()
{
        //declaring variables

        //keeps track of the number of items
        int numItems;

        //keeps track of the total cost
        double total = 0;

        //incrementer for while loop
        int counter = 1;

        //Cash or Credit payment
        char payment;

        //prompts user for input
        cout << "How many items?: ";
        cin >> numItems;

        //loops through number of items user prompted
        while(counter != numItems+1)
        {
                //temporary inputCost variable
                double inputCost;

                //prompts user during each recursion
                cout << "Please enter the cost of item #" << counter << ": $";
                cin >> inputCost;

                //adds to total
                total = total + inputCost;

                //increments loop
                counter++;
        }

        //rounds total to 2 decimal places
        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(2);


        //Subtotal
        cout << "\nSubtotal: $" << total << endl;

        //Tax
        cout << "Tax(7.75%): $" << total*0.0775 << endl;

        //Total
        cout << "Total: $" << total*1.0775 << endl << endl;

        //prompts user for cash or credit
        cout << "Cash or credit? Enter 'C' for Cash or 'T' for Credit: ";
        cin >> payment;

        //Cash case
        if((payment == 'C') || (payment == 'c'))
        {
                //amount of cash user inputs
                double cashAmount;
                cout << "\nCash: $";
                cin >> cashAmount;

                //checks cash amount
                while(cashAmount <= total * 1.0775)
                        {
                                cout << "\nPlease enter the correct amount of cash: $";
                                cin >> cashAmount;
                        }

                //prints total change
                cout << "Change: $" << cashAmount-(total*1.0775) << endl;
        }
        //Card Payment case
        else if((payment == 'T') || (payment == 't'))
        {
                cout << "Card Payment: $" << total*1.0775 << endl;
        }
        //neither cash or payment case
        else
        {
                cout << "Incorrect selection...\n";
        }

        return 0;
}
