#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        if(customers.empty()||grumpy.empty()){
            return 0;
        }
        else{
            int lenght = grumpy.size(), sum = 0, max = 0;
            for (int k = 0; k < lenght;k++){
                sum += customers[k] * (!grumpy[k]);
            }
            max = sum;
            
            for (int i = 0; i < lenght; i++)
            {
                sum += customers[lenght - i - 1] * (grumpy[lenght - i - 1]);
                if (i > (minutes - 1)){
                    sum -= customers[lenght - i - 1 + minutes] * (grumpy[lenght - i - 1 + minutes]);
                }
                if (sum > max)
                {
                    max = sum;
                }
            }
            return max;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, k = 3; // 分钟数=老板心情、持续时间
    vector<int> customers(array_len), grumpy(array_len);
    for (int i = 0; i < array_len; i++)
    {
        customers[i] = rand() % 5;
        grumpy[i] = rand() % 2;
        cout << customers[i] <<"\t";
    }
    cout << endl;
    for (int i = 0; i < array_len; i++)
    {
        cout << grumpy[i] << "\t";
    }
    cout << endl
         << "开店 " << array_len << " 分钟，连续 " << k << " 分钟不生气，最多有 " << so.maxSatisfied(customers, grumpy, k) << " 个顾客满意" << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。

在某些分钟内，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。

当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。

请你返回 这一天营业下来，最多有多少客户能够感到满意 。


示例 1：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
输出：16
解释：书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
示例 2：

输入：customers = [1], grumpy = [0], minutes = 1
输出：1
*/