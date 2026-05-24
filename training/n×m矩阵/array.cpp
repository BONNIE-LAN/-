#include<iostream>
using namespace std;
class Array
{
    private:
    int n;
    int m;
    public:
    Array(int h,int l);
    int cin_data();
    void display();
    Array(const Array&other);
    ~Array();
};
Array::Array(int h,int l)
{
    n=h;
    m=l;
}
int Array::cin_data()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
        }
    }
}
void Array::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

        }
    }
}