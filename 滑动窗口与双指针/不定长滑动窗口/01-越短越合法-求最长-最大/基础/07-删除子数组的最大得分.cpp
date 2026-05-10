#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
#include <set>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int maximumUniqueSubarray(std::vector<int> &nums)
    {
        if (nums.empty()){
            return 0;
        }
        else{
            int answer = 0, subarray_sum = 0, subarray_start = 0;
            std::set<int> array_num_record;
            std::unordered_map<int, int> num_location;
            for (int i = 0; i < nums.size(); i++){
                int num = nums.at(i);
                std::pair<std::set<int>::iterator, bool> flag = array_num_record.insert(num);
                if (!flag.second){
                    while (subarray_start <= num_location[num])
                    {
                        int over_num = nums.at(subarray_start);
                        array_num_record.erase(over_num);
                        subarray_sum -= over_num;
                        num_location.erase(over_num);
                        subarray_start++;
                    }
                    array_num_record.insert(num);
                    
                }
                subarray_sum += num;
                num_location[num] = i;
                answer = subarray_sum > answer ? subarray_sum : answer;
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
    int array_len = pow(10, 5); // 数组长度
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 12;
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，不同数字的子数组的最大和为：" << so.maximumUniqueSubarray(num_array) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。

返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。

 

示例 1：

输入：nums = [4,2,4,5,6]
输出：17
解释：最优子数组是 [2,4,5,6]
示例 2：

输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：最优子数组是 [5,2,1] 或 [1,2,5]
 

提示：

1 <= nums.length <= pow(10,5)
1 <= nums[i] <= pow(10,4) */