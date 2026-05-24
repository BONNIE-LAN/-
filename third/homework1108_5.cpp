#include<iostream>
using namespace std;
int main()
{
    int n,hundreds,tens,ones;
    cout<<"Please give me a number"<<endl;
    cin>>n;
    hundreds=n/100;
    tens=(n/10)%10;
    ones=n%10;
    if(hundreds*hundreds*hundreds+tens*tens*tens+ones*ones*ones==n){cout<<"This is the Narcissus number"<<endl;}
    else{cout<<"This is not the Narcissus number"<<endl;}
    return 0;
}