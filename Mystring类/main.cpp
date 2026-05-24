#include<iostream>
#include<cstring>
#include<cmath>
#include"MyString.h"
using namespace std;
int main()
{
    MyString s1;
    char str1[] = "s1:This is a string initialized by a constructor without parameters";
    s1.assign(str1);
    s1.showMyString();
    cout << "This is the length of s1" << endl;
    int Length = s1.length();
    cout << Length << endl;
    MyString s2("s2:This is a string initialized by a constructor with a char parameters");
    s2.showMyString();
    char str3[] = "s3:This is a string initialized by a specific size";
    cout <<str3 << endl;
    cout << "Please enter the size of the s3 you want to create" << endl;
    int size;
    cin >> size;
    MyString s3(str3, min(size, (int)strlen(str3)));
    s3.showMyString();
    char findch;
    int stringNumber;
    cout << "Please enter the character you want to find" << endl;
    cin >> findch;
    cout << "Please enter the string you want to find" << endl;
    cin >> stringNumber;
    switch (stringNumber)
    {
    case 1:
        cout << "The character's index in the string is" << " "<<s1.find(findch) << endl;
        break;
    case 2:
        cout << "The character's index in the string is" <<" "<< s2.find(findch) << endl;
        break;
    case 3:
        cout << "The character's index in the string is" <<" "<< s3.find(findch) << endl;
        break;
    default:
        cout << "The stringNumber you entered is wrong" << endl;
    }
    cout << "This is the new s1,s2 after swaping them" << endl;
    s1.swap(s1, s2);
    s1.showMyString();
    s2.showMyString();
    cout << "Refresh the s1 with s2" << endl;
    s1.strcpy1(s2);
    s1.showMyString();
    cout << "This is s2 append to s1" << endl;
    s1.append(s2);
    s1.showMyString();
    return 0;
}