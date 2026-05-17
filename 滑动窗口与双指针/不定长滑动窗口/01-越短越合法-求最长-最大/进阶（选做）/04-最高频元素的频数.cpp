#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <set>
#include <vector>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int maxFrequency(std::vector<int> &nums, int k)
    {
        if (nums.empty()){
            return 0;
        }
        else {
            int answer = 0, temp_freq_sum = 0;
            std::set<int> num_kind;
            std::unordered_map<int, int> num_frequency;
            for (int num : nums){
                num_kind.insert(num);
                num_frequency[num]++;
            }
            for (std::set<int>::iterator i = num_kind.begin(); i != num_kind.end(); i++){
                int change_num = 0;
                temp_freq_sum = 0;
                std::set<int>::iterator temp = i;
                while (i != num_kind.begin()){
                    change_num += num_frequency[*temp] * (*i - *temp);
                    if (change_num > k){
                        if (change_num > k){
                            change_num -= num_frequency[*temp] * (*i - *temp);
                            temp_freq_sum += (int)((k - change_num) / (*i - *temp));
                        }
                        break;
                    }
                    temp_freq_sum += num_frequency[*temp];
                    if (temp == num_kind.begin()){
                        break;
                    }
                    temp--;
                }
                int tt = temp_freq_sum > num_frequency[*i] ? temp_freq_sum : num_frequency[*i];
                answer = tt > answer ? tt : answer;
                //cout << *i << "\t" << answer << endl;
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
    int array_len = pow(10, 5), k = pow(10, 5); // 数组长度、操作次数
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % (int)pow(10, 5);
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，通过加 " << k << " 个加 1 操作，得到的最大频数为：" << so.maxFrequency(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 元素的 频数 是该元素在一个数组中出现的次数。

给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。

执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

 

示例 1：

输入：nums = [1,2,4], k = 5
输出：3
解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
4 是数组中最高频元素，频数是 3 。
示例 2：

输入：nums = [1,4,8,13], k = 5
输出：2
解释：存在多种最优解决方案：
- 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
- 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
- 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。
示例 3：

输入：nums = [3,9,6], k = 2
输出：1
 

提示：

1 <= nums.length <= pow(10,5)
1 <= nums[i] <= pow(10,5)
1 <= k <= pow(10,5) */