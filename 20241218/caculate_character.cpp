#include <iostream>
using namespace std;

int main() {
    char c;                   // 用于存储当前读取的字符
    int spaceCount = 0;       // 空格计数
    int tabCount = 0;         // 制表符计数
    int newlineCount = 0;     // 回车符计数

    while (cin.get(c)) {      // 逐个字符读取
        if (c == ' ') {
            ++spaceCount;     // 统计空格
        } else if (c == '\t') {
            ++tabCount;       // 统计制表符
        } else if (c == '\n') {
            ++newlineCount;   // 统计回车符
        }
    }

    // 修正 EOF 可能带来的多余回车符
    if (cin.eof()) {
        --newlineCount;       // 遇到 EOF 时，回车符计数可能多加了 1，修正
    }

    // 输出结果，按格式要求，中间用空格分隔，末尾无空格
    cout << spaceCount << " " << tabCount << " " << newlineCount;

    return 0;
}
