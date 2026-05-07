#include <iostream>
#include <unordered_map>
#include <ctime>         // time()
#include <set>     //
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        if (nums.empty() || k == 0 || k <= x){
            return {};
        }
        else{
            multiset<int> num_sort;
            unordered_map<int, int> record;
            vector<int> result(nums.size() - k + 1, 0);
            for (int i = 0; i < nums.size(); i++){
                num_sort.insert(nums[i]);
                record[nums[i]]++;

                if (i >= (k - 1)){
                    if (i > (k - 1)){
                        record[nums[i - k]]--;
                        if (record[nums[i - k]] == 0)
                        {
                            record.erase(nums[i - k]);
                            num_sort.erase(nums[i - k]);
                        }
                    }
                    
                    if (nums.at(i - (k - 1) + (x - 1)) < 0)
                    {
                        auto num_iterotr = num_sort.begin();
                        advance(num_iterotr, x - 1);
                        result.at(i - (k - 1)) = *num_iterotr;
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
    //clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = (int)pow(10, 5), k = 1000, x = 555; // 数组长度、窗口长度
    int array_len = 10, k = 4, x = 2;
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 2 == 0 ? rand() % 51 : ~rand() % 51 + 1;
        cout << num_array[i] << "\t";
    }
    cout << endl;

    clock_t start = clock();
    vector<int> result = so.getSubarrayBeauty(num_array, k, x);
    /* for (int num : so.getSubarrayBeauty(num_array, k, x))
    {
        cout << num << "\t";
    }
    cout << endl; */

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个长度为 n 的整数数组 nums ，请你求出每个长度为 k 的子数组的 美丽值 。

一个子数组的 美丽值 定义为：如果子数组中第 x 小整数 是 负数 ，那么美丽值为第 x 小的数，否则美丽值为 0 。

请你返回一个包含 n - k + 1 个整数的数组，依次 表示数组中从第一个下标开始，每个长度为 k 的子数组的 美丽值 。

子数组指的是数组中一段连续 非空 的元素序列。

 

示例 1：

输入：nums = [1,-1,-3,-2,3], k = 3, x = 2
输出：[-1,-2,-2]
解释：总共有 3 个 k = 3 的子数组。
第一个子数组是 [1, -1, -3] ，第二小的数是负数 -1 。
第二个子数组是 [-1, -3, -2] ，第二小的数是负数 -2 。
第三个子数组是 [-3, -2, 3] ，第二小的数是负数 -2 。
示例 2：

输入：nums = [-1,-2,-3,-4,-5], k = 2, x = 2
输出：[-1,-2,-3,-4]
解释：总共有 4 个 k = 2 的子数组。
[-1, -2] 中第二小的数是负数 -1 。
[-2, -3] 中第二小的数是负数 -2 。
[-3, -4] 中第二小的数是负数 -3 。
[-4, -5] 中第二小的数是负数 -4 。
示例 3：

输入：nums = [-3,1,2,-3,0,-3], k = 2, x = 1
输出：[-3,0,-3,-3,-3]
解释：总共有 5 个 k = 2 的子数组。
[-3, 1] 中最小的数是负数 -3 。
[1, 2] 中最小的数不是负数，所以美丽值为 0 。
[2, -3] 中最小的数是负数 -3 。
[-3, 0] 中最小的数是负数 -3 。
[0, -3] 中最小的数是负数 -3 。
 

提示：

n == nums.length 
1 <= n <= 105
1 <= k <= n
1 <= x <= k 
-50 <= nums[i] <= 50  */