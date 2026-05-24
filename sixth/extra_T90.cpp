#include<iostream>
#include<iomanip>
using namespace std;
int fac(int n);
int main()
{
    for(int i=5;i<=9;i++)
    {
        cout<<setw(6)<<fac(i)<<" ";
    }
}
int fac(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fac(n-1);
    }
}