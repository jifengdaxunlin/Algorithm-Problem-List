#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        if(nums.empty()){
            return 0;
        }
        else{
            int answer = 0, zero_lication = 0;
            unordered_map<int, int> record;
            for (int i = 0; i < nums.size(); i++){
                record[nums.at(i)]++;
                if (record[0] > 1){
                    if (record[1] > answer)
                    {
                        answer = record[1];
                    }
                    record[0]--;
                    record[1] = (i - zero_lication - 1);
                }
                if(!nums.at(i)){
                    zero_lication = i;
                }
            }
            answer = answer > record[1] ? answer : record[1];
            return answer;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));

    Solution so;
    int array_len = (int)pow(10, 4); // 数组长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 2;
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    cout << "长度为 " << array_len << " 的 0,1 数组,删除一个元素后，最长的且只包含 1 的非空子数组的长度为：" << so.longestSubarray(num_array) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。

如果不存在这样的子数组，请返回 0 。

提示 1：

输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
示例 2：

输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
示例 3：

输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。
 

提示：

1 <= nums.length <= pow(10,5)
nums[i] 要么是 0 要么是 1 。 */