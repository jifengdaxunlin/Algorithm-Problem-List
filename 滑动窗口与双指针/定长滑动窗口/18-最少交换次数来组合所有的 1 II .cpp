#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        if(nums.empty()){
            return 0;
        }
        else{
            int one_max = 0, result = 0, temp = 0, size = nums.size();
            for (int i = 0; i < size;i++){
                one_max += nums.at(i);
            }

            for (int k = 0; k < one_max;k++){
                temp += nums.at(k);
            }
            result = temp;

            for (int j = 0; j < size;j++){
                if (j < (size - one_max)){
                    temp -= nums.at(j);
                    temp += nums.at(j + one_max);
                }
                else{
                    temp -= nums.at(j);
                    temp += nums.at((j + one_max) % size);
                }

                if (temp > result){
                    result = temp;
                }
            }
            return one_max - result;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10; // 数组长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 2;
        cout << num_array[i] << "  ";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的、由 1、0 组成的数组，组合所有的 1 最少交换次数：" << so.minSwaps(num_array) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
交换 定义为选中一个数组中的两个 互不相同 的位置并交换二者的值。

环形 数组是一个数组，可以认为 第一个 元素和 最后一个 元素 相邻 。

给你一个 二进制环形 数组 nums ，返回在 任意位置 将数组中的所有 1 聚集在一起需要的最少交换次数。

示例 1：

输入：nums = [0,1,0,1,1,0,0]
输出：1
解释：这里列出一些能够将所有 1 聚集在一起的方案：
[0,0,1,1,1,0,0] 交换 1 次。
[0,1,1,1,0,0,0] 交换 1 次。
[1,1,0,0,0,0,1] 交换 2 次（利用数组的环形特性）。
无法在交换 0 次的情况下将数组中的所有 1 聚集在一起。
因此，需要的最少交换次数为 1 。
示例 2：

输入：nums = [0,1,1,1,0,0,1,1,0]
输出：2
解释：这里列出一些能够将所有 1 聚集在一起的方案：
[1,1,1,0,0,0,0,1,1] 交换 2 次（利用数组的环形特性）。
[1,1,1,1,1,0,0,0,0] 交换 2 次。
无法在交换 0 次或 1 次的情况下将数组中的所有 1 聚集在一起。
因此，需要的最少交换次数为 2 。
示例 3：

输入：nums = [1,1,0,0,1]
输出：0
解释：得益于数组的环形特性，所有的 1 已经聚集在一起。
因此，需要的最少交换次数为 0 。
*/