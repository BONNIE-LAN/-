#include<iostream>
using namespace std;
#define PI 3.14159
class container
{
    public:
    virtual double getArea()=0;
    virtual double getVolume()=0;
    container(double r):radius(r){};
    double radius;
};
class cube:public container
{
    public:
    cube(double r):container(r){};
    double getArea()
    {
        double area;
        area=6*radius*radius;
        cout<<"The area is"<<area<<endl;
        return area;
    }
    double getVolume()
    {
        double volume;
        volume=radius*radius*radius;
        cout<<"The volume is"<<volume<<endl;
        return volume;
    }
};
class sphere:public container
{
    public:
    sphere(double r):container(r){};
    double getArea()
    {
        double area;
        area=4*PI*radius*radius;
        cout<<"The area is"<<area<<endl;
        return area;
    }
    double getVolume()
    {
        double volume;
        volume=(4.0/3.0)*PI*radius*radius*radius;
        cout<<"The volume is"<<volume<<endl;
        return volume;
    }
};
class cylinder:public container
{
    protected:
    double height;
    public:
    cylinder(double r,double h):container(r),height(h){};
    double getArea()
    {
        double area;
        area=2*PI*radius*height;
        cout<<"The area is"<<area<<endl;
        return area;
    }
    double getVolume()
    {
        double volume;
        volume=PI*radius*radius*height;
        cout<<"The volume is"<<volume<<endl;
        return volume;
    }

};
int main()
{
    cube c1(4);
    sphere s1(4);
    cylinder cy(4,4);
    container *p;
    p=&c1;
    p->getArea();
    p=&s1;
    p->getArea();
    p=&cy;
    p->getArea();
    return 0;
}