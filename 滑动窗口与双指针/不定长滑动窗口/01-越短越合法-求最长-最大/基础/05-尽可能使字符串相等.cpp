#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
#include <list>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        if (s.empty() || t.empty() || maxCost < 0){
            return 0;
        }
        else{
            int answer = 0, equal_string_len = 0, string_cost = 0;
            std::list<int> singel_leetter_cost;
            for (int i = 0; i < t.size(); i++){
                int num = abs(s.at(i) - t.at(i));
                singel_leetter_cost.push_back(num);
                string_cost += num;
                if (string_cost > maxCost){
                    while (string_cost > maxCost)
                    {
                        string_cost -= singel_leetter_cost.front();
                        singel_leetter_cost.pop_front();
                        equal_string_len -= equal_string_len ? 1 : 0;
                    }
                    continue;
                }
                equal_string_len++;
                answer = equal_string_len > answer ? equal_string_len : answer;
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
    int string_len = pow(10, 3), maxCost = pow(10, 2); // 字符串长度，修改花销
    string s, t;
    for (int i = 0; i < string_len; i++)
    {
        s.push_back(rand() % 26 + 'a');
        t.push_back(rand() % 26 + 'a');
    }
    cout << s << endl
         << t << endl;

    cout << "长度为 " << string_len << " 的字符串 s，t 转化字符串开销不大于 " << maxCost << " 的子字符串长度为：" << so.equalSubstring(s, t, maxCost) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

 

示例 1：

输入：s = "abcd", t = "bcdf", maxCost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
示例 2：

输入：s = "abcd", t = "cdef", maxCost = 3
输出：1
解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
示例 3：

输入：s = "abcd", t = "acde", maxCost = 0
输出：1
解释：a -> a, cost = 0，字符串未发生变化，所以最大长度为 1。
 

提示：

1 <= s.length <= pow(10,5)
t.length == s.length
0 <= maxCost <= (10,6)
s 和 t 都只含小写英文字母。 */