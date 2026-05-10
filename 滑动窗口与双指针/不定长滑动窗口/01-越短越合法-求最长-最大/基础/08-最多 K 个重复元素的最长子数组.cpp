#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <list>
#include <vector>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int maxSubarrayLength(std::vector<int> &nums, int k)
    {
        if (nums.empty() || k == 0){
            return 0;
        }
        else {
            int answer = 0, subarry_len = 0, subarry_start = 0;
            std::unordered_map<int, std::list<int>> num_location;
            for (int i = 0; i < nums.size(); i++){
                int num = nums.at(i);
                num_location[num].push_back(i);
                if (num_location[num].size() > k){
                    int location = num_location[num].front();
                    while (subarry_start <= location){
                        num_location[nums.at(subarry_start)].pop_front();
                        subarry_start++;
                        subarry_len--;
                    }
                }
                subarry_len++;
                answer = subarry_len > answer ? subarry_len : answer;
            }
            return answer;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = pow(10, 5), k = 6; // 数组长度、窗口长度
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % (int)pow(10, 9);
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，每个元素的频率都小于等于 " << k << " 的最长子数组长度为：" << so.maxSubarrayLength(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个整数数组 nums 和一个整数 k 。

一个元素 x 在数组中的 频率 指的是它在数组中的出现次数。

如果一个数组中所有元素的频率都 小于等于 k ，那么我们称这个数组是 好 数组。

请你返回 nums 中 最长好 子数组的长度。

子数组 指的是一个数组中一段连续非空的元素序列。

 

示例 1：

输入：nums = [1,2,3,1,2,3,1,2], k = 2
输出：6
解释：最长好子数组是 [1,2,3,1,2,3] ，值 1 ，2 和 3 在子数组中的频率都没有超过 k = 2 。[2,3,1,2,3,1] 和 [3,1,2,3,1,2] 也是好子数组。
最长好子数组的长度为 6 。
示例 2：

输入：nums = [1,2,1,2,1,2,1,2], k = 1
输出：2
解释：最长好子数组是 [1,2] ，值 1 和 2 在子数组中的频率都没有超过 k = 1 。[2,1] 也是好子数组。
最长好子数组的长度为 2 。
示例 3：

输入：nums = [5,5,5,5,5,5,5], k = 4
输出：4
解释：最长好子数组是 [5,5,5,5] ，值 5 在子数组中的频率没有超过 k = 4 。
最长好子数组的长度为 4 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= nums.length */