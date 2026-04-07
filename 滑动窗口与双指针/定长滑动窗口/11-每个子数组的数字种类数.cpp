#include <iostream>
#include <ctime>   // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> distinctNumbers(vector<int> &nums, int k)
    {
        if(nums.empty()||k==0){
            return {};
        }
        else{
            vector<int> result(nums.size() - k + 1);
            int len = nums.size(), ans = 0;
            unordered_map<int, int> temp;
            for (int i = 0; i < len;i++){
                ++temp[nums[i]];
                if (i >= (k - 1))
                {
                    if (i == (k - 1))
                    {
                        result[ans] = temp.size();
                        ans++;
                    }
                    else{
                        --temp[nums[i - k]];
                        if (temp[nums[i - k]] == 0)
                        {
                            temp.erase(nums[i - k]);
                        }
                        result[ans] = temp.size();
                        ans++;
                    }
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
    int array_len = 15, k = 5; // 字符串数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        cout << num_array[i] << "\t";
    }
    cout << "" << endl
         << "长度为 " << k << " 的子数组数字种类数为：";
    vector<int> result = so.distinctNumbers(num_array,k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    cout << "" << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
题目描述
给你一个长度为 n 的整数数组 nums 与一个整数 k。你的任务是找到 nums 所有 长度为 k 的子数组中 不同 元素的数量。

返回一个数组 ans，其中 ans[i] 是对于每个索引 0 <= i < n - k，nums[i..(i + k - 1)] 中不同元素的数量。

示例 1:

输入: nums = [1,2,3,2,2,1,3], k = 3
输出: [3,2,2,2,3]
解释：每个子数组的数字种类计算方法如下：
- nums[0..2] = [1,2,3] 所以 ans[0] = 3
- nums[1..3] = [2,3,2] 所以 ans[1] = 2
- nums[2..4] = [3,2,2] 所以 ans[2] = 2
- nums[3..5] = [2,2,1] 所以 ans[3] = 2
- nums[4..6] = [2,1,3] 所以 ans[4] = 3
示例 2:

输入: nums = [1,1,1,1,2,3,4], k = 4
输出: [1,2,3,4]
解释: 每个子数组的数字种类计算方法如下：
- nums[0..3] = [1,1,1,1] 所以 ans[0] = 1
- nums[1..4] = [1,1,1,2] 所以 ans[1] = 2
- nums[2..5] = [1,1,2,3] 所以 ans[2] = 3
- nums[3..6] = [1,2,3,4] 所以 ans[3] = 4
*/