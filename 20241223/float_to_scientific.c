#include <stdio.h>
#include <string.h>

void convertToScientific(char *num) {
    int len = strlen(num);
    int dotPos = -1;
    int firstNonZero = -1;
    int exp = 0;
    char result[200] = {0};
    
    // 找到小数点位置和第一个非零数字位置
    for(int i = 0; i < len; i++) {
        if(num[i] == '.') {
            dotPos = i;
        }
        if(firstNonZero == -1 && num[i] != '.' && num[i] != '0') {
            firstNonZero = i;
        }
    }
    
    if(firstNonZero == -1) {
        printf("0e0\n");
        return;
    }
    
    // 计算指数
    if(dotPos == -1) { // 整数情况
        exp = len - firstNonZero - 1;
    } else if(firstNonZero > dotPos) { // 小数情况
        exp = -(firstNonZero - dotPos);
    } else { // 整数部分有非零数字
        exp = dotPos - firstNonZero - 1;
    }
    
    // 构造结果
    int resPos = 0;
    // 添加第一个数字
    result[resPos++] = num[firstNonZero];
    
    // 如果后面还有数字，添加小数点
    if(firstNonZero < len - 1) {
        result[resPos++] = '.';
    }
    
    // 添加后续数字，跳过小数点
    for(int i = firstNonZero + 1; i < len; i++) {
        if(num[i] != '.') {
            result[resPos++] = num[i];
        }
    }
    
    // 移除末尾的0
    while(resPos > 1 && result[resPos-1] == '0') {
        resPos--;
    }
    if(result[resPos-1] == '.') {
        resPos--;
    }
    result[resPos] = '\0';
    
    printf("%se%d\n", result, exp);
}

int main() {
    char num[200];
    scanf("%s", num);
    convertToScientific(num);
    return 0;
}
