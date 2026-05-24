#include<iostream>
using namespace std;
int main()
{
    int total_money;
    cin>>total_money;
    int Tens=total_money/10;
    total_money=total_money-Tens*10;
    int Fives=total_money/5;
    total_money=total_money-Fives*5;
    int twos=total_money/2;
    total_money=total_money-twos*2;
    int ones=total_money;
    cout<<Tens<<" "<<Fives<<" "<<twos<<" "<<ones;
}