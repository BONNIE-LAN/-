#include<iostream>
using namespace std;
bool isPercentage(float number){return number>=0&&number<=100;}
int main()
{
    float grade1,grade2,sum;
    cout<<"please give grade1 grade2"<<endl;
   cin>>grade1>>grade2;
    if((isPercentage(grade1))&&(isPercentage(grade2)))
    {
        sum=grade1+grade2;
        if(sum>=180)cout<<sum<<"---->A"<<endl;
        if((sum>=160)&&(sum<=179))cout<<sum<<"---->B"<<endl;
        if((sum>=140)&&(sum<=159))cout<<sum<<"---->C"<<endl;
        if((sum>=120)&&(sum<=139))cout<<sum<<"---->D"<<endl;
        if(sum<120)cout<<sum<<"---->E"<<endl;
    }
    else{ cout<<"The input is wrong"<<endl;}
    return 0;
}
