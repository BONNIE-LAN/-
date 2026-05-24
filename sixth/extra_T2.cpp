#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void in_array(vector<int>& arr,int n);
void operation(vector<int>& arr,int n);
void out_array(vector<int>& arr,int n);
int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  in_array(arr,n);
  operation(arr,n);
  out_array(arr,n); 
}
void in_array(vector<int> &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void operation(vector<int> &arr,int n)
{
    int Min=arr[0],Max=arr[0];
    int MinIndex=0,MaxIndex=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<Min)
        {
            Min=arr[i];
            MinIndex=i;
        }
         if(arr[i]>Max)
        {
            Max=arr[i];
            MaxIndex=i;
        }
    }
   
   swap(arr[MinIndex],arr[0]);
   swap(arr[MaxIndex],arr[n-1]);
}
void out_array(vector<int> &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}