#include<iostream>
using namespace std;
int main()
{
    int a[3][3];
    float student1,student2,student3,English,Math,C;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cin>>a[i][j];
    }
   student1=(a[0][0]+a[0][1]+a[0][2])/3.0;
   student2=(a[1][0]+a[1][1]+a[1][2])/3.0;
   student3=(a[2][0]+a[2][1]+a[2][2])/3.0;
   English=(a[0][0]+a[1][0]+a[2][0])/3.0;
   Math=(a[0][1]+a[1][1]+a[2][1])/3.0;
   C=(a[0][2]+a[1][2]+a[2][2])/3.0;
   cout<<student1<<" "<<student2<<" "<<student3<<endl;
   cout<<English<<" "<<Math<<" "<<C<<endl;
   return 0;
}