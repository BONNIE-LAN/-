#include<iostream>
using namespace std;
int main()
{
    int n,cube,square;
    cout<<"Please give me a number"<<endl;
    cin>>n;
    cube=n*n*n;
    square=n*n;
    if(n%7==0){cout<<"cube="<<cube<<endl;}
    else{cout<<"square="<<square<<endl;}
    return 0;
}