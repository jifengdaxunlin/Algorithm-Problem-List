#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int search_aeiou_num(char string[],int win_len){
    int len = strlen(string);
    int flag = 0;
    
    // 计算窗口元音数
    int temp = 0;
    for (int k = 0; k < win_len; k++)
    {
        if (string[k] == 'a' || string[k] == 'e' || string[k] == 'i' || string[k] == 'o' || string[k] == 'u')
        {
            temp++;
        }
    }
    printf("%d\n", temp);

    for (int i = win_len; i <= len; i++){
        //记录最大元音数，最大元音数为窗口数时直接返回最大窗口数
        if (flag < temp)
        {
            flag = temp;
            if (flag == win_len)
            {
                return win_len;
            }
        }

        //窗口后移 1 个字符
        if (string[i - win_len] == 'a' || string[i - win_len] == 'e' || string[i - win_len] == 'i' || string[i - win_len] == 'o' || string[i - win_len] == 'u')
        {
            temp--;
        }
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
        {
            temp++;
        }
        printf("%d\n", temp);

        // 窗口内容不足，则返回最大元音数
        if (string[i]=='\0')
        {
            return flag;
        }
    }
}

int main(int argc,char const * argv[]){
    char arry[30];
    printf("输入一串字符：");
    scanf("%s", arry);

    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    printf("%s\n", arry);
    printf("最多元音数：%d\n", search_aeiou_num(arry, 5));

    clock_t end = clock();
    printf("算法运行了 %d ms", end - start);
    return 0;
}