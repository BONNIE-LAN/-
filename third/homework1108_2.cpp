#include<iostream>
#include<string>
using namespace std;
int main()
{
    void printAllLetterAndAscII(char ch);
    char ch;
    cout<<"Please give a small character type"<<endl;
    cin>>ch;
    printAllLetterAndAscII(ch);
}
void printAllLetterAndAscII(char ch)
{
   char ch1;
   int ch2,ch3;
   ch1=ch-32;
   ch2=ch;
   ch3=ch1;
   cout<< ch1<<" "<<ch3<<endl;
   cout<<ch<<"  "<<ch2<<endl;
}

