/*
====================================================================
                    ADVANCED STRUCTURE IN C++
====================================================================
Topics Covered:
1. Array of Structures
2. Structure with Member Function
3. User Input
4. Display Function
Author : Harkesh
====================================================================
*/
#include <iostream>
using namespace std;
//====================================================
// Student Structure
//====================================================
struct Student
{
    string name;
    int age;
    float grade;
};
//====================================================
// Person Structure
//====================================================
struct Person
{
    string first_name;
    string last_name;
    int age;
    float salary;
    void display_info()
    {
        cout << "\nPerson Information\n";
        cout << "-------------------------\n";
        cout << "First Name : " << first_name << endl;
        cout << "Last Name  : " << last_name << endl;
        cout << "Age        : " << age << endl;
        cout << "Salary     : " << salary << endl;
    }
};
//====================================================
// Main Function
//====================================================
int main()
{
    cout << "========== ARRAY OF STRUCTURES ==========\n\n";
    Student students[3] =
    {
        {"Alice",21,89.5},
        {"Bob",22,76.0},
        {"Charlie",20,91.5}
    };
    for(int i=0;i<3;i++)
    {
        cout << "Student " << i+1 << endl;
        cout << "Name  : " << students[i].name << endl;
        cout << "Age   : " << students[i].age << endl;
        cout << "Grade : " << students[i].grade << endl;
        cout << endl;
    }
    cout << "========== STRUCTURE WITH MEMBER FUNCTION ==========\n\n";
    Person p1;
    cout << "Enter First Name : ";
    cin >> p1.first_name;
    cout << "Enter Last Name : ";
    cin >> p1.last_name;
    cout << "Enter Age : ";
    cin >> p1.age;
    cout << "Enter Salary : ";
    cin >> p1.salary;
    p1.display_info();
    return 0;
}