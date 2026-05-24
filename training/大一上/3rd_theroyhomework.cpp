#include<iostream>
using namespace std;
int x1=30,x2=40;
void sub(int x,int y)
{
    x1=x;
    x=y;
    y=x1;
}
main()
{
    int x3=10,x4=20;
    sub(x3,x4);
    sub(x2,x1);
    cout<<x3<<x4<<x1<<x2<<endl;
    return 0;
}