#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：

子数组的长度是 k，且
子数组中的所有元素 各不相同 。
返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。

子数组 是数组中一段连续非空的元素序列。
*/
long long maximumSubarraySum(int *nums, int numsSize, int k)
{
    int count = 0;
    int *freq = calloc(pow(10,5), sizeof(int));
    if (nums == NULL || numsSize <= 0 || k <= 0)
    {
        free(freq);
        return 0;
    }
    else
    {
        long long temp = 0, num_sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            temp += nums[i];
            if (freq[nums[i]] == 0)
            {
                count++;
            }
            freq[nums[i]]++;

            if (i >= (k - 1))
            {
                if (i >= k)
                {
                    temp -= nums[i - k];
                    freq[nums[i - k]]--;
                    if (freq[nums[i - k]] == 0)
                    {
                        count--;
                    }
                }
                if (count == k)
                {
                    if (temp > num_sum)
                    {
                        num_sum = temp;
                    }
                }
            }
        }
        free(freq);
        return num_sum;
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    int array_len = 5000, k = 10; // 字符串数组长度、窗口长度
    int *num_array = calloc(array_len, sizeof(int));
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        printf("%d\t", num_array[i]);
    }
    printf("\n");
    printf("子字符串为 %d 长，元素都不同的子数组最大值为 %lld", k, maximumSubarraySum(num_array, array_len, k));

    free(num_array);
    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
示例 1：

输入：nums = [1,5,4,2,9,9,9], k = 3
输出：15
解释：nums 中长度为 3 的子数组是：
- [1,5,4] 满足全部条件，和为 10 。
- [5,4,2] 满足全部条件，和为 11 。
- [4,2,9] 满足全部条件，和为 15 。
- [2,9,9] 不满足全部条件，因为元素 9 出现重复。
- [9,9,9] 不满足全部条件，因为元素 9 出现重复。
因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
示例 2：

输入：nums = [4,4,4], k = 3
输出：0
解释：nums 中长度为 3 的子数组是：
- [4,4,4] 不满足全部条件，因为元素 4 出现重复。
因为不存在满足全部条件的子数组，所以返回 0 。
*/