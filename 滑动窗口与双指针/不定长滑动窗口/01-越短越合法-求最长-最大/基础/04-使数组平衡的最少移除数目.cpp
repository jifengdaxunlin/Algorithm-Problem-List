#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        if (nums.empty() || k < 1){
            return 0;
        }
        else{
            int answer = 0;
            multiset<int> min_max;
            for (int i = 0; i < nums.size(); i++){
                int num = nums.at(i);
                if (!num){  //直接移除0，跳出本次循环
                    answer++;
                    continue;
                }
                min_max.insert(num);
                set<int>::iterator min = min_max.begin(), max = min_max.end();
                max--;
                while (((*max + *min - 1) / *min) > k)//向上取整
                {
                    int diff_1 = *next(min) - *min;
                    int diff_2 = *max - *prev(min_max.end());
                    diff_1 >= diff_2 ? min_max.erase(min) : min_max.erase(max);//移除大差值的最值，差值相等先移除最小值
                    min = min_max.begin(), max = min_max.end(), max--;
                    answer++;
                }
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
    int array_len = (int)pow(10,5), k = 3; // 数组长度、平衡倍数
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 100;
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，要平衡(最大值/最小值 <= " << k << ")，需移除元素数为：" << so.minRemoval(num_array, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个整数数组 nums 和一个整数 k。

如果一个数组的 最大 元素的值 至多 是其 最小 元素的 k 倍，则该数组被称为是 平衡 的。

你可以从 nums 中移除 任意 数量的元素，但不能使其变为 空 数组。

返回为了使剩余数组平衡，需要移除的元素的 最小 数量。

注意：大小为 1 的数组被认为是平衡的，因为其最大值和最小值相等，且条件总是成立。

示例 1:

输入：nums = [2,1,5], k = 2

输出：1

解释：

移除 nums[2] = 5 得到 nums = [2, 1]。
现在 max = 2, min = 1，且 max <= min * k，因为 2 <= 1 * 2。因此，答案是 1。
示例 2:

输入：nums = [1,6,2,9], k = 3

输出：2

解释：

移除 nums[0] = 1 和 nums[3] = 9 得到 nums = [6, 2]。
现在 max = 6, min = 2，且 max <= min * k，因为 6 <= 2 * 3。因此，答案是 2。
示例 3:

输入：nums = [4,6], k = 2

输出：0

解释：

由于 nums 已经平衡，因为 6 <= 4 * 2，所以不需要移除任何元素。
 

提示：

1 <= nums.length <= pow(10,5)
1 <= nums[i] <= pow(10,9)
1 <= k <= pow(10,5) */