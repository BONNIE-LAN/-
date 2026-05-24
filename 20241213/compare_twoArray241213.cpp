#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int> array1(n);
    for(int i=0;i<n;i++)
    {
        cin>>array1[i];
    }
    
    cin>>m;
    vector<int> array2(m);
    for(int i=0;i<m;i++)
    {
        cin>>array2[i];
    }
    
    set<int> printed;  // 使用set来记录已经输出的数字
    bool found = false;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(array1[i]==array2[j] && printed.find(array1[i]) == printed.end())
            {
                cout<<array1[i]<<" ";
                printed.insert(array1[i]);
                found = true;
                break;
            }
        }
    }
    
    if(!found) {
        cout<<"No Answer";
    }
    return 0;
}