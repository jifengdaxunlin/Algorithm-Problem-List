#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numOfSubarrays(int *arr, int arrSize, int k, int threshold)
{
    int sum = 0, count = 0, threshold_new = threshold * k;
    if (arr == NULL || arrSize == 0 || k == 0)
    {
        return 0;
    }
    if (arrSize < k)
    {
        printf("字符串总数小于子字符串...");
        for (int temp = 0; temp < arrSize; temp++)
        {
            sum += arr[temp];
        }
        if (sum > threshold_new)
        {
            count++;
        }
        return count;
    }
    else
    {
        for (int temp = 0; temp < k; temp++)
        {
            sum += arr[temp];
        }
        if (sum > threshold_new)
        {
            count++;
            for (int i = 0; i < k; i++)
            {
                printf("%d\t", arr[i]);
            }
            printf("平均数：%f\n", (float)sum / k);
        }
        for (int shen = 0; shen < (arrSize - k); shen++)
        {
            sum -= arr[shen];
            sum += arr[shen + k];
            if (sum > threshold_new)
            {
                count++;
                for (int i = shen + 1; i <= shen + k; i++)
                {
                    printf("%d\t", arr[i]);
                }
                printf("平均数：%f\n", (float)sum / k);
            }
        }
        return count;
    }
    return 0;
}

int main()
{
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    int arrSize = 10, k = 4, threshold = 77;
    srand(time(NULL));
    int *num = calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        num[i] = rand() % 100;
        printf("%d\t", num[i]);
    }
    printf("\n");
    printf("\n长度为 %d 子数组均值大于 %d 的个数：%d\n", k, threshold, numOfSubarrays(num, arrSize, k, threshold));
    free(num);

    clock_t end = clock();
    printf("算法运行了 %d ms", end - start);
    return 0;
}