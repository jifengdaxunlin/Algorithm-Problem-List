#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool queryString(string s, int n)
    {
        if (s.empty() || n < 0){
            return false;
        }
        else{
            int flag = (int)log2(n + 1), windows = 0, windows_more = 0;
            unordered_map<int, bool> record;
            for (int i = 0; i < s.size(); i++){
                windows = (windows << 1) | (s.at(i) - '0');
                windows_more = (windows_more << 1) | (s.at(i) - '0');
                if (i > (flag - 1)){
                    windows &= (1 << flag) - 1;
                    if (i > flag){
                        windows_more &= (1 << (flag + 1)) - 1;
                    }
                    record[windows] = true;
                    if (windows_more <= n){
                        record[windows_more] = true;
                    }
                }
            }
            if (record.size() == (n + 1)){
                return true;
            }
            else{
                return false;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int string_len = 1000, k = 160; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, rand() % 2 + '0');
    }
    cout << s_test <<" "<< (int)log2(k + 1)<< endl;

    if (so.queryString(s_test, k))
    {
        cout << "字符串包含所有 " << k << " 的二进制数子串" << endl;
    }
    else
    {
        cout << "字符串缺少 " << k << " 的二进制子串" << endl;
    }

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n] 范围内的每个整数，其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回 false 。

子字符串 是字符串中连续的字符序列。



示例 1：

输入：s = "0110", n = 3
输出：true
示例 2：

输入：s = "0110", n = 4
输出：false

提示：

1 <= s.length <= 1000
s[i] 不是 '0' 就是 '1'
1 <= n <= 109*/