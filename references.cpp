#include <iostream>
using namespace std;
//---------------------------------------------------------
// Pass by Value
//---------------------------------------------------------
void passByValue(int num)
{
    num += 10;
    cout << "Inside Pass by Value: " << num << endl;
}
//---------------------------------------------------------
// Pass by Reference
//---------------------------------------------------------
void passByReference(int &num)
{
    num += 10;
    cout << "Inside Pass by Reference: " << num << endl;
}
//---------------------------------------------------------
// Function Returning Reference
//---------------------------------------------------------
int &returnReference(int &num)
{
    return num;
}
//---------------------------------------------------------
// Main Function
//---------------------------------------------------------
int main()
{
    cout << "========== C++ References ==========\n\n";
    //-----------------------------------------------------
    // 1. Independent Reference (Reference Variable)
    //-----------------------------------------------------
    cout << "1. Independent Reference\n";
    int x = 50;
    int &ref = x;
    cout << "Original value of x : " << x << endl;
    cout << "Reference value     : " << ref << endl;
    ref = 100;
    cout << "After changing reference\n";
    cout << "Value of x          : " << x << endl;
    cout << "Value of ref        : " << ref << endl;
    cout << "\n--------------------------------------\n";
    //-----------------------------------------------------
    // 2. Pass by Value
    //-----------------------------------------------------
    cout << "2. Pass by Value\n";
    int a = 20;
    cout << "Before Function : " << a << endl;
    passByValue(a);
    cout << "After Function  : " << a << endl;
    cout << "\nExplanation:\n";
    cout << "Original variable is NOT modified.\n";
    cout << "\n--------------------------------------\n";
    //-----------------------------------------------------
    // 3. Pass by Reference
    //-----------------------------------------------------
    cout << "3. Pass by Reference\n";
    int b = 20;
    cout << "Before Function : " << b << endl;
    passByReference(b);
    cout << "After Function  : " << b << endl;
    cout << "\nExplanation:\n";
    cout << "Original variable IS modified.\n";
    cout << "\n--------------------------------------\n";
    //-----------------------------------------------------
    // 4. Function Returning Reference
    //-----------------------------------------------------
    cout << "4. Function Returning Reference\n";
    int c = 30;
    cout << "Before : " << c << endl;
    returnReference(c) = 500;
    cout << "After  : " << c << endl;
    cout << "\nExplanation:\n";
    cout << "Function returned a reference, so\n";
    cout << "the original variable was modified.\n";
    cout << "\n--------------------------------------\n";
    //-----------------------------------------------------
    // 5. Memory Address
    //-----------------------------------------------------
    cout << "5. Memory Address of Reference\n";
    int number = 10;
    int &r = number;
    cout << "Address of number : " << &number << endl;
    cout << "Address of r      : " << &r << endl;
    cout << "\nBoth addresses are same because\n";
    cout << "reference is just another name of the variable.\n";
    cout << "\n========== End of Program ==========";
    return 0;
} 
// expect output :- ========== C++ References ==========
1. Independent Reference
Original value of x : 50
Reference value     : 50
After changing reference
Value of x          : 100
Value of ref        : 100
--------------------------------------
2. Pass by Value
Before Function : 20
Inside Pass by Value: 30
After Function  : 20
Explanation:
Original variable is NOT modified.
--------------------------------------
3. Pass by Reference
Before Function : 20
Inside Pass by Reference: 30
After Function  : 30
Explanation:
Original variable IS modified.
--------------------------------------
4. Function Returning Reference
Before : 30
After  : 500
Explanation:
Function returned a reference, so
the original variable was modified.
--------------------------------------
5. Memory Address of Reference
Address of number : 0x...
Address of r      : 0x...
Both addresses are same because
reference is just another name of the variable.

========== End of Program ==========