#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

bool checkParentheses(const string& code) {
    stack<char> brackets;
    int leftCount = 0, rightCount = 0;
    bool inComment = false;
    char lastChar = '\0';
    
    for(size_t i = 0; i < code.length(); i++) {
        char c = code[i];
        
        // Skip comments
        if(i < code.length() - 1 && c == '/' && code[i+1] == '/') {
            while(i < code.length() && code[i] != '\n') i++;
            continue;
        }
        if(i < code.length() - 1 && c == '/' && code[i+1] == '*') {
            inComment = true;
            i++;
            continue;
        }
        if(inComment) {
            if(i < code.length() - 1 && c == '*' && code[i+1] == '/') {
                inComment = false;
                i++;
            }
            continue;
        }

        // Check braces
        if(c == '{') {
            brackets.push(c);
            leftCount++;
        }
        else if(c == '}') {
            if(brackets.empty() || brackets.top() != '{') {
                return false;
            }
            brackets.pop();
            rightCount++;
        }
    }
    
    return brackets.empty() && leftCount == rightCount;
}

int main() {
    ifstream inFile("check.in");
    ofstream outFile("check.out");
    
    if(!inFile || !outFile) {
        return 1;
    }
    
    string code, line;
    while(getline(inFile, line)) {
        code += line + "\n";
    }
    
    bool result = checkParentheses(code);
    outFile << (result ? "True" : "False");
    
    inFile.close();
    outFile.close();
    return 0;
}
