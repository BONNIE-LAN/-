#include <iostream>
using namespace std;
void insertion_sort(int array[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        
        // 将比key大的元素都向后移动一位
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// 打印数组的函数
void print_array(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    
    cout << "原始数组: ";
    print_array(array, n);
    
    insertion_sort(array, n);
    
    cout << "排序后数组: ";
    print_array(array, n);
    
    return 0;
}