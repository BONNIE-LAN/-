#include<iostream>
using namespace std;
int fac(int n);
void print(int array[],int digit);
int main()
{
    int n;
    cin>>n;
    int temp = n;  // 保存原始数值
    int digit=1;
    for(int i=1;i<=n;i*=10)
    {
        if(n/i>=10)
        {digit++;}
    }
    int array[digit];
    for(int i=0;i<digit;i++)
    {
       n%10;
       array[i]=n%10;
       n/=10; 
    }
    int sum=0;
    for(int i=0;i<digit;i++)
    {
        sum+=fac(array[i]);
    }
    cout<<temp<<",";
    print(array,digit);
    cout<<sum;
    if(sum==temp)
    {
        cout<<endl<<"Yes"<<endl;
    }
    else
    {
        cout<<endl<<"No"<<endl;
    }
    return 0;
}
int fac(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fac(n-1);
}
void print(int array[],int digit)
{
    for(int i=digit-1;i>=0;i--)
    {
        cout<<array[i]<<"!";
        if(i>0) cout<<"+";
    }
    cout<<"=";
}
