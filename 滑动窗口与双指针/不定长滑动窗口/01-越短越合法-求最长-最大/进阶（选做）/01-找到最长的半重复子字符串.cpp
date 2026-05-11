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
    int longestSemiRepetitiveSubstring(string s)
    {
        if (s.empty()){
            return 0;
        }
        else {
            int answer = 0, sub_len = 0, sub_start = 0;
            std::list<int> location;
            for (int i = 0; i < s.size(); i++){
                int num = s.at(i) - '0';
                if (i){
                    if (num == (s.at(i - 1) - '0'))
                    {
                        location.push_back(i);
                        if (location.size() > 1){
                            sub_len -= (location.front() - sub_start);
                            sub_start = location.front();
                            location.pop_front();
                        }
                    }
                }
                sub_len++;
                answer = sub_len > answer ? sub_len : answer;
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
    int string_len = 50; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, rand()%10 + '0');
    }
    cout << s_test << endl;

    cout << "长度为 " << string_len << " 的字符串，最长的半重复（只有一对字符相等）子字符串长度为：" << so.longestSemiRepetitiveSubstring(s_test) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你一个下标从 0 开始的字符串 s ，这个字符串只包含 0 到 9 的数字字符。

如果一个字符串 t 中至多有一对相邻字符是相等的，那么称这个字符串 t 是 半重复的 。例如，"0010" 、"002020" 、"0123" 、"2002" 和 "54944" 是半重复字符串，而 "00101022" （相邻的相同数字对是 00 和 22）和 "1101234883" （相邻的相同数字对是 11 和 88）不是半重复字符串。

请你返回 s 中最长 半重复 子字符串 的长度。


示例 1：

输入：s = "52233"

输出：4

解释：

最长的半重复子字符串是 "5223"。整个字符串 "52233" 有两个相邻的相同数字对 22 和 33，但最多只能选取一个。

示例 2：

输入：s = "5494"

输出：4

解释：

s 是一个半重复字符串。

示例 3：

输入：s = "1111111"

输出：2

解释：

最长的半重复子字符串是 "11"。子字符串 "111" 有两个相邻的相同数字对，但最多允许选取一个。

提示：

1 <= s.length <= 50
'0' <= s[i] <= '9' */