#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addLargeNumbers(const string& num1, const string& num2) {
    int m = num1.size(), n = num2.size();
    string result;
    int carry = 0; // 初始化进位为0

    // 从最低位开始相加
    for (int i = 0; i < max(m, n); ++i) {
        int digit1 = (i < m) ? (num1[m - 1 - i] - '0') : 0; // 如果num1的位数不够，补0
        int digit2 = (i < n) ? (num2[n - 1 - i] - '0') : 0; // 如果num2的位数不够，补0
        int sum = digit1 + digit2 + carry;
        carry = sum / 10; // 更新进位
        result.push_back((sum % 10) + '0'); // 将结果的个位数加到字符串的前面
    }

    // 如果最后还有进位，需要加到结果的前面
    if (carry > 0) {
        result.push_back(carry + '0');
    }

    // 反转字符串，因为我们是从低位加到高位的
    reverse(result.begin(), result.end());

    // 去除可能的前导零
    size_t nonZeroPos = result.find_first_not_of('0');
    if (nonZeroPos != string::npos) {
        result.erase(0, nonZeroPos); // 去除前导零
    }

    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string sum = addLargeNumbers(num1, num2);
    cout << sum << endl;
    return 0;
}
