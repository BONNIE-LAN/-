#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<cmath>
#include"menu.h"
#include"game.h"
using namespace std;
double result=0.0;
int generateRandomNumber(int min,int max)
{
    return min+rand()%(max-min+1);
}
char generateRandomOperator()
{
    char operators[]={'+','-','*','/'};
    return operators[rand()%4];

}
void generateFourOperation()
{
    int num1=generateRandomNumber(1,1000);
    int num2=generateRandomNumber(1,1000);
    int num3=generateRandomNumber(1,1000);
    char op=generateRandomOperator();
    char op2=generateRandomOperator();
    if(op=='/'&&num2==0)
    {
        do{num2=generateRandomNumber(1,1000);}
        while(num2==0);
    }
    if(op2=='/'&&num3==0)
    {
        do{num3=generateRandomNumber(1,1000);}
        while(num3==0);
    }
    cout<<num1<<" "<<op<<" "<<num2<<" "<<op2<<" "<<num3<<"=?"<<endl;
   if(op=='+'||op=='-')
   {
        int MiddleNumber=num2;
        if(op2=='+')
        {
            MiddleNumber+=num3;
        }
        else if(op2=='-')
        {
            MiddleNumber-=num3;
        }
        else if(op2=='*')
        {
            MiddleNumber*=num3;
        }
        else if(op2=='/')
        {
            MiddleNumber/=num3;
        }
        if(op=='+')
        {
            result=MiddleNumber+num1;
        }
        else if(op=='-')
        {
            result=num1-MiddleNumber;
        }
    }
    else if(op=='*'||op=='/')
    {
        int MiddleNumber=num1;
        if(op=='*')
        {
            MiddleNumber*=num2;
        }
        else if(op=='/')
        {
            MiddleNumber/=num2;
        }
         if(op2=='+')
        {
            result=MiddleNumber+num3;
        }
        else if(op2=='-')
        {
            result=MiddleNumber-num3;
        }
        else if(op2=='*')
        {
          result=MiddleNumber*num3;
        }
        else if(op2=='/')
        {
            result=MiddleNumber/num3;
        }

    }
}
void checkAnswer(double n)
{
    const double ecplison=1.00;
    if(fabs(n-result)<ecplison)
    {
        cout<<"Well done! You give the right answer!"<<endl;
    }
    else
    {
        cout<<"Sorry, you give the wrong answer!"<<endl;
        cout<<"The right answer is "<<fixed<<setprecision(2)<<result<<endl;
    }
}
void generateFourOperation_N()
{
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        generateFourOperation();
        double n;
        cin>>n;
        checkAnswer(n);
    }
}
