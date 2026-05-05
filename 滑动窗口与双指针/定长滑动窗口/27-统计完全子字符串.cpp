#include <iostream>
#include <ctime> // time()
#include <unordered_map>    //哈希表头文件
#include <math.h>   
#include <vector>
using namespace std;

class Solution
{
public:
    int countCompleteSubstrings(string word, int k)
    {
        if(word.empty()){
            return 0;
        }
        else{
            int result = 0;
            unordered_map<char, int> record;
            unordered_map<char, char> letter;
            for (int i = 1; i < (int)(word.size() / k) + 1; i++)
            {
                record.clear();
                letter.clear();
                for (int j = 0; j < word.size(); j++){
                    record[word.at(j)]++;
                    letter[word.at(j)] = word.at(j);
                    if (j >= (k * i - 1))
                    {
                        if (j > (k * i - 1)){
                            record[word.at(j - k * i)]--;
                            if (record[word.at(j - k * i)] == 0)
                            {
                                record.erase(word.at(j - k * i));
                                letter.erase(word.at(j - k * i));
                            }
                        }

                        if (record.size() == i && letter.size() == i)
                        {
                            int num = 0;
                            auto le = letter.begin();
                            pair<char, char> temp = *le;
                            for (auto re = record.begin(); re != record.end(); re++, le++)
                            {
                                temp.second = le->second;
                                if (abs(temp.first - temp.second) <= 2 && re->second == k)
                                {
                                    temp.first = temp.second;
                                    num++;
                                }
                            }

                            if (num == i )
                            {
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
    Solution so;
    int string_len = 10, k = 3; // 字符串长度，字符出现次数
    string s_test;
    cout << "输入字符串：";
    cin >> s_test;

    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    cout << "长度为 " << string_len << " 的字符串，每个字符出现 " << k << " 次的子字符串个数：" << so.countCompleteSubstrings(s_test, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

// 提示1：There are at most 26 different lengths of the complete substrings: k *1, k * 2, … k * 26.****
// 提示2：For each length, we can use sliding window to count the frequency of each letter in the window.
// 提示3：We still need to check for all characters in the window that abs(word[i] - word[i - 1]) <= 2. We do this by maintaining the values of abs(word[i] - word[i - 1]) in the sliding window dynamically in an ordered multiset or priority queue, so that we know the maximum value at each iteration.

/*
给你一个字符串 word 和一个整数 k 。

如果 word 的一个子字符串 s 满足以下条件，我们称它是 完全字符串：

s 中每个字符 恰好 出现 k 次。
相邻字符在字母表中的顺序 至多 相差 2 。也就是说，s 中两个相邻字符 c1 和 c2 ，它们在字母表中的位置相差 至多 为 2 。
请你返回 word 中 完全 子字符串的数目。

子字符串 指的是一个字符串中一段连续 非空 的字符序列。

示例 1：

输入：word = "igigee", k = 2
输出：3
解释：完全子字符串需要满足每个字符恰好出现 2 次，且相邻字符相差至多为 2 ：igig, ee, igigee 。
示例 2：

输入：word = "aaabbbccc", k = 3
输出：6
解释：完全子字符串需要满足每个字符恰好出现 3 次，且相邻字符相差至多为 2 ：aaa, bbb, ccc, aaabbb, bbbccc, aaabbbccc 。
*/