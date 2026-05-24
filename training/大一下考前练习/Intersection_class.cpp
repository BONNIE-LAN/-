#include<iostream>
using namespace std;
class Intersection
{
    public:
    Intersection(int *s,int I);
    Intersection();
    int f(int num);
    Intersection operator&&(Intersection t);
    void show();
    private:
    int set[20];
    int len;
};
Intersection::Intersection(int *s,int I)
{
    len=I;
    for(int i=0;i<I;i++)
    {
        set[i]=s[i];
    }
}
Intersection::Intersection()
{
    for(int i=0;i<20;i++)
    {
        set[i]=0;
    }
    len=0;
}
int Intersection::f(int num)
{
    for(int i=0;i<len;i++)
    {
        if(set[i]==num)
        {
            return 1;
            break;
        }
    }
    return 0;
}
Intersection Intersection:: operator&&(Intersection t)
{
    Intersection Jset;
    int k=0;
    for(int i=0;i<t.len;i++)
    {
        if(t.f(set[i])==1)
        {
            Jset.set[k++]=set[i];
        }
    }
    Jset.len=k;
    return Jset;
}
void Intersection::show()
{
    for(int i=0;i<len;i++)
    {
        cout<<set[i]<<" ";
    }
}
int main()
{
    int s1[6]={1,3,4,5,7,8};
    int s2[7]={1,2,3,5,7,9};
    Intersection obj1(s1,6);
    Intersection obj2(s2,7);
    Intersection obj3;
    obj3=obj1&&obj2;
    obj3.show();
    return 0;
}
