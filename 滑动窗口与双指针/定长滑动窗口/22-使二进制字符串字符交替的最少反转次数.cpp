#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;
#define MIN(a,b) a < b ? a : b

class Solution
{
public:
    int minFlips(string s)
    {
        if(s.empty()){
            return 0;
        }
        else{
            int size = s.size(), result = size, min = 0;
            unordered_map<char, int> odd, even;
            for (int i = 0; i < size; i++)
            {
                if (i % 2)
                {
                    odd[s.at(i)]++;
                }
                else
                {
                    even[s.at(i)]++;
                }
            }
            result = MIN(abs(size - odd['0'] - even['1']), abs(size - odd['1'] - even['0']));

            if (size % 2){
                for (int j = 0; j < (size - 1); j++){
                    if (j % 2){
                        even[s.at(j)]++;
                        odd[s.at(j)]--;
                    }
                    else{
                        even[s.at(j)]--;
                        odd[s.at(j)]++;
                    }
                    min = MIN(abs(size - odd['0'] - even['1']), abs(size - odd['1'] - even['0']));
                    if (min < result){
                        result = min;
                    }
                }
                return result;
            }
            else{
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
    int array_len = 19; // 数组长度
    string s;
    for (int i = 0; i < array_len; i++)
    {
        s.push_back((rand() % 2) ? '1' : '0');
    }
    cout << s << endl;

    cout << "长度为：" << array_len << "的二进制字符串，最少反转次数为：" << so.minFlips(s) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给你一个二进制字符串 s 。你可以按任意顺序执行以下两种操作任意次：

类型 1 ：删除 字符串 s 的第一个字符并将它 添加 到字符串结尾。
类型 2 ：选择 字符串 s 中任意一个字符并将该字符 反转 ，也就是如果值为 '0' ，则反转得到 '1' ，反之亦然。
请你返回使 s 变成 交替 字符串的前提下， 类型 2 的 最少 操作次数 。

我们称一个字符串是 交替 的，需要满足任意相邻字符都不同。

比方说，字符串 "010" 和 "1010" 都是交替的，但是字符串 "0100" 不是。

示例 1：

输入：s = "111000"
输出：2
解释：执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "101010" 。

示例 2：

输入：s = "010"
输出：0
解释：字符串已经是交替的。

示例 3：

输入：s = "1110"
输出：1
解释：对第二个字符执行第二种操作，得到 s = "1010" 。
*/