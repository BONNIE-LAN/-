#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 函数：模拟两个超长正整数的减法
string subtractBigNumbers(string A, string B) {
    // 如果A小于B，交换A和B，并设置结果为负号
    bool isNegative = false;
    if (A.length() < B.length() || (A.length() == B.length() && A < B)) {
        swap(A, B);
        isNegative = true;
    }

    int lenA = A.length(), lenB = B.length();
    int carry = 0;  // 用于存放借位
    string result = "";

    // 从低位到高位进行减法
    for (int i = 0; i < lenA; i++) {
        int digitA = A[lenA - 1 - i] - '0';  // 获取A的当前位
        int digitB = (i < lenB) ? (B[lenB - 1 - i] - '0') : 0;  // 获取B的当前位

        int diff = digitA - digitB - carry;  // 当前位的差值，考虑借位

        if (diff < 0) {
            diff += 10;  // 借位
            carry = 1;   // 设置借位
        } else {
            carry = 0;   // 不需要借位
        }

        result += (diff + '0');  // 将结果的当前位添加到结果字符串
    }

    // 去除结果字符串的前导零
    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    // 如果结果为0，返回"0"
    if (result.empty()) {
        return "0";
    }

    // 如果是负数，则加上负号
    if (isNegative) {
        result += '-';
    }

    // 结果需要反转才能从高位到低位输出
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    // 输出两个超长正整数的差
    cout << subtractBigNumbers(A, B) << endl;

    return 0;
}
