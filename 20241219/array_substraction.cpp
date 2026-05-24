#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n1, n2;
    
    // 输入第一组整数
    cin >> n1;
    vector<int> group1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> group1[i];
    }
    
    // 输入第二组整数
    cin >> n2;
    set<int> group2;
    for (int i = 0; i < n2; ++i) {
        int num;
        cin >> num;
        group2.insert(num);  // 用set去重
    }
    
    // 保存相同元素的结果
    vector<int> result;
    
    // 找到第一组中和第二组相同的元素（按照第一组的顺序）
    for (int i = 0; i < n1; ++i) {
        if (group2.find(group1[i]) != group2.end()) {
            result.push_back(group1[i]);
            group2.erase(group1[i]);  // 删除已经匹配过的元素，防止重复输出
        }
    }
    
    // 如果没有相同元素，输出"No Answer"
    if (result.empty()) {
        cout << "No Answer" << endl;
    } else {
        // 输出相同元素，按照第一组的输入顺序
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1) {
                cout <<" ";
            }
        }
        cout << endl;
    }

    return 0;
}
