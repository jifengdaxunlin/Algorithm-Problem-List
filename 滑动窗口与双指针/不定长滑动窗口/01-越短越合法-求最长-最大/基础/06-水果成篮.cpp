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
    int totalFruit(std::vector<int> &fruits)
    {
        if (fruits.empty()){
            return 0;
        }
        else {
            int answer = 0, window_start = 0;
            std::pair<int, int> num_location;
            std::set<int> num_kind_record;
            for (int i = 0; i < fruits.size(); i++){
                int num = fruits.at(i);
                num_kind_record.insert(num);
                if (num_kind_record.size() > 2){
                    int location = num_location.first < num_location.second ? num_location.first : num_location.second;
                    num_kind_record.erase(fruits.at(location));
                    window_start = location + 1;
                    num_location.first = num_location.first > num_location.second ? num_location.first : num_location.second;
                    num_location.second = num_location.first;
                }
                num_location.first = *num_kind_record.begin() == num ? i : num_location.first;
                num_location.second = *prev(num_kind_record.end()) == num ? i : num_location.second;
                answer = (i - window_start + 1) > answer ? (i - window_start + 1) : answer;
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
        num_array[i] = rand() % 10;
        //cout << num_array[i] << "\t";
    }
    cout << endl;

    cout << "长度为 " << array_len << " 的数组，只含两种数字的最长子数组长度为：" << so.totalFruit(num_array) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
} 
/* 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
 你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

 示例 1：

 输入：fruits = [1,2,1]
 输出：3
 解释：可以采摘全部 3 棵树。
 示例 2：

 输入：fruits = [0,1,2,2]
 输出：3
 解释：可以采摘 [1,2,2] 这三棵树。
 如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
 示例 3：

 输入：fruits = [1,2,3,2,2]
 输出：4
 解释：可以采摘 [2,3,2,2] 这四棵树。
 如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
 示例 4：

 输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
 输出：5
 解释：可以采摘 [1,2,1,1,2] 这五棵树。


 提示：

 1 <= fruits.length <= pow(10,5)
 0 <= fruits[i] < fruits.length */