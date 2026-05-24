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
    Ratio(const Ratio& other)
    {
        num=other.num;
        den=other.den;
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
    Ratio ra1(3,2);
    Ratio ra2(ra1);
    ra1.disp();
    ra2.disp();
    return 0;
}