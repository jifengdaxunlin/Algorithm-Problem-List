#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int distinctPoints(string s, int k)
    {
        if (s.empty() || k == 0)
        {
            return 1;
        }
        else{
            unordered_map<string, int> record;
            string temp = s;
            pair<int, int> start;
            for (int i = 0; i < s.size()- k + 1;i++){
                temp = s;
                temp.erase(temp.begin() + i, temp.begin() + i + k);
                    char* location;
                    start = {0, 0};
                    for (int flag = 0; flag < temp.size();flag++){
                        if(temp.at(flag)=='U'){
                            start.second++;
                        }
                        else if (temp.at(flag) == 'D'){
                            start.second--;
                        }
                        else if(temp.at(flag)=='L'){
                            start.first--;
                        }
                        else if (temp.at(flag) == 'R')
                        {
                            start.first++;
                        }
                    }
                    sprintf(location, "%d,%d", start.first, start.second);
                    record[(string)location];
                    //cout << "\t" << temp.size() << "\t" << temp << "\t" << location << endl;
            }
            return record.size();
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, k = 4; // 字符串数组长度、移除字符长度
    string str,temp="UDLR";
    for (int i = 0; i < array_len; i++)
    {
        str.append(1, temp.at(rand() % 4));
    }
    cout << str << endl;

    cout << "长度为：" << array_len << " 的字符串，移除 " << k << " 长的字符后，不同的终点数为：" << so.distinctPoints(str, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给你一个由字符 'U'、'D'、'L' 和 'R' 组成的字符串 s，表示在无限的二维笛卡尔网格上的移动。

'U': 从 (x, y) 移动到 (x, y + 1)。
'D': 从 (x, y) 移动到 (x, y - 1)。
'L': 从 (x, y) 移动到 (x - 1, y)。
'R': 从 (x, y) 移动到 (x + 1, y)。
你还得到了一个正整数 k。

你 必须 选择并移除 恰好一个 长度为 k 的连续子字符串 s。然后，从坐标 (0, 0) 开始，按顺序执行剩余的移动。

返回可到达的 不同 最终坐标的数量。

示例 1:
输入：s = "LUL", k = 1
输出：2
解释：
移除长度为 1 的子字符串后，s 可以是 "UL"、"LL" 或 "LU"。执行这些移动后，最终坐标将分别是 (-1, 1)、(-2, 0) 和 (-1, 1)。有两个不同的点 (-1, 1) 和 (-2, 0)，因此答案是 2。

示例 2:
输入：s = "UDLR", k = 4
输出：1
解释：

移除长度为 4 的子字符串后，s 只能是空字符串。最终坐标将是 (0, 0)。只有一个不同的点 (0, 0)，因此答案是 1。

示例 3:
输入：s = "UU", k = 1
输出：1
解释：

移除长度为 1 的子字符串后，s 变为 "U"，它总是以 (0, 1) 结束，因此只有一个不同的最终坐标。
*/