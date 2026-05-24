#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 模拟大数乘法
string multiply(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    // 从数字的最后一位开始相乘
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // 处理结果中的前导零
    string resultStr = "";
    for (int i : result) {
        if (!(resultStr.empty() && i == 0)) {
            resultStr += to_string(i);
        }
    }

    return resultStr.empty() ? "0" : resultStr;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    cout << multiply(a, b) << endl;
    
    return 0;
}
