#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    string str1, str2;
    // 输入两个字符串
    getline(cin, str1);
    getline(cin, str2);

    // 使用set存储字符串2中的字符，便于快速查找
    set<char> charsInStr2(str2.begin(), str2.end());
    string result;

    // 遍历字符串1，将不在字符串2中的字符加入结果
    for (char c : str1) {
        if (charsInStr2.find(c) == charsInStr2.end()) {
            result += c;
        }
    }

    // 按照ASCII顺序排序结果字符串
    sort(result.begin(), result.end());

    // 输出结果
    if (result.empty()) {
        cout << "Empty" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
