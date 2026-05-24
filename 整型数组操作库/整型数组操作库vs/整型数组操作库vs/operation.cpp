#include<iostream>
#include<algorithm>
#include<vector>
#include <graphics.h>
#include <conio.h>
#include"menu.h"
using namespace std;
void cin_arr(vector<int>& arr);//输入数组
void sort_arr(vector<int>& arr);//数组排列
void insert_element(vector<int>& arr, int index, int element);//输入一个元素进入数组
void find_element(const vector<int>& arr, int element);//根据元素输出索引
void delete_element(vector<int>& arr, int element);//删除元素
void cout_arr(const vector<int>& arr);//输出数组
void cout_sepcific_element(const vector<int>& arr, int index);//根据索引输出元素
int sum_array(vector<int>& indices, const vector<int>& arr);//对指定索引的元素求和
void cin_arr(vector<int>& arr)
{
    for (auto& num : arr)
    {
        cin >> num;
    }
}
void sort_arr(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    cout_arr(arr);
}
void insert_element(vector<int>& arr, int index, int element)
{
    if (index >= 0 && index <= arr.size())
    {
        arr.resize(arr.size() + 1);
        for (int i = arr.size() - 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        cout_arr(arr);
    }
    else
    {
        cout << "index out of range" << endl;
    }
}
// 增强find_element显示效果
void find_element(const vector<int>& arr, int element) {
    bool found = false;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            TCHAR msg[50];
            _stprintf_s(msg, _T("找到元素 %d 在索引 [%d]"), element, i);
            MessageBox(GetHWnd(), msg, _T("查找结果"), MB_OK);
            found = true;
            break;
        }
    }
    if (!found) {
        TCHAR msg[50];
        _stprintf_s(msg, _T("元素 %d 不存在于数组中"), element);
        MessageBox(GetHWnd(), msg, _T("查找结果"), MB_OK);
    }
}
void delete_element(vector<int>& arr, int element)
{
    bool found = false;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
        {
            arr.erase(arr.begin() + i);
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "The element is not in the array" << endl;
    }
    cout_arr(arr);
}
void cout_arr(const vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
void cout_sepcific_element(const vector<int>& arr, int index)
{
    if (index >= 0 && index < arr.size()) {
        cout <<"The number in the array is"<<" "<<arr[index];
    }
    else
    {
        cout << "Invalid index";
    }
}
int sum_array(vector<int>& indices, const vector<int>& arr)
{
    int sum = 0;
    for (int idx : indices)
    {
        if (idx >= 0 && idx < arr.size())
        {
            sum += arr[idx];
           
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }
    return sum;
    
}