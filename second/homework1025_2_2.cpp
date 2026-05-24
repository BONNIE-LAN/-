#include<iostream>
using namespace std;
bool isPercentage(float number){return number>=0&&number<=100;}
int main()
{
    float grade1,grade2,sum;
    cout<<"please give grade1 grade2"<<endl;
    cin>>grade1>>grade2;
    if(!isPercentage(grade1)||!isPercentage(grade2))
    {cout<<"Grade must be between 0 and 100"<<endl;}
    else {sum=grade1+grade2;
    switch((int)sum/20)
    {
        case 9:cout<<sum<<"---->A"<<endl;break;
        case 8:cout<<sum<<"---->B"<<endl;break;
        case 7:(sum>=140)&&(sum<=159);cout<<sum<<"---->C"<<endl;break;
        case 6:(sum>=120)&&(sum<=139);cout<<sum<<"---->D"<<endl;break;
        default:cout<<sum<<"---->E"<<endl;break;
    }
    }
    return 0;
}