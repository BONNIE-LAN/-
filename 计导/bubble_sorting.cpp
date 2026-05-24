#include <iostream>
using namespace std;

// 冒泡排序函数
void bubble_sort(int array[], int n) {
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        // 每次循环将最大的元素冒泡到末尾
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // 交换元素
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        // 如果没有发生交换，说明数组已经有序
        if (!swapped) {
            break;
        }
    }
}

// 打印数组函数
void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "请输入数组的大小: ";
    cin >> n;
    
    // 动态分配数组
    int* array = new int[n];
    
    cout << "请输入" << n << "个整数:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    cout << "原始数组: ";
    print_array(array, n);
    
    bubble_sort(array, n);
    
    cout << "排序后数组: ";
    print_array(array, n);
    
    // 释放动态分配的内存
    delete[] array;
    
    return 0;
}