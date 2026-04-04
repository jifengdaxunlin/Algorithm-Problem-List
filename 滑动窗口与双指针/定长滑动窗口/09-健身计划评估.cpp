#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
using namespace std;
/*
给定一个数组 calories，其中 calories[i] 代表好友第 i 天需要消耗的卡路里总量。再给定 lower 代表较低消耗的卡路里，upper 代表较高消耗的卡路里。再给定一个整数 k，代表连续 k 天。

* 如果你的好友在这一天以及之后连续 k 天内消耗的总卡路里 T 小于 lower，则这一天的计划相对糟糕，并失去 11 分。
* 如果你的好友在这一天以及之后连续 k 天内消耗的总卡路里 T 高于 upper，则这一天的计划相对优秀，并得到 11 分。
* 如果你的好友在这一天以及之后连续 k 天内消耗的总卡路里 T 大于等于 lower，并且小于等于 upper，则这份计划普普通通，分值不做变动。

**要求**：输出最后评估的得分情况。

**说明**：

* 1 ≤ k ≤ calories.length ≤ 10**5
* 0 ≤ calories[i] ≤ 20000
* 0 ≤ lower ≤ upper
*/

class Solution{
    public:
        int dietPlanPerformance(vector<int>&calories, int k, int lower, int upper)
        {
            int calories_len = calories.size();
            if (k == 0 || lower == 0 || upper == 0)
            {
                cout << "参数错误..." << endl;
                return 0;
            }
            else{
                int source = 0, k_calorises = 0;
                for (int i = 0; i < calories_len;i++){
                    k_calorises += calories[i];
                        if(i==(k-1)){
                            if(k_calorises<lower){
                                --source;
                            }else if(k_calorises>upper){
                                ++source;
                            }
                        }
                        else if (i >= k)
                        {
                            k_calorises -= calories[i - k];
                            if (k_calorises < lower)
                            {
                                --source;
                            }
                            else if (k_calorises > upper)
                            {
                                ++source;
                            }
                        }
                }

                return source;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, k = 3,lower=25000,upper=30000; // 字符串数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 20001;
        cout << num_array[i] << "\t";
    }
    cout << "" << endl;
    cout << "子天数为 " << k << " 天，总天数为 " << array_len << " 的健身计划分数：" <<so.dietPlanPerformance(num_array,k,lower,upper)<< endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
