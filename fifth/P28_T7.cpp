#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Please give me the parameters m and n"<<endl;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"The array is"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
