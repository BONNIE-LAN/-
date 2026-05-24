#include<iostream>
using namespace std;
class CMatrix
{
    public:
    CMatrix(int x=3,int y=3);
    ~CMatrix();
    friend istream&operator>>(istream &input,CMatrix &m);
    friend CMatrix &operator+(const CMatrix &m1,const CMatrix &m2);
    protected:
    int mx,my;
    int **pm;
};
CMatrix::CMatrix(int x,int y)
{
    mx=x;
    my=y;
    pm=new int*[mx];
    for(int i1=0;i1<mx;i1++)
    {
        pm[i1]=new int[my];
        for(int i2=0;i2<my;i2++)
        {
            cin>>pm[i1][i2];
        }
    }
}
CMatrix::~CMatrix()
{
    for(int i1=0;i1<mx;i1++)
    {
        delete []pm[i1];
        delete []pm;
    }
}
istream &operator>>(istream &input,CMatrix &m)
{
    int i1,i2;
    for(int i1=0;i1<m.mx;i1++)
    {
        for(int i2=0;i2<m.my;i2++)
        {
            input>>m.pm[i1][i2];
            return input;
        }
    }
}
CMatrix::CMatrix(const CMatrix &a)
{
    mx=a.mx;
    my=a.my;
    pm=new int*[mx];
    for(int i1=0;i1<mx;i1++)
    {
        pm[i1]=new int[my];
        for(int i2=0;i2<my;i2++)
        {
            pm[i1][i2]=a.pm[i1][i2];
        }
    }
}
//pm=new int*[mx];
//pm[i1]=new int[my];