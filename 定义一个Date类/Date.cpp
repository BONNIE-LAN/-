#include<iostream>
using namespace std;
class Date
{
    private:
    int year,month,day;
    public:
    void getDate()
    {
        cin>>year>>month>>day;
    }
    void cout_Date()
    {
        if(month<10&&day<10)
        {
            cout<<year<<"-0"<<month<<"-0"<<day<<endl;
        }
        else if(day<10)
        {
            cout<<year<<"-"<<month<<"-0"<<day<<endl;
        }
        else if(month<10)
        {
            cout<<year<<"-0"<<month<<"-"<<day<<endl;
        }
        else{cout<<year<<"-"<<month<<"-"<<day<<endl;}
    }
};
int main()
{
    Date d1;
    d1.getDate();
    d1.cout_Date();
    return 0;
}