#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if(s.empty() || k==0){
            return false;
        }
        else{
            int window = 0, num_size = 1 << k;
            unordered_map<int, bool> record;
            for (int i = 0; i < s.size(); i++){
                window = (window << 1) | (s.at(i) - '0');
                if(i>=(k-1)){
                    if (i >= k)
                    {
                        window &= (1 << k) - 1;
                    }
                    if (window <= (num_size - 1))
                    {
                        record[window] = true;
                    }
                }
            }
            if (record.size() == num_size){
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
    int string_len = 20, k = 3; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, '0' + rand() % 2);
    }
    cout << s_test << endl;

    if (so.hasAllCodes(s_test, k)){
        cout << "字符串包含所有长度为 " << k << " 的二进制子串" << endl;
    }
    else{
        cout << "字符串缺少长度为 " << k << " 的二进制子串" << endl;
    }

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/* 给你一个二进制字符串 s 和一个整数 k 。如果所有长度为 k 的二进制字符串都是 s 的子串，请返回 true ，否则请返回 false 。

示例 1：

输入：s = "00110110", k = 2
输出：true
解释：长度为 2 的二进制串包括 "00"，"01"，"10" 和 "11"。它们分别是 s 中下标为 0，1，3，2 开始的长度为 2 的子串。
示例 2：

输入：s = "0110", k = 1
输出：true
解释：长度为 1 的二进制串包括 "0" 和 "1"，显然它们都是 s 的子串。
示例 3：

输入：s = "0110", k = 2
输出：false
解释：长度为 2 的二进制串 "00" 没有出现在 s 中。 */