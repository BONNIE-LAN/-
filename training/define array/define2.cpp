#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* array = new int[n];
      // 使用完后要记得释放内存
    delete[] array;
}