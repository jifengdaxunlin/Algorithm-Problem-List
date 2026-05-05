#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int equalCountSubstrings(string s, int count)
    {
        if(s.empty() || count == 0){
            return 0;
        }
        else{
            int result = 0;
            unordered_map<char, int> record;
            for (int j = 1; j < (s.size() / count) + 1; j++){
                record.clear();
                for (int i = 0; i < s.size(); i++)
                {
                    record[s.at(i)]++;
                    if (i >= (j * count - 1))
                    {
                        if (i > (j * count) - 1){
                            record[s.at(i - j * count)]--;
                            if (record[s.at(i - j * count)] == 0){
                                record.erase(s.at(i - j * count));
                            }
                        }

                        if (record.size() == j){
                            int temp = 0;
                            for(auto num : record){
                                if (num.second == count)
                                {
                                    temp++;
                                }
                            }

                            if(temp == j){
                                result++;
                            }
                        }
                    }
                }
            }
            return result;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int string_len = 10, k = 3; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, rand() % 4 + 'a');
    }
    cout << s_test << endl;

    cout << "长度为 " << string_len << " 的字符串，字母恰好出现 " << k << " 次的子字符串个数：" << so.equalCountSubstrings(s_test, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
题目描述
给你一个下标从 0 开始的字符串 s，只包含小写英文字母和一个整数 count。如果 s 的 子串 中的每种字母在子串中恰好出现 count 次，这个子串就被称为 等计数子串。

返回 s 中 等计数子串 的个数。

子串 是字符串中连续的非空字符序列。

示例 1:

输入: s = "aaabcbbcc", count = 3
输出: 3
解释:
从下标 0 开始到下标 2 结束的子串是 "aaa"。
字母 “a” 在子串中恰好出现了 3 次。
从下标 3 开始到下标 8 结束的子串是 "bcbbcc"。
字母 “b” 和 “c” 在子串中恰好出现了 3 次。
从下标 0 开始到下标 8 结束的子串是 "aaabcbbcc"。
字母 “a”、“b” 和 “c” 在子串中恰好出现了 3 次。
示例 2:

输入: s = "abcd", count = 2
输出: 0
解释:
每种字母在 s 中出现的次数小于 count。
因此，s 中没有子串是等计数子串，返回 0。
示例 3:

输入: s = "a", count = 5
输出: 0
解释:
每种字母在 s 中出现的次数小于 count。
因此，s 中没有子串是等计数子串，返回 0。
*/