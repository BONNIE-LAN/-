#include<iostream>
using namespace std;
double max(double x,double y);
int main()
{
    double a,b,c;
    cout<<"input two numbers:";
    cin>>a>>b; //输入俩个实数
    c=max(a,b); //求俩个实数最大值
    cout<<"maximum="<<c<<endl;
}
double max(double x,double y)
{
    if(x>y)
    return x;
    else
    return y;
}