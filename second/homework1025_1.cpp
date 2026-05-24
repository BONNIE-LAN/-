#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int workingtime;
    double hourly_wage,total_wage,wage_payable;
    cout<<"please offer workingtime and hourly_wage"<<endl;
    cin>>workingtime>>hourly_wage;
    total_wage=workingtime*hourly_wage;
    wage_payable=total_wage*0.9;
    cout<<"wage payable="<<setiosflags(ios::fixed)<<setprecision(2)<<wage_payable<<endl;
    return 0;
}