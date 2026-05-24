#include<iostream>
using namespace std;
class Rational
{
    private:
    int molucule;//分母
    int denominator;//分子
    public:
    Rational(int m,int d)
    {
        molucule=m;
        denominator=d;
    }
    Rational &operator+(Rational r1)
    {
        int LCM_d;
        for(int i=1;i<=100;i++)
        {
            if(molucule*i==r1.molucule*molucule)
            {
                molucule=molucule*i;
                LCM_d=i;
                break;
            }
        }
        denominator=denominator*LCM_d;
        r1.denominator*=molucule;
        denominator+=r1.denominator;
        return *this;
    }
    void display()
    {
        cout<<denominator<<"/"<<molucule<<endl;
    }

};
int main()
{
    Rational r(3,1),r1(2,1);
    r.operator+(r1);
    r.display();
    return 0;
}