#include<iostream>
using namespace std;
class Ratio
{
    int num;
    int den;
    public:
    Ratio()
    {num=1;den=1;}
    Ratio(int n)
    {num=n;den=1;}
    Ratio(int n,int d)
    {
        num=n;
        den=d;
    }
    void disp()
    {
        if(den==0)
        {
            cout<<"invalid number"<<endl;
        }
        else 
        {cout<<"num/den="<<to_string(num)<<"/"<<to_string(den)<<endl;}
    }
};
int main()
{
    Ratio ra1;
    Ratio ra2(2);
    Ratio ra3(3,0);
    Ratio ra4(3,2);
    ra1.disp();
    ra2.disp();
    ra3.disp();
    ra4.disp();
}