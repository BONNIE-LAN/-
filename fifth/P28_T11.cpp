#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int year,month,days,d;
    int days_m1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int days_m2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int days_m[12];
    cout<<"Enter the year,month:"<<endl;
    cin>>year>>month;
    if(year%4==0&&year%100!=0||year%400==0)
    {
        for(int i=0;i<12;i++)
        {
            days_m[i]=days_m2[i];
        }
    }
    else
    {
        for(int i=0;i<12;i++)
        {
            days_m[i]=days_m1[i];
        }
    }
    int day=1;
    days=day;
    for(int i=0;i<month-1;i++)
    {
        days+=days_m[i];
    }
    d=(year-1+(year-1)/4-(year-1)/100+(year-1)/400+days)%7;
    cout<<"\nSUN MON TUE WED THU FRI SAT"<<endl;
    for(int i=0;i<d;i++)//打印空格
    {
        cout<<"   ";
    }
    for(int i=1;i<=days_m[month-1];i++)
    {
        cout<<setw(3)<<i<<" ";
        if((d+i)%7==0){cout<<endl;}
    }
    cout<<endl;
    return 0;
}
