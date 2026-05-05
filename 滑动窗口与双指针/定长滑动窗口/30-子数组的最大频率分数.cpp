#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxFrequencyScore(vector<int> &nums, int k)
    {
        if (nums.empty() || k == 0){
            return 0;
        }
        else{
            long long result = 0, sum = 0;
            unordered_map<int, int> frequency, record;
            for (int num : nums){
                frequency[num]++;
            }

            for (int i = 0; i < nums.size(); i++){
                record[nums.at(i)]++;
                if (i >= (k - 1)){
                    if (i > (k - 1)){
                        record[nums.at(i - k)]--;
                        if (record[nums.at(i - k)] == 0){
                            record.erase(nums.at(i - k));
                        }
                    }

                    sum = 0;
                    for (auto data : record)
                    {
                        sum += (long long)pow(data.first, frequency.at(data.first));
                    }
                    if (sum % (int)pow(10, 9) > result)
                    {
                        result = sum % (int)pow(10, 9);
                    }
                }
                
            }
            return (int)result;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 100, k = 10; // 数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 101;
        cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，长度为 " << k << " 的子字符串的最大频分数为：" << so.maxFrequencyScore(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 题目描述
给定一个整数数组 nums 和一个 正 整数 k 。

数组的 频率得分 是数组中 不同 值的 幂次 之和，并将和对 109 + 7 取模。

例如，数组 [5,4,5,7,4,4] 的频率得分为 (pow(4,3) + pow(5,2) + pow(7,1)) modulo (pow(10,9) + 7) = 96 。

返回 nums 中长度为 k 的 子数组 的 最大 频率得分。你需要返回取模后的最大值，而不是实际值。

子数组 是一个数组的连续部分。

 

示例 1 ：

输入：nums = [1,1,1,2,1,2], k = 3
输出：5
解释：子数组 [2,1,2] 的频率分数等于 5。可以证明这是我们可以获得的最大频率分数。

示例 2 ：

输入：nums = [1,1,1,1,1,1], k = 4
输出：1
解释：所有长度为 4 的子数组的频率得分都等于 1。 */