#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double fac(int n);
double caculate_x(float x,int n);
int caculate_1(int n);
int main()
{
    int n;
    float x;
    cin>>x>>n;
    double sinx=0;
    int sign=-1;
    for(int i=1;i<=2*n-1;i+=2)
    {
        sinx+=sign*caculate_1(i)*caculate_x(x,i)/fac(i);
        sign=-sign;
    }
    cout<<fixed<<setprecision(8)<<sinx<<endl;
    return 0;
}
double fac(int n)
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
double caculate_x(float x,int n)
{
    return pow(x,n);
}
int caculate_1(int n)
{
    return(n%2==0)?1:-1;
}