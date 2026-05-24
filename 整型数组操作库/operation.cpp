#include<iostream>
#include<algorithm>
#include<vector>
#include"menu.h"
using namespace std;
void cin_arr(vector<int>& arr);
void sort_arr(vector<int>& arr);
void insert_element(vector<int>& arr,int index,int element);
void find_element(const vector<int>& arr,int element);
void delete_element(vector<int>& arr,int element);
void cout_arr(const vector<int>& arr);
void cout_sepcific_element(const vector<int>& arr,int index);
int sum_array(vector<int>& indices,const vector<int>& arr);
void cin_arr(vector<int>& arr)
{
    for(auto& num : arr)
    {
        cin>>num;
    }
}
void sort_arr(vector<int>& arr)
{
   sort(arr.begin(),arr.end());
   cout_arr(arr);
}
void insert_element(vector<int>& arr,int index,int element)
{
   if(index>=0&&index<=arr.size())
    {   arr.size()+1;
        for(int i=arr.size()-1;i>index;i--)
      {
       arr[i]=arr[i-1];
       }
       arr[index]=element;
       cout_arr(arr);
    }
    else
    {
        cout<<"index out of range"<<endl;
    }
}
void find_element(const vector<int>& arr,int element)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==element)
        {
            cout<< "The element is in the"<<i<<"index of the array";
        }
    }
}
void delete_element(vector<int>& arr,int element)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==element)
        {
            for(int j=i;j<arr.size();j++)
            {
                arr[j]=arr[j+1];
            }
        }
    }
    cout_arr(arr);
}
void cout_arr(const vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
void cout_sepcific_element(const vector<int>& arr,int index)
{
    if(index >=0 && index < arr.size()) {
        cout << arr[index];
    } 
    else 
    {
        cout << "Invalid index";
    }
}
int sum_array(vector<int>& indices,const vector<int>& arr)
{
    int sum=0;
    for(int idx : indices) 
    {
        if(idx >=0 && idx < arr.size()) 
        {
            sum += arr[idx];
        }
        else
        {
            cout << "Invalid index"<<endl;
        }
    }
    return sum;
}
