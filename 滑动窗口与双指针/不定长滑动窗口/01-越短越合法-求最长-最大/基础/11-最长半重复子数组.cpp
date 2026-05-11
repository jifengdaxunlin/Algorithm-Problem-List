#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <list>
#include <set>
#include <vector>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int longestSubarray(std::vector<int> &nums, int k)
    {
        if (nums.empty()){
            return 0;
        }
        else {
            int answer = 0, sub_len = 0, sub_start = 0;
            std::set<int> kind_over_k;
            std::unordered_map<int, std::list<int>> num_location;
            for (int i = 0; i < nums.size(); i++){
                int num = nums.at(i);
                num_location[num].push_back(i);
                if(num_location[num].size() > 1){
                    kind_over_k.insert(num);
                    while (kind_over_k.size() > k)
                    {
                        int num_w = nums.at(sub_start);
                        num_location[num_w].pop_front();
                        if(num_location[num_w].size() == 1){
                            kind_over_k.erase(num_w);
                        }
                        sub_len--;
                        sub_start++;
                    }
                }
                sub_len++;
                answer = sub_len > answer ? sub_len : answer;
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
    int array_len = pow(10, 5), k = 60; // 数组长度、重复元素个数
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 100;
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，子数组最多有 " << k << " 个重复元素元素，最长子数组长度为：" << so.longestSubarray(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给定一个长度为??n 的整数数组 nums 和一个整数?k。

半重复 子数组是指最多有 k 个元素重复（即出现超过一次）的连续子数组。

返回 nums 中最长 半重复 子数组的长度。

示例 1：

输入：nums = [1,2,3,1,2,3,4], k = 2

输出：6

解释：

最长的半重复子数组是 [2, 3, 1, 2, 3, 4]，其中有 2 个重复元素（2 和 3）。

示例 2：

输入：nums = [1,1,1,1,1], k = 4

输出：5

解释：

最长的半重复子数组是 [1, 1, 1, 1, 1]，其中只有 1 个重复元素（1）。

示例 3：

输入：nums = [1,1,1,1,1], k = 0

输出：1

解释：

最长的半重复子数组是 [1]，其中没有重复元素。

提示：

1 <= nums.length <= pow(10,5)
1 <= nums[i] <= pow(10,5)
0 <= k <= nums.length */