#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int maximumBeauty(std::vector<int> &nums, int k)
    {
        if (nums.empty()){
            return 0;
        }
        else {
            int answer = 0, sum_flag = 0;
            std::set<int> num_kind;
            std::queue<std::set<int>::iterator> num_in_k;
            std::unordered_map<int, int> num_frequency;
            for (int i = 0; i < nums.size(); i++){
                int num = nums.at(i);
                num_kind.insert(num);
                num_frequency[num]++;
            }

            int temp = 0;
            std::set<int>::iterator j;
            for (j = num_kind.begin(); j != num_kind.end(); j++){
                static std::set<int>::iterator subnum_array = j;
                while ((*j + k) > *subnum_array && subnum_array != num_kind.end())
                {
                    num_in_k.push(subnum_array);
                    sum_flag += num_frequency[*subnum_array];
                    subnum_array++;
                }
                while ((*j - k) > *num_in_k.front()){
                    sum_flag -= num_frequency[*num_in_k.front()];
                    num_in_k.pop();
                }
                int temp = (sum_flag - num_frequency[*j]) > k ? k : (sum_flag - num_frequency[*j]);
                answer = (temp + num_frequency[*j]) > answer ? (temp + num_frequency[*j]) : answer;
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
    int array_len = pow(10, 5), k = 3; // 数组长度、可改值
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % (int)pow(10, 3);
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << "的数组，最大美丽值为：" << so.maximumBeauty(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个下标从 0 开始的整数数组 nums 和一个 非负 整数 k 。

在一步操作中，你可以执行下述指令：

在范围 [0, nums.length - 1] 中选择一个 此前没有选过 的下标 i 。
将 nums[i] 替换为范围 [nums[i] - k, nums[i] + k] 内的任一整数。
数组的 美丽值 定义为数组中由相等元素组成的最长子序列的长度。

对数组 nums 执行上述操作任意次后，返回数组可能取得的 最大 美丽值。

注意：你 只 能对每个下标执行 一次 此操作。

数组的 子序列 定义是：经由原数组删除一些元素（也可能不删除）得到的一个新数组，且在此过程中剩余元素的顺序不发生改变。

 

示例 1：

输入：nums = [4,6,1,2], k = 2
输出：3
解释：在这个示例中，我们执行下述操作：
- 选择下标 1 ，将其替换为 4（从范围 [4,8] 中选出），此时 nums = [4,4,1,2] 。
- 选择下标 3 ，将其替换为 4（从范围 [0,4] 中选出），此时 nums = [4,4,1,4] 。
执行上述操作后，数组的美丽值是 3（子序列由下标 0 、1 、3 对应的元素组成）。
可以证明 3 是我们可以得到的由相等元素组成的最长子序列长度。
示例 2：

输入：nums = [1,1,1,1], k = 10
输出：4
解释：在这个示例中，我们无需执行任何操作。
数组 nums 的美丽值是 4（整个数组）。
 

提示：

1 <= nums.length <= pow(10,5)
0 <= nums[i], k <= pow(10,5) */