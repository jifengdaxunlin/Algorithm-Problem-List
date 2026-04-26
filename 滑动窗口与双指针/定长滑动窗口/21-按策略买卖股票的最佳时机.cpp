#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        if (prices.empty() || strategy.empty() || k % 2 == 1){
            return 0;
        }else{
            int max = 0, flag = 0, sum = 0,size = prices.size();
            for (int i = 0; i < size; i++){
                sum += prices[i] * strategy[i];
            }
            max = sum;
            for (int j = 0; j < size - k + 1; j++){
                flag = sum;
                for (int x = 0; x < (k / 2); x++){
                    flag -= prices[x + j] * strategy[x + j];
                    flag -= prices[j + k - x - 1] * strategy[j + k - x - 1];
                    flag += prices[j + k - x - 1];
                }
                if (flag > max){
                    max = flag;
                    //cout << max << endl;
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
    int array_len = 10, k = 4; // 数组长度、可修改个数（偶数）
    vector<int> prices(array_len), strategy(array_len);
    for (int i = 0; i < array_len; i++)
    {
        prices[i] = rand() % 10;
        strategy[i] = rand() % 3 - 1;
        cout << prices[i] << " " << strategy[i] << "\t";
    }
    cout << endl;

    cout << "长度为：" << array_len << " 的数组，最大的利润为：" << so.maxProfit(prices, strategy, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给你两个整数数组 prices 和 strategy，其中：

prices[i] 表示第 i 天某股票的价格。
strategy[i] 表示第 i 天的交易策略，其中：
-1 表示买入一单位股票。
0 表示持有股票。
1 表示卖出一单位股票。
同时给你一个 偶数 整数 k，你可以对 strategy 进行 最多一次 修改。一次修改包括：

选择 strategy 中恰好 k 个 连续 元素。
将前 k / 2 个元素设为 0（持有）。
将后 k / 2 个元素设为 1（卖出）。
利润 定义为所有天数中 strategy[i] * prices[i] 的 总和 。

返回你可以获得的 最大 可能利润。

注意： 没有预算或股票持有数量的限制，因此所有买入和卖出操作均可行，无需考虑过去的操作。

示例 1：

输入： prices = [4,2,8], strategy = [-1,0,1], k = 2

输出： 10

解释：

修改	策略	利润计算	利润
原始	[-1, 0, 1]	(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8	4
修改 [0, 1]	[0, 1, 1]	(0 × 4) + (1 × 2) + (1 × 8) = 0 + 2 + 8	10
修改 [1, 2]	[-1, 0, 1]	(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8	4
因此，最大可能利润是 10，通过修改子数组 [0, 1] 实现。

示例 2：

输入： prices = [5,4,3], strategy = [1,1,0], k = 2

输出： 9

解释：

修改	策略	利润计算	利润
原始	[1, 1, 0]	(1 × 5) + (1 × 4) + (0 × 3) = 5 + 4 + 0	9
修改 [0, 1]	[0, 1, 0]	(0 × 5) + (1 × 4) + (0 × 3) = 0 + 4 + 0	4
修改 [1, 2]	[1, 0, 1]	(1 × 5) + (0 × 4) + (1 × 3) = 5 + 0 + 3	8
因此，最大可能利润是 9，无需任何修改即可达成。
*/