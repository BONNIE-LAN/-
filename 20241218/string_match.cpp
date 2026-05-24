#include <iostream>
#include <fstream>  // 文件操作
#include <string>
#include <vector>
#include <regex>
#include <unordered_set>
using namespace std;

// 转换字符串为小写
string toLower(const string &s) {
    string res = s;
    for (char &c : res) c = tolower(c);
    return res;
}

// 将模式字符串转换为正则表达式
string buildRegex(const string &pattern) {
    string regexPattern;
    bool inBracket = false;

    for (size_t i = 0; i < pattern.size(); ++i) {
        char c = pattern[i];
        if (c == '*') {
            regexPattern += ".*";
        } else if (c == '[') {
            inBracket = true;
            regexPattern += '[';
        } else if (c == ']') {
            inBracket = false;
            regexPattern += ']';
        } else if (c == '^' && inBracket) {
            regexPattern += "^";
        } else {
            regexPattern += tolower(c);
        }
    }
    return regexPattern;
}

// 查找符合正则表达式的子串，并去重保留顺序
vector<string> findMatches(const string &line, const string &regexPattern) {
    vector<string> matches;
    smatch sm;
    regex re(regexPattern, regex::icase);
    unordered_set<string> seen;  // 用于去重，但不影响顺序

    auto start = line.cbegin();
    while (regex_search(start, line.cend(), sm, re)) {
        string match = sm.str();
        if (seen.find(match) == seen.end()) {  // 如果没出现过
            matches.push_back(match);
            seen.insert(match);  // 标记为已出现
        }
        start = sm[0].second;
    }

    return matches;
}

int main() {
    ifstream inputFile("string.in");
    ofstream outputFile("string.out");

    if (!inputFile) {
        cerr << "Error: Cannot open input file 'string.in'!" << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Error: Cannot open output file 'string.out'!" << endl;
        return 1;
    }

    // 读取匹配模式
    string pattern;
    cout << "Enter the search pattern: ";
    getline(cin, pattern);

    string regexPattern = buildRegex(pattern);
    string line;
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        ++lineNumber;

        vector<string> matches = findMatches(toLower(line), regexPattern);
        if (!matches.empty()) {
            outputFile << lineNumber << ":";
            for (size_t i = 0; i < matches.size(); ++i) {
                if (i > 0) outputFile << ",";
                outputFile << matches[i];
            }
            outputFile << endl;
        }
    }

    cout << "Search completed. Results are saved in 'string.out'." << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
