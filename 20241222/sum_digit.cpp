#include<iostream>
using namespace std;
int sum_digit(int n);
int main()
{
    int n;
    cin>>n;
    sum_digit(n);
    cout<<sum_digit(n);
    return 0;
}
int sum_digit(int n)
{
    int sum=0;
    int digit=0;
    for(int i=1;i<=n;i*=10)
    {
        if(n/i!=0)
        {
            digit++;
        }
    }
    for(int i=1;i<=digit;i++)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}