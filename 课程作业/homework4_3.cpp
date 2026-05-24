#include <iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int c[m+n];
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {if(a[i]<b[j]){c[k++]=a[i++];}
     else{c[k++]=b[j++];}}
     //如果数组a或b还有元素没有比较，就把剩下的元素全部加入c数组中
     while(i<m){c[k++]=a[i++];}
     while(j<n){c[k++]=b[j++];}
     for(int i=0;i<m+n;i++)
     {cout<<c[i]<<" ";}
     cout<<endl;
     return 0;

}