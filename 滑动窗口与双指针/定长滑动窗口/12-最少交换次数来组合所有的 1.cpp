#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &data)
    {
        if(data.empty()){
            return 0;
        }
        else{
            unordered_map<int, int> result;
            int length = data.size(), flag = 0, ans = 0;
            for (int i = 0; i < length;i++){
                if(data[i]){
                    ++flag;
                }
            }
            for (int i = 0; i < length;i++){
                ++result[data[i]];
                if (i > (flag - 1))
                {
                    --result[data[i - flag]];
                }
                if (result[1] > ans){
                    ans = result[1];

                }
            }
            return (flag - ans);
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10; // 字符串数组长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 2;
        cout << num_array[i] << "\t";
    }
    cout << endl
         << "组合所有的 1 最少的交换次数为"<<so.minSwaps(num_array);

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
题目描述
给出一个二进制数组 data，你需要通过交换位置，将数组中 任何位置 上的 1 组合到一起，并返回所有可能中所需 最少的交换次数。

示例 1:

输入: data = [1,0,1,0,1]
输出: 1
解释:
有三种可能的方法可以把所有的 1 组合在一起：
[1,1,1,0,0]，交换 1 次；
[0,1,1,1,0]，交换 2 次；
[0,0,1,1,1]，交换 1 次。
所以最少的交换次数为 1。
示例  2:

输入：data = [0,0,0,1,0]
输出：0
解释：
由于数组中只有一个 1，所以不需要交换。
示例 3:

输入：data = [1,0,1,0,1,0,0,1,1,0,1]
输出：3
解释：
交换 3 次，一种可行的只用 3 次交换的解决方案是 [0,0,0,0,0,1,1,1,1,1,1]。
示例 4:

输入: data = [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
输出: 8
*/