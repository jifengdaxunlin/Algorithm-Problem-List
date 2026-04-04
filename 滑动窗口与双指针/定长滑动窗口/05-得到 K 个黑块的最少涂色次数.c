#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int minimumRecolors(char *blocks, int k)
{
    if(blocks==NULL){
        return -1;
    }
    else if(k <= 0){
        return 0;
    }
    else{
        int temp = 0, B_max = 0, len = strlen(blocks);
        for (int i = 0; i < k; i++)
        {
            if(blocks[i]=='B'){
                temp++;
            }
        }

        for (int x = k; x <= len; x++)
        {
            if(temp>B_max){
                B_max = temp;
            }
            if (blocks[x-k] == 'B')
            {
                temp--;
            }
            if (blocks[x] == 'B')
            {
                temp++;
            }
        }
        return (k - B_max);
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    int array_len = 50, k = 10; // 字符串数组长度、窗口长度
    char *blocks = calloc(array_len+1, sizeof(char));
    for (int i = 0; i < array_len;i++){
        if(rand()%2){
            blocks[i] = 'B';
        }
        else{
            blocks[i] = 'W';
        }
    }
    blocks[array_len] = '\0';
    printf("初始字符串数组为 %s\n",blocks);
    printf(" %d 个黑块的最少涂色次数 %d \n", k, minimumRecolors(blocks, k));

    free(blocks);
    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
示例 1：
输入：blocks = "WBBWWBBWBW", k = 7
输出：3
解释：
一种得到 7 个连续黑色块的方法是把第 0 ，3 和 4 个块涂成黑色。
得到 blocks = "BBBBBBBWBW" 。
可以证明无法用少于 3 次操作得到 7 个连续的黑块。
所以我们返回 3 。
*/
