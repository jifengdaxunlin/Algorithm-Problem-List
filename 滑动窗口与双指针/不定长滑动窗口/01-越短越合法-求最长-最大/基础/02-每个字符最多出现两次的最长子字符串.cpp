#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        if (s.empty()){
            return 0;
        }
        else{
            int record_location[26][2] = {0};
            string result, temp;
            unordered_map<char, int> record_count;
            for (int i = 0; i < s.size(); i++){
                int letter_index = s.at(i) - 'a';
                record_count[s.at(i)]++;
                if (record_count[s.at(i)] > 2){
                    if (temp >= result){
                        result = temp;
                    }
                    temp.clear();
                    record_count.clear();
                    temp = s.substr(record_location[letter_index][0] + 1, i - record_location[letter_index][0] - 1);
                    for (int j = 0; j < temp.size(); j++){
                        record_count[temp.at(j)]++;
                    }
                }
                temp.push_back(s.at(i));
                record_location[letter_index][0] = record_location[letter_index][1];
                record_location[letter_index][1] = i;
            }
            if (temp.size() > result.size()){
                result = temp;
            }
            cout << result << endl;
            return result.size();
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int string_len = 100; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, rand() % 26 + 'a');
    }
    cout << s_test << endl;

    cout << "长度为 " << string_len << " 的字符串,每个字符最多出现两次的最长字符子串长度为：" << so.maximumLengthSubstring(s_test) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/* 给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该子字符串的 最大 长度。

示例 1：

输入： s = "bcbbbcba"

输出： 4

解释：

以下子字符串长度为 4，并且每个字符最多出现两次："bcbbbcba"。

示例 2：

输入： s = "aaaa"

输出： 2

解释：

以下子字符串长度为 2，并且每个字符最多出现两次："aaaa"。

 

提示：

2 <= s.length <= 100
s 仅由小写英文字母组成。 */