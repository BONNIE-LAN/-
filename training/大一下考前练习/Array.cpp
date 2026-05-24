#include<iostream>
using namespace std;
template <typename T>
class Array
{
    private:
    T *element;
    int size;
    public:
    Array(T *e,int s);
    Array();
    template <typename U>
    friend ostream& operator<<(ostream& output,Array<U>& a);
    template <typename U>
    friend istream& operator>>(istream& input,Array<U>& a);
    ~Array();
};
template <typename T>
Array<T>::Array(T *e,int s)
{
    size=s;
    element=new T[size];
    for(int i=0;i<size;i++)
    {
        element[i]=e[i];
    }
}
template <typename T>
Array<T>::Array()
{
    element=new T[size];
    for(int i=0;i<size;i++)
    {
        element[i]=0;
    }
    size=0;
}
template <typename U>
ostream& operator<<(ostream& output,Array<U>& a)
{
    for(int i=0;i<a.size;i++)
    {
        output<<a.element[i]<<" ";
    }
    return output;
}
template <typename U>
istream& operator>>(istream& input,Array<U>& a)
{
    input>>a.size;
    for(int i=0;i<a.size;i++)
    {
        input>>a.element[i];
    }
    return input;
}
template <typename T>
Array<T>::~Array()
{
    delete[ ] element;
}
int main()
{
    Array<int> a1;
    cin>>a1;
    cout<<a1;
    return 0;

}
