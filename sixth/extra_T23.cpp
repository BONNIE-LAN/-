#include<iostream>
using namespace std;
struct Student
{
        int id;
        int score[5];
};
float FirstAverage(Student students[],int n);
void FindStudent(Student students[],int n);
void FindGood(Student students[],int n);
int main()
{
    const int n=4;
    Student students[n];
    for(int i=0;i<n;i++)
    {
        cin>>students[i].id;
        for(int j=0;j<5;j++)
        {
            cin>>students[i].score[j];
        }

    }
    cout<<"First subject average score:"<<FirstAverage(students,n)<<endl;
    FindStudent(students,n);
    FindGood(students,n);
    return 0;
    
}
float FirstAverage(Student students[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=students[i].score[0];
    }
    return sum/float(n);
}
void FindStudent(Student students[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        int failcount=0;
        int sum=0;
        for(int j=0;j<5;j++)
        {
            if(students[i].score[j]<60)
            {
                failcount++;
            }
            sum+=students[i].score[j];
        }
        if(failcount>=2)
    {
        cout<<"The student has at least two scores below 60 is: "<<students[i].id<<endl;
        cout<<"Score:";
        for(int j=0;j<5;j++)
        {
            cout<<students[i].score[j]<<" ";
        }
        cout<<"Average is "<<sum/5.0<<endl;
    }
       
    }
   
}
void FindGood(Student students[],int n)
{
   
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int highcount=0;
        for(int j=0;j<5;j++)
        {
            sum+=students[i].score[j];
            if(students[i].score[j]>=85)
            {
                highcount++;
            }
        }
        float average=sum/5.0;
        if(average>=90||highcount==5)
        {
            cout<<"student "<<students[i].id<<" is good"<<endl;
        }
    }
}