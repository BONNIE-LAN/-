#include<iostream>
using namespace std;
int main()
{
    void selection_sort(int array[],int n);
    int n;
    cout<<"enter the number of elements:";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    selection_sort(array,n);
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
void selection_sort(int array[],int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[min_idx])
            {
                min_idx=j;
            }
        }
        swap(array[i],array[min_idx]);
    }
}