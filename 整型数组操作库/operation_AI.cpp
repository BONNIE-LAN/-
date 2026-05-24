#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 函数声明
void cin_arr(vector<int>& arr);
void sort_arr(vector<int>& arr);
bool insert_element(vector<int>& arr, int x);
int find_element(const vector<int>& arr, int x);
bool delete_element(vector<int>& arr, int x);
void cout_arr(const vector<int>& arr);
void cout_specific_element(const vector<int>& arr, int index);
int sum_array(const vector<int>& indices, const vector<int>& arr);

int main() {
    // 输入主数组
    int n;
    cin >> n;
    vector<int> arr(n);
    cin_arr(arr);
    
    // 排序并输出
    sort_arr(arr);
    cout << "Sorted array: ";
    cout_arr(arr);
    
    // 插入操作
    int insert_num;
    cin >> insert_num;
    if(insert_element(arr, insert_num)) {
        cout << "After insertion: ";
        cout_arr(arr);
    } else {
        cout << "Insertion failed!" << endl;
    }
    
    // 查找操作
    int find_num;
    cin >> find_num;
    int pos = find_element(arr, find_num);
    if(pos != -1) {
        cout << "Found at index: " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    // 删除操作
    int del_num;
    cin >> del_num;
    if(delete_element(arr, del_num)) {
        cout << "After deletion: ";
        cout_arr(arr);
    } else {
        cout << "Delete failed!" << endl;
    }
    
    // 输出指定元素
    int index;
    cin >> index;
    cout << "Element at " << index << ": ";
    cout_specific_element(arr, index);
    cout << endl;
    
    // 求和操作
    int m;
    cin >> m;
    vector<int> indices(m);
    for(int i=0; i<m; i++) {
        cin >> indices[i];
    }
    cout << "Sum: " << sum_array(indices, arr) << endl;
    
    // 最终输出
    cout << "Final array: ";
    cout_arr(arr);
    
    return 0;
}

// 输入数组
void cin_arr(vector<int>& arr) {
    for(auto& num : arr) {
        cin >> num;
    }
}

// 排序函数（使用标准库排序）
void sort_arr(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

// 插入元素（保持有序）
bool insert_element(vector<int>& arr, int x) {
    // 查找插入位置
    auto it = upper_bound(arr.begin(), arr.end(), x);
    arr.insert(it, x);
    return true;
}

// 查找元素（返回首个匹配位置）
int find_element(const vector<int>& arr, int x) {
    auto it = find(arr.begin(), arr.end(), x);
    return (it != arr.end()) ? distance(arr.begin(), it) : -1;
}

// 删除元素（删除所有匹配项）
bool delete_element(vector<int>& arr, int x) {
    auto new_end = remove(arr.begin(), arr.end(), x);
    bool removed = new_end != arr.end();
    arr.erase(new_end, arr.end());
    return removed;
}

// 输出数组
void cout_arr(const vector<int>& arr) {
    for(const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 输出指定索引元素
void cout_specific_element(const vector<int>& arr, int index) {
    if(index >=0 && index < arr.size()) {
        cout << arr[index];
    } else {
        cout << "Invalid index";
    }
}

// 求和函数
int sum_array(const vector<int>& indices, const vector<int>& arr) {
    int sum = 0;
    for(int idx : indices) {
        if(idx >=0 && idx < arr.size()) {
            sum += arr[idx];
        }
    }
    return sum;
}