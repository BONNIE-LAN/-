#include<iostream>
using namespace std;
int main()
{
    int Month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int Month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int Month[12];
    int year;
    cout<<"Enter the year: ";
    cin>>year;
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        for(int i=0;i<12;i++)
        {
            Month[i]=Month2[i];
        }
    }
    else
    {
        for(int i=0;i<12;i++)
        {
            Month[i]=Month1[i];
        }
    }
    cout<<"Please enter the month and the day:"<<endl;
    int month,day;
    cin>>month>>day;
    int totalDays=day;
    for(int i=0;i<month-1;i++)
    {
        totalDays+=Month[i];
    }
    cout<<"It is the "<<totalDays<<"th day of the year."<<endl;
    return 0;
}
