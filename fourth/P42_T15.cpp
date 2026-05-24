#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void create_Ary(int a[],int n);
int main()
{
    int n=10;
    int a[10];
    create_Ary(a,n);
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";}
    cout<<endl;
    return 0;
}
void create_Ary(int a[],int n)
{
    srand(time(0));
    int i,j,x;
    i=0;
    while(i<n)
    {
        x=rand();
        if(x<10||x>=100)
        continue;
        j=0;
        while(j<=i&&a[j]!=x)
        j++;
        if(j>i)a[i++]=x;
    }
}
