#include <iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    if(m>10||n>10)
    {
        cout<<"error"<<endl;
    }
    else
    {
        int a[m][n];
        int b[n][m];
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                b[j][m-1-i]=a[i][j];
            }
        }
        cout<<n<<" "<<m<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
}