#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<=6;++i)
    {
        for(int j=6;j>=i;--j){cout<<"M";}
        for(int K=1;K<=i;++K){cout<<" ";}
        cout<<endl;
    }
    return 0;
}   
