#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 定义函数，判断是否为运算符
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 定义运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 中缀转后缀表达式函数
string infixToPostfix(string infix) {
    stack<char> s; // 运算符栈
    string postfix = ""; // 存储后缀表达式

    for (char c : infix) {
        // 如果是数字，直接添加到结果
        if (isdigit(c)) {
            postfix += c;
        }
        // 如果是左括号，入栈
        else if (c == '(') {
            s.push(c);
        }
        // 如果是右括号，弹出所有运算符直到遇到左括号
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 弹出左括号
        }
        // 如果是运算符
        else if (isOperator(c)) {
            // 弹出优先级 >= 当前运算符的栈顶运算符
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // 当前运算符入栈
        }
    }

    // 弹出栈中剩余的运算符
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cin >> infix; // 输入中缀表达式（无空格）

    string postfix = infixToPostfix(infix); // 转换为后缀表达式
    cout << postfix << endl;

    return 0;
}
