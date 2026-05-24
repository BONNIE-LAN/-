#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float *radius= new float;
    cout<<"Please enter the radius of the circle:";
    cin>>*radius;
    float area=M_PI*(*radius)*(*radius);
    cout<<"The area of the circle is"<<" "<<area<<endl;
    delete radius;
    return 0;
}