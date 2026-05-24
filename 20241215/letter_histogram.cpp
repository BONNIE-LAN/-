#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    // 输入一段英文文本
    
    string input;
    char ch;
    vector<int> frequency(26, 0);

    // 统计小写字母的出现次数
    while (cin.get(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            frequency[ch - 'a']++;
        }
    }

    // 找到最高的字母出现次数，用于柱状图高度
    int maxFrequency = *max_element(frequency.begin(), frequency.end());
    if (maxFrequency == 0) {
        cout << "" << endl;
        return 0;
    }

    // 按出现次数从大到小排序，保留字母和频率的对应关系
    vector<pair<char, int>> charFrequency;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] > 0) {
            charFrequency.push_back({static_cast<char>('a' + i), frequency[i]});
        }
    }
    sort(charFrequency.begin(), charFrequency.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; // 按出现次数从大到小排序
    });

    // 输出柱状图
    
    for (int i = maxFrequency; i > 0; --i) {
        for (const auto& p : charFrequency) {
            if (p.second >= i) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

   
    cout << endl;

    return 0;
}
