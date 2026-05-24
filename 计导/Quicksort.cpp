#include <iostream>
using namespace std;

// 分区函数，返回基准元素的最终位置
int partition(int array[], int low, int high) {
    int pivot = array[high];    // 选择最后一个元素作为基准
    int i = (low - 1);         // 小于基准的元素的位置

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于基准
        if (array[j] < pivot) {
            i++;    // 移动小于基准的元素的位置
            // 交换元素
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // 将基准放到正确的位置
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

// 快速排序函数
void quick_sort(int array[], int low, int high) {
    if (low < high) {
        // 获取基准元素的位置
        int pi = partition(array, low, high);

        // 分别对基准元素左右两边的子数组进行排序
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
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
    
    quick_sort(array, 0, n-1);
    
    cout << "排序后数组: ";
    print_array(array, n);
    
    // 释放动态分配的内存
    delete[] array;
    
    return 0;
}