#include <string>
#include <cstdlib>
#include <iostream>

std::string removeTrailingZeros(std::string numStr) {
    if (numStr.find('.') != std::string::npos) {
        size_t pos = numStr.find_last_not_of('0');
        if (pos != std::string::npos) {
            if (numStr[pos] == '.') pos--;
            numStr = numStr.substr(0, pos + 1);
        }
    }
    return numStr;
}

std::string insertDecimalPoint(std::string numStr, int position) {
    if (position < static_cast<int>(numStr.length())) {
        numStr.insert(position, ".");
    }
    return numStr;
}

std::string scientificToDecimal(std::string scientificStr) {
    // Remove spaces
    scientificStr.erase(0, scientificStr.find_first_not_of(" "));
    scientificStr.erase(scientificStr.find_last_not_of(" ") + 1);
    
    // Check if scientific notation
    size_t ePos = scientificStr.find_first_of("eE");
    if (ePos == std::string::npos) {
        return scientificStr;
    }
    
    // Handle sign
    bool isNegative = false;
    if (scientificStr[0] == '-') {
        isNegative = true;
        scientificStr = scientificStr.substr(1);
        ePos--;
    } else if (scientificStr[0] == '+') {
        scientificStr = scientificStr.substr(1);
        ePos--;
    }
    
    // Split into base and exponent
    std::string baseStr = scientificStr.substr(0, ePos);
    std::string expStr = scientificStr.substr(ePos + 1);
    
    // Remove decimal point from base
    size_t decimalPos = baseStr.find('.');
    if (decimalPos != std::string::npos) {
        baseStr.erase(decimalPos, 1);
    } else {
        decimalPos = baseStr.length();
    }
    
    // Convert exponent to integer
    int exponent = std::stoi(expStr);
    
    // Calculate new decimal position
    int newPos = static_cast<int>(decimalPos) + exponent;
    
    // Pad with zeros as needed
    while (static_cast<int>(baseStr.length()) < newPos) {
        baseStr += "0";
    }
    while (newPos <= 0) {
        baseStr = "0" + baseStr;
        newPos++;
    }
    
    // Format result
    std::string result = baseStr;
    result = insertDecimalPoint(result, newPos);
    result = removeTrailingZeros(result);
    
    // Add negative sign if needed
    if (isNegative) {
        result = "-" + result;
    }
    
    return result;
}
int main() {
    // 测试用例
    std::string test;
    std::cin>>test;
    std::cout  << scientificToDecimal(test) << std::endl;
    
    return 0;
}