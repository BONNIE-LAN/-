#include<iostream>
using namespace std;
class Clock
{
    public:
    Clock(int=0,int=0,int s=0);
    void ShowTime();
    protected:
    int Hour;//0-23
    int Minute;//0-59
    int Second;//0-59
};
void Clock::ShowTime()
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}
Clock::Clock(int h,int m,int s)
{
    Hour=h;
    Minute=m;
    Second=s;
}
class NewClock:public Clock
{
    public:
    NewClock(int h,int m,int s):Clock(h,m,s)
    {
        Hour=h;
        Minute=m;
        Second=s;
    }
    void ShowTime()
    {
        if(Hour>=0&&Hour<12)
        {
        cout<<Hour<<":"<<Minute<<":"<<Second<<" AM"<<endl;
        }
        if(Hour==12)
        {
            cout<<Hour<<":"<<Minute<<":"<<Second<<" PM"<<endl;
        }
        if(Hour>12&&Hour<=23)
        {
            cout<<Hour-12<<":"<<Minute<<":"<<Second<<" PM"<<endl;
        }
    }
};
class Date
{
    public:
    Date(int y,int mo,int d)
    {
        year=y;
        month=mo;
        day=d;
    }
    void showDate()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
    protected:
    int year;
    int month;
    int day;
};
class ClockwithDate:public NewClock,public Date
{
    public:
    ClockwithDate(int y,int mo,int d,int h,int m,int s):NewClock(h,m,s),Date(y,mo,d)
    {
        
    }
};
int main()
{
    Clock c1(0,1,2);
    c1.ShowTime();
    NewClock c2(0,1,2);
    c2.ShowTime();
    return 0;
}