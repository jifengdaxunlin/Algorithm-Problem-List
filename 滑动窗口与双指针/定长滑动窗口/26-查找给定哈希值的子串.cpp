#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        if(s.empty()){
            return "";
        }
        else{
            for (int i = 0; i < (s.size() - k + 1); i++){
                string temp(s.begin() + i, s.begin() + i + k);
                int record = 0;

                for (int j = 0; j < k; j++){
                    record += (temp.at(j) - 'a' + 1) * pow(power, j);
                }

                if (record % modulo == hashValue){
                    return temp;
                }
            }
            return "";
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 1000,power = 5, modulo = 11, hashValue = 5, k = 10; // 字符串长度、窗口长度
    string s_test;
    for (int i = 0; i < array_len; i++)
    {
        int temp = rand() % 26;
        s_test.append(1, temp + 'a');
    }
    cout << s_test << endl;

    cout << "长度为 " << k << " 的第一个哈希值为 " << hashValue << " 的子串是："<< so.subStrHash(s_test,power,modulo,k,hashValue) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给定整数 p 和 m ，一个长度为 k 且下标从 0 开始的字符串 s 的哈希值按照如下函数计算：

hash(s, p, m) = (val(s[0]) * pow(p,0) + val(s[1]) * pow(p,1) + ... + val(s[k-1]) * pow(p,k-1)) mod m.
其中 val(s[i]) 表示 s[i] 在字母表中的下标，从 val('a') = 1 到 val('z') = 26 。

给你一个字符串 s 和整数 power，modulo，k 和 hashValue 。请你返回 s 中 第一个 长度为 k 的 子串 sub ，满足 hash(sub, power, modulo) == hashValue 。

测试数据保证一定 存在 至少一个这样的子串。

子串 定义为一个字符串中连续非空字符组成的序列。

示例 1：

输入：s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
输出："ee"
解释："ee" 的哈希值为 hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0 。
"ee" 是长度为 2 的第一个哈希值为 0 的子串，所以我们返回 "ee" 。
示例 2：

输入：s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
输出："fbx"
解释："fbx" 的哈希值为 hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 312) mod 100 = 23132 mod 100 = 32 。
"bxz" 的哈希值为 hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 312) mod 100 = 25732 mod 100 = 32 。
"fbx" 是长度为 3 的第一个哈希值为 32 的子串，所以我们返回 "fbx" 。
注意，"bxz" 的哈希值也为 32 ，但是它在字符串中比 "fbx" 更晚出现。
*/