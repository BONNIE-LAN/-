#include<iostream>
using namespace std;
enum AMPM{AM=1,PM};
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
    cout<<Hour<<":"<<Minute<<":"<<Second;
}
Clock::Clock(int h,int m,int s)
{
    Hour=h;
    Minute=m;
    Second=s;
}
enum AMPM{AM=1,PM};
class NewClock:public Clock
{
    public:
    NewClock();
    NewClock(Clock c,AMPM ap);
    void ShowTime();
    private:
    AMPM AP;
};
NewClock::NewClock(Clock c,AMPM ap):Clock(c)
{
    AP=ap;
}
void NewClock::ShowTime()
{
    Clock::ShowTime();
    cout<<(AP==AM?"AM":"PM")<<endl;
}
class Date
{
    protected:
    int Year;//1900-2022
    int Month;//0-12
    int Day;//1-31
    static const int days[];
    bool LeapYear();
    bool EndofMonth();
    public:
    Date(int=1900,int=1,int=1);
    void Increment(int);
    void Decrement(int);
    void SetDate(int,int,int);
    void ShowDate();
};
const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
Date::Date()
