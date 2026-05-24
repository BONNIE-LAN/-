#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    
    // 声明第一个数组
    int array1[100];  // 假设最大大小为100
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array1[i]);
    }
    
    scanf("%d", &m);
    
    // 声明第二个数组
    int array2[100];  // 假设最大大小为100
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &array2[i]);
    }
    
    int found = 0;  // 在C语言中用0表示false，1表示true
    int printed[100] = {0};  // 用于记录已经输出过的数字
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(array1[i] == array2[j])
            {
                // 检查这个数字是否已经输出过
                int already_printed = 0;
                for(int k = 0; k < i; k++)
                {
                    if(array1[k] == array1[i] && printed[k])
                    {
                        already_printed = 1;
                        break;
                    }
                }
                
                if(!already_printed)
                {
                    printf("%d ", array1[i]);
                    printed[i] = 1;
                    found = 1;
                }
                break;
            }
        }
    }
    
    if(!found) {
        printf("No Answer");
    }
    
    return 0;
}
