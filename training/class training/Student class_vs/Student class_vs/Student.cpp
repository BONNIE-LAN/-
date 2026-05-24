#include<iostream>
#include<cstring>
using namespace std;
class Student
{
private:
    char* name;
    int age;
public:
    Student(char* na, int ag);
    ~Student();
    Student(const Student& otner);
    void input();
    void output();
};
Student::Student(char* na, int ag)
{
    name = new char[strlen(na) + 1];
    if (name != 0) strcpy(name, na);
    age = ag;
}
Student::~Student()
{
    name = '\0';
    delete[]name;
}
Student::Student(const Student& other)
{
    name = new char[strlen(other.name + 1)];
    if (name != 0) strcpy(name, other.name);
    age = other.age;
}
void Student::input()
{
    char tempName[100];
    cout << "Enter name:" << endl;
    cin >> tempName[100];
    strcpy(name, tempName);
    cout << "Enter age:" << endl;
    cin >> age;
    if (age < 18 && age>24)
    {
        cout << "Wrong age" << endl;
    }
}
void Student::output()
{
    cout << "Name:" << name << "Age:" << age << endl;
}