#pragma once
class Student
{
    private:
    char *name[20];
    int age;
    public:
    Student(char *na[20],int ag);
    ~Student();
    Student(const Student& otner);
    void input();
    void output();
};
