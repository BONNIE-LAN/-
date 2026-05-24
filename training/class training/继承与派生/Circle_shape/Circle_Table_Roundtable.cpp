#include<iostream>
#include<string>
using namespace std;
class Circle
{
    protected:
    float radius;
    public:
    Circle(float r)
    {
        radius=r;
    }
    double getArea()
    {
        double area=3.14*radius*radius;
        return area;
    }
};
class Table
{
    protected:
    float height;
    public:
    Table(float h)
    {
        height=h;
    }
    int feedbackHight()
    {
        return height;
    }
};
class Roundtable:public Circle,public Table
{
    private:
    string color;
    public:
    Roundtable(float r,float h,string c):Circle(r),Table(h)
    {
        color=c;
    }
    void cout_member()
    {
        cout<<"The color of this roundtable is:"<<color<<endl;
        cout<<"The area of this roundtable is:"<<getArea()<<endl;
        cout<<"The height of this roundtable is:"<<height<<endl;
    }

};
int main()
{
    Roundtable greentable(30,120.0,"green");
    greentable.cout_member();
    return 0;
}
