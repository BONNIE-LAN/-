#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    int n,key;
    cin>>n;
    if(n<1&&n>26)
    {cout<<"Please enter a number between 1 and 25"<<endl;}
    else{key=n;}
    ifstream inFile;
    inFile.open("in.txt");
    char ch;
    ofstream outFile;
    outFile.open("out.txt");
    while(inFile.get(ch))
    {
    if(ch>='A'&&ch<='Z')
    {
        ch='A'+ (( ch - 'A' + key ) % 26);
    }
    if(ch>='a'&&ch<='z')
    {
        ch='a'+ (( ch - 'a' + key ) % 26);
    }
    outFile<<ch;
    }
    inFile.close();
    outFile.close();
    return 0;
}