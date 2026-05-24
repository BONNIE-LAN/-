#include<iostream>
#include"Student.h"
using namespace std;
int main()
{
    Student s1(nullptr, 0);
    cout << "Enter the name ane age of the student" << endl;
    s1.input();
    cout << "Student information is: " << endl;
    s1.output();

}