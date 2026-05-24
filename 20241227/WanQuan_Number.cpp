#include<iostream>
using namespace std;
int FindNumber(int x);
int main()
{
    int n,m;
    cin>>n>>m;
    bool find=false;
    for(int i=n;i<=m;i++)
    {
        if(FindNumber(i))
        {
            cout<<FindNumber(i)<<" ";
            find=true;
        }
    }
    if(!find)
    {
        cout<<"No Answer"<<endl;
    }
}
int FindNumber(int x)
{
    int sum=0;
    for(int i=1;i<x;i++)
    {
        if(x%i==0)
        {
            sum+=i;
        }
    }
    if(sum==x)
    {
        return x;
    }
    return 0;
}