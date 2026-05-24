#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<cmath>
#include"menu.h"
#include"game.h"
using namespace std;
double generateRandomNumber(double min,double max)
{
    int integerPart=generateRandomNumber(static_cast<int>(min),static_cast<int>(max));
    int decimalPart=generateRandomNumber(0,9);
    return integerPart+decimalPart/10.0;
}
void level_1(int &count)
{
    int num1=generateRandomNumber(1,1000);
    int num2=generateRandomNumber(1,1000);
    char op=generateRandomOperator();
    if(op=='/'&&num2==0)
    {
        do{num2=generateRandomNumber(1,1000);}
        while(num2==0);
    }
    cout<<"This is level 1"<<" "<<"count: "<<count<<endl;
    cout<<num1<<" "<<op<<" "<<num2<<"=?"<<endl;
    if(op=='+')
    {
        result=num1+num2;
    }   
    else if(op=='-')
    {
        result=num1-num2;
    }
    else if(op=='*')
    {
        result=num1*num2;
    }
    else if(op=='/')
    {
        result=num1/num2;
    }
}
void level_2(int &count)
{
    double num1=generateRandomNumber(1.0,1000.0),num2=generateRandomNumber(1.0,1000.0);
    char op=generateRandomOperator();
    if(op=='/'&&num2==0)
    {
        do{num2=generateRandomNumber(1,1000);}
        while(num2==0);
    }
    cout<<"This is level 2"<<" "<<"count: "<<count-5<<endl;
    cout<<num1<<" "<<op<<" "<<num2<<"=?"<<endl;
    if(op=='+')
    {
        result=num1+num2;
    }   
    else if(op=='-')
    {
        result=num1-num2;
    }
    else if(op=='*')
    {
        result=num1*num2;
    }
    else if(op=='/')
    {
        result=num1/num2;
    }
}
void checkAnswer(double n,int &count)
{
    const double epsilon=1;
    if(fabs(n-result)<epsilon)
    {
        count++;
        cout<<"Well done! You give the right answer!"<<endl;
    }
    else
    {
        cout<<"Sorry, you give the wrong answer!"<<endl;
        cout<<"The right answer is "<<fixed<<setprecision(2)<<result<<endl;
    }
}
void generateFourOperation_G()
{
    srand(time(0));
    int count=0;
    for (int i = 0; i <= 15; i++)
    {
        if (count == 5)
        {
            system("cls");
            cout << "Congratulations! You have passed the first level!" << endl;
            system("pause");
        }
        else if (count == 10)
        {
            system("cls");
            cout << "Congratulations! You have passed the second level!" << endl;
            system("pause");
        }
        else if (count == 15)
        {
            system("cls");
            cout << "Congratulations! You have passed the game" << endl;
            system("pause");
        }
        if (count < 5)
        {
            level_1(count);
        }
        else if (count >= 5 && count < 10)
        {
            level_2(count);
        }
        else if (count >= 10)
        {
            cout << "This is level 3" << " " << "count: " << count - 10 << endl;
            generateFourOperation();
        }
        double n;
        cin >> n;
        checkAnswer(n, count);
    }
    
}
