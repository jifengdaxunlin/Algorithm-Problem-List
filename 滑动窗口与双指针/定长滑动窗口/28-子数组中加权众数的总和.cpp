#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    long long modeWeight(vector<int> &nums, int k)
    {
        if(nums.empty() || k == 0){
            return 0;
        }
        else{
            pair<int, int> temp = {0, 0};
            long long result = 0;
            unordered_map<int, int> record;
            for (int i = 0; i < nums.size(); i++){
                record[nums.at(i)]++;
                if (i >= (k - 1)){
                    if (i > (k - 1)){
                        record[nums.at(i - k)]--;
                        if (record[nums.at(i - k)] == 0){
                            record.erase(nums.at(i - k));
                        }
                    }

                    temp = {0, 0};
                    for (int j = i - k + 1; j < (i + 1); j++)
                    {
                        if (temp.second < record[nums.at(j)]){
                            temp = {nums.at(j), record[nums.at(j)]};
                        }
                        else if (temp.second == record[nums.at(j)] && temp.first > nums.at(j)){
                            temp.first = nums.at(j);
                        }
                    }
                    result += temp.first * temp.second;
                }
            }
            return result;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, k = 3; // 数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，长度为 " << k << " 的子数组加权众数总和为：" << so.modeWeight(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
题目描述
给定一个整数数组 nums 和一个整数 k。

对于每个长度为 k 的 子数组：

众数 mode 是指 出现频率最高 的元素。如果有多个众数，取其中 最小 的那个元素。
权重 定义为 mode * frequency(mode)。
返回长度为 k 的所有 子数组 的权重之 和。

注意：

子数组 是数组中连续的 非空 元素序列。
元素 x 的 频率 是它在数组中出现的次数。


示例 1：

输入：nums = [1,2,2,3], k = 3

输出：8

解释：

长度为 k = 3 的子数组是：

子数组	频率	众数	众数频率	权重
[1, 2, 2]	1: 1, 2: 2	2	2	2 × 2 = 4
[2, 2, 3]	2: 2, 3: 1	2	2	2 × 2 = 4
因此，权重的和是 4 + 4 = 8。

示例 2：

输入：nums = [1,2,1,2], k = 2

输出：3

解释：

长度为 k = 2 的子数组是：

子数组	频率	众数	众数频率	权重
[1, 2]	1: 1, 2: 1	1	1	1 × 1 = 1
[2, 1]	2: 1, 1: 1	1	1	1 × 1 = 1
[1, 2]	1: 1, 2: 1	1	1	1 × 1 = 1
因此，权重的和是 1 + 1 + 1 = 3。

示例 3：

输入：nums = [4,3,4,3], k = 3

输出：14

解释：

长度为 k = 3 的子数组是：

子数组	频率	众数	众数频率	权重
[4, 3, 4]	4: 2, 3: 1	4	2	2 × 4 = 8
[3, 4, 3]	3: 2, 4: 1	3	2	2 × 3 = 6
因此，权重的和是 8 + 6 = 14。
*/