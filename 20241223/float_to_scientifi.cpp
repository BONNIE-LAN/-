#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

string toScientificNotation(const string& number) {
    // 找到小数点的位置
    size_t dotPos = number.find('.');
    
    // 提取整数部分和小数部分
    string integerPart = number.substr(0, dotPos);
    string decimalPart = number.substr(dotPos + 1);

    // 计算指数
    int exponent = 0;
    
    // 如果小数点左边是1以上的数字，指数部分为0
    if (integerPart != "0") {
        exponent = integerPart.length() - 1;
    } else {
        // 小数点左边为0的情况
        int firstNonZeroDigitIndex = decimalPart.find_first_not_of('0');
        if (firstNonZeroDigitIndex != string::npos) {
            exponent = -(firstNonZeroDigitIndex + 1);
            // 从第一个非零数字开始
            integerPart = decimalPart.substr(firstNonZeroDigitIndex, 1);
            decimalPart = decimalPart.substr(firstNonZeroDigitIndex + 1);
        }
    }

    // 构造底数部分
    string base = integerPart + "." + decimalPart;
    
    // 去掉尾部的多余0
    while (!base.empty() && base.back() == '0') {
        base.pop_back();
    }

    // 拼接科学计数法形式
    return base + "e" + to_string(exponent);
}

int main() {
    string input;
    cin >> input;

    string result = toScientificNotation(input);
    cout << result << endl;

    return 0;
}
