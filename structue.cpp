/*
====================================================================
                        BASIC STRUCTURE IN C++
====================================================================
Topics Covered:
1. Structure Declaration
2. Creating Structure Objects
3. Assigning Values
4. Structure Initialization
5. Nested Structure
Author : Harkesh
====================================================================
*/
#include <iostream>
using namespace std;
//====================================================
// Structure Declaration
//====================================================
struct Student
{
    string name;
    int age;
    float grade;
};
struct Address
{
    string city;
    string state;
};
struct Person
{
    string name;
    int age;
    Address address;
};
//====================================================
// Main Function
//====================================================
int main()
{
    cout << "========== BASIC STRUCTURE ==========\n\n";
    //------------------------------------------------
    // Method 1 : Creating Object and Assigning Values
    //------------------------------------------------
    Student student1;
    student1.name = "John Doe";
    student1.age = 20;
    student1.grade = 85.5;
    cout << "Student Information\n";
    cout << "-------------------\n";
    cout << "Name  : " << student1.name << endl;
    cout << "Age   : " << student1.age << endl;
    cout << "Grade : " << student1.grade << endl;
    //------------------------------------------------
    // Method 2 : Direct Initialization
    //------------------------------------------------
    Student student2 = {"Alice",21,89.5};
    cout << "\nStudent Information (Initialized)\n";
    cout << "---------------------------------\n";
    cout << "Name  : " << student2.name << endl;
    cout << "Age   : " << student2.age << endl;
    cout << "Grade : " << student2.grade << endl;
    //------------------------------------------------
    // Nested Structure
    //------------------------------------------------
    Person person1;
    person1.name = "Bob";
    person1.age = 25;
    person1.address.city = "Bhopal";
    person1.address.state = "Madhya Pradesh";
    cout << "\nNested Structure\n";
    cout << "----------------\n";
    cout << "Name  : " << person1.name << endl;
    cout << "Age   : " << person1.age << endl;
    cout << "City  : " << person1.address.city << endl;
    cout << "State : " << person1.address.state << endl;
    return 0;
}