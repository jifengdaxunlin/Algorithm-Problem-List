#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*半径为 k 的子数组平均值 是指：nums 中一个以下标 i 为 中心 且 半径 为 k 的子数组中所有元素的平均值，即下标在 i - k 和 i + k 范围（含 i - k 和 i + k）内所有元素的平均值。如果在下标 i 前或后不足 k 个元素，那么 半径为 k 的子数组平均值 是 -1 。

构建并返回一个长度为 n 的数组 avgs ，其中 avgs[i] 是以下标 i 为中心的子数组的 半径为 k 的子数组平均值 。

x 个元素的 平均值 是 x 个元素相加之和除以 x ，此时使用截断式 整数除法 ，即需要去掉结果的小数部分。*/

/*
  Note: The returned array must be malloced, assume caller calls free().
 */
int *getAverages(int *nums, int numsSize, int k, int *returnSize)
{
    if(nums==NULL||numsSize==0){
        return NULL;
    }
    else{
        int *nums_average = (int *)malloc(sizeof(int) * numsSize);
        int sum = 0;
        for (int x = 0; x < (2 * k + 1); x++)
        {
            sum += nums[x];
        }
        for (int i = 0; i < numsSize;i++){
            if ((i - k) < 0 || (i + k >= numsSize)){
                nums_average[i] = -1;
            }
            else{
                nums_average[i] = sum / (2 * k + 1);
                sum -= nums[i - k];
                sum += nums[i + k + 1];
            }
        }
        return nums_average;
    }
}

int main()
{
    clock_t start = clock();//表示当前cpu记录下的已经过了的毫秒数
    //数组、半径 初始化
    int arrSize = 10, k = 0;
    srand(time(NULL));
    int *num = calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        num[i] = rand() % 100;
        printf("%d\t", num[i]);
    }

    printf("\n");
    printf("\n半径为 %d 子数组均值平均值数组：", k);
    int *new_num_average = getAverages(num,arrSize,k,new_num_average);
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d\t", new_num_average[i]);
    }
    free(num);
    free(new_num_average);

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}