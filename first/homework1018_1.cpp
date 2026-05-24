#include<iostream>
using namespace std;
int main()
{
    char c1='a',c2='b',c3='c';
    int i1=10,i2=20,i3=30;
    double d1=0.1,d2=0.2,d3=0.4;
    int x;//表达式相应的数据类型说明符
    x=(i3=(i1=1,i2--));//表达式
    cout<<"x="<< x <<endl;
}