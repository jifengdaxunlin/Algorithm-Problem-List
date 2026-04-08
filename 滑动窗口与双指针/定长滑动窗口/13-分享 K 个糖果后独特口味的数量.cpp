#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int shareCandies(vector<int> &candies, int k)
    {
        if(candies.empty()){
            return 0;
        }
        else{
            unordered_map<int, int> standard;
            int max_kind = 0, flag = 0,length = candies.size();
            for (int i = 0; i < length;i++){
                ++standard[candies[i]];
            }
            for (int i = 0; i < length;i++){
                --standard[candies[i]];
                if(standard[candies[i]]==0){
                    standard.erase(candies[i]);
                }
                if(i>=(k-1)){
                    if(i==(k-1)){
                        flag = standard.size();
                    }
                    else{
                        ++standard[candies[i - k]];
                        if (flag < standard.size())
                        {
                            flag = standard.size();
                        }
                    }
                }
            }
            return flag;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, k = 5; // 字符串数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 5;
        cout << num_array[i] << "\t";
    }
    cout << endl
         << "糖果数量为 " << array_len << " ,给妹妹 " << k << " 个连续的糖果,最多保留 " << so.shareCandies(num_array, k) << " 个独特口味的糖果";

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
您将获得一个 从0开始的 整数数组 candies ，其中 candies[i] 表示第 i 个糖果的味道。你妈妈想让你和你妹妹分享这些糖果，给她 k 个 连续 的糖果，但你想保留尽可能多的糖果口味。
在与妹妹分享后，返回 最多 可保留的 独特 口味的糖果。

示例 1：

输入: candies = [1,2,2,3,4,3], k = 3
输出: 3
解释:
将[1,3]（含[2,2,3]）范围内的糖果加入[2,2,3]口味。
你可以吃各种口味的糖果[1,4,3]。
有3种独特的口味，所以返回3。

示例 2:

输入: candies = [2,2,2,2,3,3], k = 2
输出: 2
解释:
在[3,4]范围内（含[2,3]）的糖果中加入[2,3]口味。
你可以吃各种口味的糖果[2,2,2,3]。
有两种独特的口味，所以返回2。
请注意，你也可以分享口味为[2,2]的糖果，吃口味为[2,2,3,3]的糖果。

示例 3:

输入: candies = [2,4,5], k = 0
输出: 3
解释:
你不必给任何糖果。
你可以吃各种口味的糖果[2,4,5]。
有3种独特的口味，所以返回3。
*/