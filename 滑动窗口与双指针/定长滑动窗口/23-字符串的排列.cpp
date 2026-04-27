#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.empty() || s2.empty()){
            return false;
        }
        else{

            for (int i = 0; i < (s2.size() - s1.size() + 1); i++)
            {
                string temp(s2.begin() + i, s2.begin() + i + s1.size());
                cout << temp << endl;
                if(temp==s1){
                    return true;
                }
            }
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 100; // 字符串数组长度
    string s_long, s_short("ab");
    for (int i = 0; i < array_len; i++)
    {
        int temp = rand() % 52;
        if (temp < 26)
        {
            s_long.append(1, temp + 'a');
        }
        else
        {
            s_long.append(1, temp - 26 + 'A');
        }
    }
    cout << s_long << endl;

    if(so.checkInclusion(s_short,s_long)){
        cout << "s_long 中包含 " << s_short << " 的排序" << endl;
    }
    else{
        cout << "s_long 中不包含 " << s_short << " 的排序" << endl;
    }

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。

示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false
*/