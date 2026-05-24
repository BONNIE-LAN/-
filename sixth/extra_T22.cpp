#include<iostream>
float FirstAverage(int a[4][6]);
int FindStudent(int a[4][6]);
int FindGood(int a[4][6]);
using namespace std;
int main()
{
    int n=4,m=6;
    int a[4][6];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<6;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"the first average is "<<FirstAverage(a)<<endl;
    cout<<"The student has at least two scores below 60 is: "<<FindStudent(a)<<endl;
    FindGood(a);

}
float FirstAverage(int a[4][6])
{
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum+=a[i][1];
    }
    return sum/4.0;
}
int FindStudent(int a[4][6])
{
    int count=0;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<6;j++)
        {
            if(a[i][j]<60)
            {
                count++;
            }
        }
        if(count>=2)
        {
            for(int j=0;j<6;j++)
            {
                cout<<a[i][j]<<" ";
            }
            int sum=0;
            for(int j=1;j<6;j++)
            {
                sum+=a[i][j];
            }
            float average=sum/5.0;
            cout<<"average is "<<average<<endl;


        }
    }
    return 0;
}
int FindGood(int a[4][6])
{
    int sum=0,count=0;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<6;j++)
        {
            sum+=a[i][j];
            if(a[i][j]>=85)
            {
                count++;
            }

        }
        float average=sum/5;
        if(average>=90||count==5)
        {
            cout<<"student "<<a[i][0]<<" is good"<<endl;
        }
    }
    return 0;
}