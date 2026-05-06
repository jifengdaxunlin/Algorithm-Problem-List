#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        if(nums.empty() || k < 0){
            return {};
        }
        else{
            vector<int> result, start, end;
            for (int i = 0; i < nums.size(); i++){
                if (nums.at(i) == key){
                    start.push_back(i - k);
                    end.push_back(i + k);
                }
            }

            if (start.empty() || end.empty())
            {
                return {};
            }
            else{
                int flag = 0;
                for (int j = 0; j < nums.size(); j++)
                {

                    if (j >= start.at(flag) && j <= end.at(flag)){
                        result.push_back(j);
                        if (j == end.at(flag) && (start.size() - 1) > flag){
                            flag++;
                        }
                    }
                }
                return result;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, key = 6, k = 1; // 数组长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        cout << num_array[i] << "\t";
    }
    cout << endl;

    for (int num : so.findKDistantIndices(num_array, key, k)){
        cout << num << "\t";
    }
    cout << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个下标从 0 开始的整数数组 nums 和两个整数 key 和 k 。K 近邻下标 是 nums 中的一个下标 i ，并满足至少存在一个下标 j 使得 |i - j| <= k 且 nums[j] == key 。

以列表形式返回按 递增顺序 排序的所有 K 近邻下标。

 

示例 1：

输入：nums = [3,4,9,1,3,9,5], key = 9, k = 1
输出：[1,2,3,4,5,6]
解释：因此，nums[2] == key 且 nums[5] == key。
- 对下标 0 ，|0 - 2| > k 且 |0 - 5| > k，所以不存在 j 使得 |0 - j| <= k 且 nums[j] == key。所以 0 不是一个 K 近邻下标。
- 对下标 1 ，|1 - 2| <= k 且 nums[2] == key，所以 1 是一个 K 近邻下标。
- 对下标 2 ，|2 - 2| <= k 且 nums[2] == key，所以 2 是一个 K 近邻下标。
- 对下标 3 ，|3 - 2| <= k 且 nums[2] == key，所以 3 是一个 K 近邻下标。
- 对下标 4 ，|4 - 5| <= k 且 nums[5] == key，所以 4 是一个 K 近邻下标。
- 对下标 5 ，|5 - 5| <= k 且 nums[5] == key，所以 5 是一个 K 近邻下标。
- 对下标 6 ，|6 - 5| <= k 且 nums[5] == key，所以 6 是一个 K 近邻下标。
因此，按递增顺序返回 [1,2,3,4,5,6] 。 
示例 2：

输入：nums = [2,2,2,2,2], key = 2, k = 2
输出：[0,1,2,3,4]
解释：对 nums 的所有下标 i ，总存在某个下标 j 使得 |i - j| <= k 且 nums[j] == key，所以每个下标都是一个 K 近邻下标。 
因此，返回 [0,1,2,3,4] 。 */