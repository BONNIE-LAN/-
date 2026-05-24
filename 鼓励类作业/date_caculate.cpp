#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int n;
    cin>>str>>n;
    int year,month,day;
    year=n/365;
    int count=0;
    int current_year=stoi(str.substr(0,4));
    int current_month=stoi(str.substr(4,2));
    int current_day=stoi(str.substr(6,2));
    for(int i=1;i<=year;i++)
    {
        if(((current_year+i)%4==0&&(current_year+i)%100!=0)||(current_year+i)%400==0)
        {
            count++;
        }
    }
    int total_month=stoi(str)-count*366-(n-count)*365;
    month=total_month/30;
    int count_31=0;
    int count_30=0;
    int count_29=0,count_28=0;
    for(int i=current_month;i<=current_month+month;i++)
    {
        if(current_month+i==1||current_month+i==3||current_month+i==5||current_month+i==7||current_month+i==8||current_month+i==10||current_month+i==12)
        {
            count_31++;
        }
        if(current_month+i==4||current_month+i==6||current_month+i==9||current_month+i==11)
        {
            count_30++;
        }
        if(current_month+i==2&&((current_year+year)%4==0&&(current_year+year)%100!=0)||(current_year+year)%400==0)
        {
            count_29++;
        }
        else{count_28++;}
    }
    day=total_month-count_31*31-count_30*30-count_29*29-count_28*28;
    current_year+=year;
    current_month+=month;
    current_day+=day;
    string result;
    result=(current_year<1000?"0":"")+to_string(current_year)+(current_month<10?"0":"")+to_string(current_month)+(current_day<10?"0":"")+to_string(current_day);
    if(current_year>=10000)
    {
        cout<<"out of limitation"<<endl;
    }
    else{cout<<result<<endl;}
    return 0;
}