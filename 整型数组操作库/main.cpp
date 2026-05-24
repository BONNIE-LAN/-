#include "operation.h"
#include "menu.h"
#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    vector<int> arr;
    bool arrayInitialized = false;
    int choice;
    showmenu();
    while (true) 
    {
        cout << "Please enter your choice: ";
        cin >> choice;
        if (!arrayInitialized) //检验第一次的输入值是否是1
        {
            if (choice != 1) 
            {
                cout << "You must first input the array. Please enter 1." <<endl;
                continue;
            }
            arrayInitialized = true;
        }

        switch (choice) //输入的数字对应的操作
        {
        case 1: //输入数组
            cout << "Enter the number of elements: ";
            int n;
            cin >> n;
            arr.resize(n);
            cin_arr(arr);
            cout << "Array has been initialized." <<endl;
            break;
        case 2: //数组排列
            sort_arr(arr);
            cout << "Array has been sorted." <<endl;
            break;
        case 3: //输入一个元素进入数组
        {
            int index, element;
            cout << "Enter the index to insert the element: ";
            cin >> index;
            cout << "Enter the element to insert: ";
            cin >> element;
            insert_element(arr, index, element);
            cout << "Element inserted." <<endl;
            break;
        }
        case 4: //查找一个元素，输出它的索引
        {
            int element;
            cout << "Enter the element to find: ";
            cin >> element;
            find_element(arr, element);
            break;
        }
        case 5: //删除一个数组中的元素
        {
            int element;
            cout << "Enter the element to delete: ";
            cin >> element;
            delete_element(arr, element);
            cout << "Element deleted." <<endl;
            break;
        }
        case 6: //根据索引输出元素
        {
            int index;
            cout << "Enter the index of the element to output: ";
            cin >> index;
            cout_sepcific_element(arr, index);
            cout <<endl;
            break;
        }
        case 7: //对指定元素求和
        {
            vector<int> indices;
            int numIndices;
            cout << "Enter the number of indices: ";
            cin >> numIndices;
            indices.resize(numIndices);
            cout << "Enter the indices: ";
            for (auto& idx : indices) {
                cin >> idx;
            }
            int sum = sum_array(indices, arr);
            cout << "Sum of specified elements: " << sum <<endl;
            break;
        }
        case 8: //输出数组
            cout_arr(arr);
            cout <<endl;
            break;
        case 9: //退出程序
            cout << "Exiting the program." <<endl;
            return 0;
        default: //输入了其他数字
            cout << "Invalid choice. Please try again." <<endl;
        }
        
    }

    return 0;
}
