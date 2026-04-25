#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        if(s.empty()){
            return 0;
        }
        else{
            int size = s.size(), max = 0;
            unordered_map<char, int> record;
            unordered_map<string, int> srecord;
            for (int array_len = minSize; array_len <= maxSize; array_len++){

                for (int i = 0; i < size; i++){
                    record[s.at(i)]++;

                    if (i >= array_len)
                    {
                        record.at(s.at(i-array_len))--;
                        if (record.at(s.at(i - array_len))==0)
                        {
                            record.erase(s.at(i - array_len));
                        }
                    }

                    if (i >= (array_len - 1) && record.size() >= maxLetters)
                    {
                        string flag(s.begin() + i - array_len + 1, s.begin() + i);
                        srecord[flag]++;
                    }
                }

                record.clear();
            }

            for (auto num = srecord.begin(); num !=srecord.end(); num++){
                if (max < num->second)
                {
                    //cout << num->first << endl;
                    max = num->second;
                }
            }
            return max;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));

    Solution so;
    int maxLetters = 2, minSize = 3, maxSize = 4; //子串不同字母数阈值，子串最小长度，子串最大长度
    string s;
    cout << "输入字符串：";
    cin >> s;
    cout << s << endl;

    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    cout << "子串最多出现次数：" << so.maxFreq(s, maxLetters, minSize, maxSize) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给你一个字符串 s ，请你返回满足以下条件且出现次数最大的 任意 子串的出现次数：

子串中不同字母的数目必须小于等于 maxLetters 。
子串的长度必须大于等于 minSize 且小于等于 maxSize 。

示例 1：

输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
输出：2
解释：子串 "aab" 在原字符串中出现了 2 次。
它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
示例 2：

输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
输出：2
解释：子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
示例 3：

输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
输出：3
示例 4：

输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
输出：0
*/