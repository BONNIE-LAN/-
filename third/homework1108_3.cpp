#include<iostream>
#include<string>
using namespace std;
void printAllLetterAndASCII()
{
    for(int i=65;i<=90;i++)
    {char ch=static_cast<char>(i);
     cout<<ch<<i<<endl;}
    for(int i=97;i<=122;i++)
    {char ch=static_cast<char>(i);
     cout<<ch<<i<<endl;}
}
int main()
{
    printAllLetterAndASCII();
    return 0;
}