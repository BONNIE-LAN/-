#include<iostream>
using namespace std;
class Date
{
    public:
    Date(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    Date &operator-(Date &d1)
    {
        year=year-d1.year;
        month=month-d1.month;
        day=day-d1.day;
        cout<<year<<month<<day;
    }
    private:
    int year;
    int month;
    int day;
};
int main()
{
    Date d1(2020,3,14);
    Date d2(2025,4,16);
    d2.operator-(d1);
    return 0;
}