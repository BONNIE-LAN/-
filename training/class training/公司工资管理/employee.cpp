#include<iostream>
#include<string>
using namespace std;
class Employee
{
    protected:
    long int num;
    string name;
    int salary;
    public:
    Employee(int n,string na)
    {
        num=n;
        name=na;
    }
    int caculate_salary()
    {
        return salary;
    }
    void show_infor()
    {
        cout<<"The employee information"<<endl;
        cout<<name<<" "<<num<<" "<<"Salary: "<<salary<<endl;
    }
};
class manager:public Employee
{
    public:
    manager(int n,string na,int sa):Employee(n,na)
    {
        salary=sa;
    }
};
class technician:public Employee
{
    protected:
    int workingHour;
    public:
    technician(int n,string na,int wh):Employee(n,na)
    {
        workingHour=wh;
    }
    int caculate_salary
    {
        salary=100*workingHour;
        return salary;
    }
};
class salesman:public Employee
{
    protected:
    float money;
    public:
    
};