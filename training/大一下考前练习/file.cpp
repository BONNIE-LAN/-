#include<fstream>
#include<iostream>
using namespace std;
int main()
{
    int values[10]={1,2,3,4,5,6,7,8,9,10};
    ofstream ofs("data1.txt",ios::binary);
    ofs.write(reinterpret_cast<char*>(&values),sizeof(values));
    ofs.close();
    ifstream ifs("data1.txt",ios::binary);
    ifs.read(reinterpret_cast<char*>(&values),sizeof(values));
    ifs.close();
    int max=values[0];
    int min=values[0];
    double average=0;
    int sum=0;
    for(int i=0;i<10;i++)
    {
        cout<<values[i]<<" ";
        sum+=values[i];
        if(values[i]>max)
        {
            max=values[i];
        }
        if(values[i]<min)
        {
            min=values[i];
        }
    }
    average=sum/10;
    cout  << max << endl;
    cout << min<< endl;
    cout << average<< endl;
    ofstream ofs_append("data1.txt", ios::binary | ios::app);
    int newData[5] = {11, 12, 13, 14, 15};
    ofs_append.write(reinterpret_cast<char*>(newData), sizeof(newData));
    ofs_append.close();
    return 0;
}