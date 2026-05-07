#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty()){
            return 0;
        }else{
            string result, temp;
            unordered_map<char, int> record;
            for (int i = 0; i < s.size(); i++)
            {
                record[s.at(i)]++;
                temp.append(1, s.at(i));
                //cout << temp << endl;
                if (record[s.at(i)] > 1)
                {
                    if (temp.size() >= result.size()){
                        result = temp;
                        result.pop_back();
                    }
                    record.clear();
                    temp.clear();
                    record[s.at(i)]++;
                    temp.append(1, s.at(i));
                }
                if (temp.size() >= result.size())
                {
                    result = temp;
                }
            }
            //cout << result << endl;
            return result.size();
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int string_len = 5 * (int)pow(10, 4); // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, rand() % 95 + 32);
    }
    cout << s_test  <<endl;

    cout << "长度为 " << string_len << " 的字符串的不重复字符子串长度为：" << so.lengthOfLongestSubstring(s_test) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成 */