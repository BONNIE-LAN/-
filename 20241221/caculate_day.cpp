#include <iostream>
using namespace std;
struct Date
{
    int year;
    int month;
    int day;
};
int main()
{
   Date date;
   cin>>date.year>>date.month>>date.day;
   if(date.year%4==0&&date.year%100!=0||date.year%400==0)
   {
       int month1[12]={31,29,31,30,31,30,31,31,30,31,30,31};
       int sum=0;
       for(int i=0;i<date.month-1;i++)
       {
           sum+=month1[i];
       }
       int days=sum+date.day;
       cout<<days<<endl;
   }
   else
   {
      int month2[12]={31,28,31,30,31,30,31,31,30,31,30,31};
       int sum=0;
       for(int i=0;i<date.month-1;i++)
       {
           sum+=month2[i];
       }
       int days=sum+date.day;
       cout<<days<<endl;
   }
   
       
}