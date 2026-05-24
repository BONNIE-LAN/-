#pragma once
class MyString
{
public:
    MyString();//构造函数
    ~MyString();//析构函数
    MyString(const MyString& other);//拷贝构造函数
    MyString(const char* c);//用字符串初始化
    MyString(char c[], int size);//用字符串的前size个字符初始化
    void append(MyString& s);//将s连接在后面
    void assign(char c[]);//把字符串c赋值该当前string字符串
    int length();//返回mystring类字符串长度
    void swap(MyString& s1, MyString& s2);//交换两个字符串
    int find(char ch);//在mystring中寻找ch返回位置号
    void showMyString();//输出字符串到屏幕上
    MyString& strcpy1(const MyString& s1);
private:
    char* data;//字符串指针
    int Size;
};
