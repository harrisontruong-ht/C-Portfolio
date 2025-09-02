#include <iostream>
using namespace std;

void DisplayUppercaseABC(void);

int main(void)
{
        cout << "About to call the DisplayUppercaseABC function..." << endl << endl << endl << endl;
        DisplayUppercaseABC();
        cout << endl << endl << endl << endl << "Returned from the DisplayUppercaseABC function." << endl;
}

void DisplayUppercaseABC(void)
{
        cout << "A     B     C    D    E    F    G    H    I    J    K    L     M" << endl << endl;
        cout << "N     O     P    Q    R    S    T    U    V    W    X    Y     Z" << endl;
}
