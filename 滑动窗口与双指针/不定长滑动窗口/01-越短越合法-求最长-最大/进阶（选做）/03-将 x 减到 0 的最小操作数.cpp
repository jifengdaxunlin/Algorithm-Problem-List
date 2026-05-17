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
    int minOperations(std::vector<int> &nums, int x)
    {
        if (nums.empty()){
            return -1;
        }
        else {
            int answer = -1, sum_of_subarray = 0, sum_len = -1;
            std::list<int> subarray;
            for (auto i = nums.begin(); i != nums.end(); i++){
                subarray.push_front(*i);
                sum_of_subarray += *i;
                if (sum_of_subarray >= x){
                    sum_len = sum_of_subarray == x ? subarray.size() : sum_len;
                    answer = sum_len > answer ? sum_len : answer;
                    sum_of_subarray -= subarray.front();
                    subarray.pop_front();
                    break;
                }
            }
            for (int i = (nums.size() - 1); i >= 0; i--){
                static int sum_tail = 0;
                int num = nums.at(i);
                sum_tail += num;
                sum_of_subarray += num;
                subarray.push_back(num);
                if (sum_tail > x){
                    break;
                }
                while (sum_of_subarray >= x){
                    if(answer ==-1){
                        sum_len = sum_of_subarray == x ? subarray.size() : sum_len;
                        answer = sum_len > answer ? sum_len : answer;
                    }
                    else if(sum_of_subarray == x){
                        sum_len = sum_of_subarray == x ? subarray.size() : sum_len;
                        answer = sum_len < answer ? sum_len : answer;
                    }
                    //cout << i << "\t" << num << "\t" << subarray.front() << endl;
                    sum_of_subarray -= subarray.front();
                    subarray.pop_front();
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
    int array_len = pow(10, 5), x = pow(10, 5); // 数组长度、移除元素合
    std::vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % (int)pow(10, 3);
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，移除数组两边数字的值达到 " << x << " 的最少元素数为：" << so.minOperations(num_array, x) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

 

示例 1：

输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
示例 2：

输入：nums = [5,6,7,8,9], x = 4
输出：-1
示例 3：

输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 

提示：

1 <= nums.length <= pow(10,5)
1 <= nums[i] <= pow(10,4)
1 <= x <= pow(10,9) */