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
    int longestOnes(std::vector<int> &nums, int k)
    {
        if (nums.empty()){
            return 0;
        }
        else {
            int answer = 0, subarray_len = 0, subarray_start = 0;
            std::list<int> zero_location;
            for (int i = 0; i < nums.size(); i++){
                int num = nums.at(i);
                if (!num){
                    zero_location.push_back(i);
                    if (zero_location.size() > k){
                        int location = zero_location.front();
                        subarray_len -= (location - subarray_start + 1);
                        subarray_start = location + 1;
                        zero_location.pop_front();
                    }
                }
                subarray_len++;
                answer = subarray_len > answer ? subarray_len : answer;
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
    int array_len = pow(10, 5), k = 100; // 数组长度、改变元素长度
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 2;
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的由 “0”、“1” 组成的数组，改变 " << k << " 个元素，全为 “1” 的最长子数组长度为：" << so.longestOnes(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给定一个二进制数组 nums 和一个整数 k，假设最多可以翻转 k 个 0 ，则返回执行操作后 数组中连续 1 的最大个数 。

 

示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= nums.length <= pow(10,5)
nums[i] 不是 0 就是 1
0 <= k <= nums.length */