#include<bits/stdc++.h> 
#include<string>
#include<vector>

using namespace std;

int main( )
{
   string duck;
   cin>>duck;
    int max=0;
    for(int i=0;i<duck.size();i++)
    {
        if((int)duck[max]<(int)duck[i])
        {
           max=i;
        }
    }
    cout<<duck[max];
    return 0;
}