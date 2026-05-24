#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// 生成所有可能的旋转字符串
std::vector<std::string> generateRotations(const std::string& s) {
    std::vector<std::string> rotations;
    int n = s.length();
    std::string temp = s;
    
    for(int i = 0; i < n; i++) {
        rotations.push_back(temp);
        temp = temp.back() + temp.substr(0, n-1);
    }
    
    std::sort(rotations.begin(), rotations.end());
    return rotations;
}

// 构建最终字符串
std::string buildFinalString(const std::vector<std::string>& rotations) {
    std::string result;
    for(const auto& str : rotations) {
        result += str.back();
    }
    return result;
}

// 查找原始字符串的位置
int findOriginalPosition(const std::vector<std::string>& rotations, const std::string& original) {
    char firstChar = original[0];
    
    for(int i = 0; i < rotations.size(); i++) {
        if(rotations[i][0] == firstChar) {
            std::string temp = rotations[i];
            int len = temp.length();
            for(int j = 0; j < len; j++) {
                if(temp == original) {
                    return i+1;
                }
                temp = temp.substr(1) + temp[0];
            }
        }
    }
    return 1;
}

int main() {
    std::ifstream fin("filezip.in");
    std::ofstream fout("filezip.out");
    
    int n;
    std::string s;
    
    fin >> n >> s;
    
    if(n >= 1 && n <= 10000 && s.length() == n) {
        std::vector<std::string> rotations = generateRotations(s);
        std::string result = buildFinalString(rotations);
        int position = findOriginalPosition(rotations, s);
        
        fout << result << '\n' << position;
    }
    
    fin.close();
    fout.close();
    return 0;
}
