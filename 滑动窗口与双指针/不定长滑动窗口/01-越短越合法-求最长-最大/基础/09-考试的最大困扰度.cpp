#include <iostream>
#include <ctime>         // time()
#include <unordered_map> //哈希表头文件
#include <cmath>
#include <list>
#include <vector>
using std::cin, std::cout, std::endl, std::string;

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        if (answerKey.empty()){
            return 0;
        }
        else {
            int answer = 0, T_sub_k = 0, F_sub_k = 0, T_start = 0, F_start = 0;
            std::unordered_map<char, std::list<int>> letter_location;
            for (int i = 0; i < answerKey.size(); i++){
                char letter = answerKey.at(i);
                letter_location[letter].push_back(i);
                if (letter_location[letter].size() > k && letter == 'T'){
                    int start = letter_location[letter].front();
                    T_sub_k -= (start - T_start + 1);
                    T_start = start + 1;
                    letter_location[letter].pop_front();
                }
                else if (letter_location[letter].size() > k && letter == 'F'){
                    int start = letter_location[letter].front();
                    F_sub_k -= (start - F_start + 1);
                    F_start = start + 1;
                    letter_location[letter].pop_front();
                }
                T_sub_k++;
                F_sub_k++;
                answer = ((T_sub_k > F_sub_k) ? T_sub_k : F_sub_k) > answer ? ((T_sub_k > F_sub_k) ? T_sub_k : F_sub_k) : answer;
            }
            return answer;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    
    Solution so;
    int string_len = 5 * pow(10, 6), k = 300; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        s_test.append(1, rand() % 2 ? 'T' : 'F');
    }
    //cout << s_test << endl;

    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数
    cout << "长度为 " << string_len << " 的由 T，F 组成的字符串，最多含 " << k << " 个不同元素的最长子字符串长度为：" << so.maxConsecutiveAnswers(s_test, k) << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/* 一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。

示例 1：

输入：answerKey = "TTFF", k = 2
输出：4
解释：我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "TTTT" 。
总共有四个连续的 'T' 。
示例 2：

输入：answerKey = "TFFT", k = 1
输出：3
解释：我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "FFFT" 。
或者，我们可以将第二个 'T' 换成 'F' ，得到 answerKey = "TFFF" 。
两种情况下，都有三个连续的 'F' 。
示例 3：

输入：answerKey = "TTFTTFTT", k = 1
输出：5
解释：我们可以将第一个 'F' 换成 'T' ，得到 answerKey = "TTTTTFTT" 。
或者我们可以将第二个 'F' 换成 'T' ，得到 answerKey = "TTFTTTTT" 。
两种情况下，都有五个连续的 'T' 。
 

提示：

n == answerKey.length
1 <= n <= 5 * pow(10,4)
answerKey[i] 要么是 'T' ，要么是 'F'
1 <= k <= n */