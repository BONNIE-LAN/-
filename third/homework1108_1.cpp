#include<iostream>
#include<string>
using namespace std;
void checkCharacterType(char ch)
{
    if(ch>='a'&&ch<='z'){cout<<"small type"<<endl;}
    else if(ch>='A'&&ch<='Z'){cout<<"big type"<<endl;}
    else if(ch>='0'&&ch<='9'){cout<<"a number"<<endl;}
    else{cout<<"other character type"<<endl;}
}
int main()
{
    char ch;
    cout<<"please give me a character"<<endl;
    cin>>ch;
    checkCharacterType(ch);
    return 0;
}