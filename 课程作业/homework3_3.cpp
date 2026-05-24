#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string M, string N) {
    reverse(M.begin(), M.end());
    reverse(N.begin(), N.end());
    int carry = 0;
    string result;
    for (size_t i = 0; i < max(M.size(), N.size()); ++i) {
        int sum = carry;
        if (i < M.size()) sum += M[i] - '0';
        if (i < N.size()) sum += N[i] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}
string subtract(string M, string N) {
    reverse(M.begin(), M.end());
    reverse(N.begin(), N.end());
    string result;
    int borrow = 0;
    for (size_t i = 0; i < max(M.size(), N.size()); ++i) {
        int diff = borrow;
        if (i < M.size()) diff += M[i] - '0';
        if (i < N.size()) diff -= N[i] - '0';
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    reverse(result.begin(), result.end());
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    return result;
}
string multiply(string M, string N) {
    string result(M.size() + N.size(), '0');
    reverse(M.begin(), M.end());
    reverse(N.begin(), N.end());
    for (size_t i = 0; i < N.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < M.size(); ++j) {
            int prod = (N[i] - '0') * (M[j] - '0') + (result[i + j] - '0') + carry;
            result[i + j] = (prod % 10) + '0';
            carry = prod / 10;
        }
        result[i + M.size()] += carry;
    }
    reverse(result.begin(), result.end());
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    return result;
}

int main() {
    string M, N, operation;
    cout << "请输入第一个大整数M: ";
    cin >> M;
    cout << "请输入运算符(+, -, *): ";
    cin >> operation;
    cout << "请输入第二个大整数N: ";
    cin >> N;

    string result;
    if (operation == "+") {
        result = add(M, N);
    } else if (operation == "-") {
        result = subtract(M, N);
    } else if (operation == "*") {
        result = multiply(M, N);
    } else {
        cout << "无效的运算符！" << endl;
        return 1;
    }

    // 输出结果
    if (result[0] == '0') {
        cout << "0" << endl;
    } else if (M[0] == '-' && operation == "+" && N[0] == '-') {
        cout << "-" << result << endl;
    } else if (M[0] == '-' && operation == "-" && N[0] == '-') {
        cout << "+" << result << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}