#include<iostream>
using namespace std;
class Ratio
{
    int num;
    int den;
    public:
    Ratio(int n=1,int d=1)
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
    Ratio ra3(2,3);
    ra1.disp();
    ra2.disp();
    ra3.disp();
    return 0;
}