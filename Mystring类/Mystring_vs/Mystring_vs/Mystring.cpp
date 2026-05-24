#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
class MyString
{
public:
    MyString();//构造函数
    ~MyString();//析构函数
    MyString(const MyString& other);//拷贝构造函数
    MyString(const char* c);//用字符串初始化
    MyString(char c[], int size);//用字符串的前size个字符初始化
    void append(MyString& s);//将s连接在后面
    void assign(char c[]);//把字符串c赋值给当前string字符串
    int length();//返回mystring类字符串长度
    void swap(MyString& s1, MyString& s2);//交换两个字符串
    int find(char ch);//在mystring中寻找ch返回位置号
    void showMyString();//输出字符串到屏幕
    MyString& strcpy1(const MyString& s1);//将当前的字符串刷新为s1
private:
    char* data;//字符串指针
    int Size;
};
MyString::MyString()
{
    data = new char[1];//分配一个字符的空间，用于存储空字符串
    data[0] = '\0';
    Size = 0;
}
MyString::MyString(const MyString& other)
{
    Size = other.Size;
    data = new char[Size + 1];
    strcpy_s(data, Size + 1, other.data);
}
MyString::~MyString()
{
    delete[]data;
}
MyString::MyString(const char* c)
{
    data = new char[strlen(c) + 1];
    strcpy_s(data, strlen(c) + 1, c);
    Size = strlen(c);
}
MyString::MyString(char c[], int size)
{
    int actualSize = min(size, (int)strlen(c));
    data = new char[actualSize + 1];
    strncpy_s(data, actualSize + 1, c,actualSize);//限制复制字符数
    data[actualSize] = '\0';//显示添加终止符
    Size = actualSize;
}
void MyString::append(MyString& s)
{
    int newSize = Size + s.Size;//扩大size的长度
    char* newData = new char[newSize + 1];//分配更多的内存给data
    strcpy_s(newData, newSize + 1, data);//复制当前的字符串到新的内存空间
    strcat_s(newData+Size,newSize+1-Size, s.data);//连接字符串
    delete[] data;
    //更新指针和大小
    data = newData;
    Size = newSize;
}
void MyString::assign(char c[])
{
    delete[]data;
    data = new char[strlen(c) + 1];
    strcpy_s(data, strlen(c) + 1, c);
    Size = strlen(c);
}
int MyString::length()
{
    return strlen(data);
}
void MyString::swap(MyString& s1, MyString& s2)
{
    std::swap(s1.data, s2.data);
    std::swap(s1.Size, s2.Size);
}
int MyString::find(char ch)
{
    char* pos = strchr(data, ch);//定位ch在data中的位置
    if (pos != nullptr)
    {
        return pos - data;//返回ch在data中的位置
    }
    else
    {
        cout << "The character is not found in the string" << endl;
        return -1;
    }
}
void MyString::showMyString()
{
    cout << data << endl;
}
MyString& MyString::strcpy1(const MyString& s1)
{
    delete[] data;//先释放原有内存
    data = new char[strlen(s1.data) + 1];
    strcpy_s(data, strlen(s1.data) + 1, s1.data);
    Size = s1.Size;
    return *this;
}