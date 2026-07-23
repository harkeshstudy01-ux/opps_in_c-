/*
====================================================================
                     Access Specifiers in C++
====================================================================

Definition:
Access specifiers are keywords in C++ that control the visibility
and accessibility of data members and member functions of a class.
They help implement encapsulation by restricting direct access to
the class members.

There are three access specifiers in C++:

1. Public
--------------------------------------------------------------------
- Members declared as public can be accessed from anywhere in the
  program.
- They are accessible:
    • Inside the class
    • Outside the class through an object
    • Inside derived (child) classes
- Public members form the interface of the class through which users
  interact with the object.

2. Private
--------------------------------------------------------------------
- Members declared as private can only be accessed within the class
  in which they are declared.
- They cannot be accessed:
    • Outside the class
    • Directly by derived (child) classes
- Private members are used to hide implementation details and
  protect the internal state of an object.
- They are a key feature for achieving encapsulation and data hiding.

3. Protected
--------------------------------------------------------------------
- Members declared as protected can be accessed:
    • Inside the class
    • Inside derived (child) classes
- They cannot be accessed directly from outside the class.
- Protected members are mainly used in inheritance, allowing derived
  classes to access selected members of the base class while keeping
  them hidden from external code.

Summary:
--------------------------------------------------------------------
Specifier      Same Class   Derived Class   Outside Class
---------------------------------------------------------
Private            Yes            No              No
Protected          Yes           Yes              No
Public             Yes           Yes             Yes

====================================================================
*/
// the example at single and multiple level as expected output :-
//SINGLE LEVEL _
#include <iostream>
using namespace std;
//------------------------------------------------------------
// Base Class
//------------------------------------------------------------
class Base
{
private:
    int privateVar = 10;
protected:
    int protectedVar = 20;
public:
    int publicVar = 30;
    // Member function of Base class
    void showBaseMembers()
    {
        cout << "Inside Base Class\n";
        cout << "Private Variable   : " << privateVar << endl;
        cout << "Protected Variable : " << protectedVar << endl;
        cout << "Public Variable    : " << publicVar << endl;
    }
};
//------------------------------------------------------------
// Derived Class
//------------------------------------------------------------
class Derived : public Base
{
public:
    void showDerivedMembers()
    {
        cout << "\nInside Derived Class\n";
        // cout << privateVar;    // ERROR
        // Private members cannot be accessed directly.
        cout << "Protected Variable : " << protectedVar << endl;
        cout << "Public Variable    : " << publicVar << endl;
    }
};
//------------------------------------------------------------
// Main Function
//------------------------------------------------------------
int main()
{
    cout << "=========== ACCESS SPECIFIERS IN C++ ===========\n\n";
    //--------------------------------------------------------
    // Base Class Object
    //--------------------------------------------------------
    Base baseObj;
    cout << "Accessing through Base Object\n";
    baseObj.showBaseMembers();
    cout << "\nOutside the Class\n";
    // cout << baseObj.privateVar;     // ERROR
    // cout << baseObj.protectedVar;   // ERROR
    cout << "Public Variable : " << baseObj.publicVar << endl;
    //--------------------------------------------------------
    // Derived Class Object
    //--------------------------------------------------------
    Derived derivedObj;
    derivedObj.showDerivedMembers();
    cout << "\nAccessing Public Member through Derived Object\n";
    cout << "Public Variable : " << derivedObj.publicVar << endl;
    // cout << derivedObj.protectedVar; // ERROR
    // cout << derivedObj.privateVar;   // ERROR
    cout << "\n===============================================\n";
    return 0;
}
//EXPECTED OUTPUT:-
=========== ACCESS SPECIFIERS IN C++ ===========
Accessing through Base Object
Inside Base Class
Private Variable   : 10
Protected Variable : 20
Public Variable    : 30
Outside the Class
Public Variable : 30
Inside Derived Class
Protected Variable : 20
Public Variable    : 30
Accessing Public Member through Derived Object
Public Variable : 30
===============================================

//MULTIPLE LEVEL--

#include <iostream>
using namespace std;
//====================================================
// Base Class
//====================================================
class Base
{
private:
    int privateVar = 10;
protected:
    int protectedVar = 20;
public:
    int publicVar = 30;
    void show()
    {
        cout << "\nInside Base Class\n";
        cout << "Private Variable   : " << privateVar << endl;
        cout << "Protected Variable : " << protectedVar << endl;
        cout << "Public Variable    : " << publicVar << endl;
    }
};
//====================================================
// Derived1 Class
//====================================================
class Derived1 : public Base
{
public:
    void accessBaseMembers()
    {
        cout << "\nInside Derived1 Class\n";
        // ERROR
        // cout << privateVar;
        cout << "Protected Variable : " << protectedVar << endl;
        cout << "Public Variable    : " << publicVar << endl;
    }
};
//====================================================
// Derived2 Class
//====================================================
class Derived2 : public Derived1
{
public:
    void accessDerived1Members()
    {
        cout << "\nInside Derived2 Class\n";
        // ERROr
        // cout << privateVar;
        cout << "Protected Variable : " << protectedVar << endl;
        cout << "Public Variable    : " << publicVar << endl;
    }
};
//====================================================
// Main Function
//====================================================
int main()
{
    cout << "==============================================\n";
    cout << " ACCESS SPECIFIERS & MULTILEVEL INHERITANCE\n";
    cout << "==============================================\n";
    //------------------------------------------------
    // Base Class Object
    //------------------------------------------------
    Base baseObj;
    cout << "\n1. Accessing Base Class Members";
    baseObj.show();
    cout << "\nAccessing Members Outside the Class\n";
    // ERROR
    // cout << baseObj.privateVar;
    // cout << baseObj.protectedVar;
    cout << "Public Variable : " << baseObj.publicVar << endl;
    //------------------------------------------------
    // Derived1 Object
    //------------------------------------------------
    Derived1 obj1;
    cout << "\n2. Accessing Members from Derived1";
    obj1.accessBaseMembers();
    // show() is inherited because it is public
    obj1.show();
    cout << "\nPublic Variable : " << obj1.publicVar << endl;
    //------------------------------------------------
    // Derived2 Object
    //------------------------------------------------
    Derived2 obj2;
    cout << "\n3. Accessing Members from Derived2";
    obj2.accessBaseMembers();
    obj2.accessDerived1Members();
    // show() is inherited from Base
    obj2.show();
    cout << "\nPublic Variable : " << obj2.publicVar << endl;
    //------------------------------------------------
    // Invalid Access Examples
    //------------------------------------------------
    /*
    cout << obj2.privateVar;      // ERROR
    cout << obj2.protectedVar;    // ERROR
    */
    cout << "\n==============================================\n";
    cout << "Program Completed Successfully.\n";
    cout << "==============================================\n";
    return 0;
}

// excpected output :-
==============================================
 ACCESS SPECIFIERS & MULTILEVEL INHERITANCE
==============================================
1. Accessing Base Class Members
Inside Base Class
Private Variable   : 10
Protected Variable : 20
Public Variable    : 30
Accessing Members Outside the Class
Public Variable : 30
2. Accessing Members from Derived1
Inside Derived1 Class
Protected Variable : 20
Public Variable    : 30
Inside Base Class
Private Variable   : 10
Protected Variable : 20
Public Variable    : 30
Public Variable : 30
3. Accessing Members from Derived2
Inside Derived1 Class
Protected Variable : 20
Public Variable    : 30
Inside Derived2 Class
Protected Variable : 20
Public Variable    : 30
Inside Base Class
Private Variable   : 10
Protected Variable : 20
Public Variable    : 30
Public Variable : 30


