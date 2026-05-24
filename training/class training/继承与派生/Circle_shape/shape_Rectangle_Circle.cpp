#include<iostream>
using namespace std;
class shape
{
    protected:
    float base,height,radius;
    public:
    shape(float b,float h,float r)
    {
        base=b;
        height=h;
        radius=r;
    }
};
class rectangle:public shape
{
    public:
    rectangle(float b,float h):shape(b,h,0)
    {
        base=b;
        height=h;
    }
    double GetArea()
    {
        double area=(base*height)/2;
        return area;
    }
};
class circle:public shape
{
    public:
    circle(float r):shape(0,0,r)
    {
        radius=r;
    }
    void GetArea()
    {
        cout<<"The area of this circle is:"<<(3.14*radius*radius)<<endl;
    }
};
class spuare:public rectangle
{
    public:
    spuare(float b,float h):rectangle(b,h)
    {
        base=b;
        height=h;
    }
    void GeatArea()
    {
        cout<<"The area of this spuare is:"<<2*GetArea()<<endl;
    }

};
int main()
{
    rectangle r(5,6);
    cout<<"The area of this rectangle is:"<<r.GetArea()<<endl;
    circle c(10);
    c.GetArea();
    spuare s(5,6);
    s.GeatArea();
    return 0;
}