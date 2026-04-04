#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
给你一个整数数组 nums 和两个正整数 m 和 k 。

请你返回 nums 中长度为 k 的 几乎唯一 子数组的 最大和 ，如果不存在几乎唯一子数组，请你返回 0 。

如果 nums 的一个子数组有至少 m 个互不相同的元素，我们称它是 几乎唯一 子数组。

子数组指的是一个数组中一段连续 非空 的元素序列。
*/
long long maxSum(int *nums, int numsSize, int m, int k)
{
    int count = 0;
    int *freq = calloc(100005, sizeof(int));
    if (nums == NULL || numsSize <= 0 || m <= 0 || k <= 0)
    {
        free(freq);
        return 0;
    }
    else{
        long long temp = 0, num_sum = 0;
        for (int i = 0; i < numsSize;i++){
            temp += nums[i];
            if(freq[nums[i]]==0){
                count++;
            }
            freq[nums[i]]++;

            
            if(i>=(k-1)){
                if (i >= k)
                {
                    temp -= nums[i - k];
                    freq[nums[i - k]]--;
                    if (freq[nums[i - k]] == 0)
                    {
                        count--;
                    }
                }
                if(count>=m){
                    if(temp>num_sum){
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

    int array_len = 50, k = 10, m = 6; // 字符串数组长度、窗口长度、不同元素数
    int *num_array = calloc(array_len, sizeof(int));
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        printf("%d\t", num_array[i]);
    }
    printf("\n");
    printf("子字符串为 %d 长，不同元素为 %d 的子数组最大值为 %lld", k, m, maxSum(num_array, array_len, m, k));

    free(num_array);
    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
示例 1：

输入：nums = [2,6,7,3,1,7], m = 3, k = 4
输出：18
解释：总共有 3 个长度为 k = 4 的几乎唯一子数组。分别为 [2, 6, 7, 3] ，[6, 7, 3, 1] 和 [7, 3, 1, 7] 。这些子数组中，和最大的是 [2, 6, 7, 3] ，和为 18 。
示例 2：

输入：nums = [5,9,9,2,4,5,4], m = 1, k = 3
输出：23
解释：总共有 5 个长度为 k = 3 的几乎唯一子数组。分别为 [5, 9, 9] ，[9, 9, 2] ，[9, 2, 4] ，[2, 4, 5] 和 [4, 5, 4] 。这些子数组中，和最大的是 [5, 9, 9] ，和为 23 。
示例 3：

输入：nums = [1,2,1,2,1,2,1], m = 3, k = 3
输出：0
解释：输入数组中不存在长度为 k = 3 的子数组含有至少  m = 3 个互不相同元素的子数组。所以不存在几乎唯一子数组，最大和为 0 。
*/