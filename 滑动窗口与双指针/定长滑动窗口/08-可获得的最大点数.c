#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int maxScore(int *cardPoints, int cardPointsSize, int k)
{
    int temp = 0, sum = 0;
    if(cardPoints==NULL||cardPointsSize==0||k==0){
        return 0;
    }
    else if (cardPointsSize > k)
    {
        for (int i = 0; i < k * 2;i++){
            if(i>(k-1)){
                    sum -= cardPoints[2 * k - i - 1];
                    sum += cardPoints[cardPointsSize - (i - k + 1)];
                    if (temp < sum)
                    {
                        temp = sum;
                    }
            }
            else{
                sum += cardPoints[i];
                if (i == (k - 1))
                {
                    temp = sum;
                }
            }
        }
        return temp;
    }
    else if(cardPointsSize==k){
        for (int i = 0; i < k;k++){
            sum += cardPoints[i];
        }
        return sum;
    }
    else{
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    int array_len = 10, k = 3; // 字符串数组长度、窗口长度
    int *num_array = calloc(array_len, sizeof(int));
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        printf("%d\t", num_array[i]);
    }
    printf("\n");
    printf("子字符串为 %d 长，从头部或尾部取数，最大点数为：%d", k, maxScore(num_array, array_len, k));

    free(num_array);
    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}