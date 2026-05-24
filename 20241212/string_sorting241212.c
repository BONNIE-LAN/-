#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

// 比较函数，用于qsort
int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    FILE *fin, *fout;
    char *words[MAX_WORDS];
    char temp[MAX_WORD_LEN];
    int word_count = 0;

    // 打开输入文件
    fin = fopen("sort.in", "r");
    if (fin == NULL) {
        printf("无法打开输入文件\n");
        return 1;
    }

    // 读取单词
    while (fscanf(fin, "%s", temp) == 1 && word_count < MAX_WORDS) {
        words[word_count] = (char*)malloc(strlen(temp) + 1);
        if (words[word_count] == NULL) {
            printf("内存分配失败\n");
            fclose(fin);
            return 1;
        }
        strcpy(words[word_count], temp);
        word_count++;
    }
    fclose(fin);

    // 排序单词
    qsort(words, word_count, sizeof(char*), compare);

    // 打开输出文件
    fout = fopen("sort.out", "w");
    if (fout == NULL) {
        printf("无法打开输出文件\n");
        return 1;
    }

    // 写入结果（去除重复）
    if (word_count > 0) {
        fprintf(fout, "%s", words[0]);
        for (int i = 1; i < word_count; i++) {
            if (strcmp(words[i], words[i-1]) != 0) {
                fprintf(fout, " %s", words[i]);
            }
        }
    }

    // 关闭文件并释放内存
    fclose(fout);
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }

    return 0;
}
