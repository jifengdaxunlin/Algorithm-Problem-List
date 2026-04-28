#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if(s.empty()||words.empty()){
            return {};
        }
        else{
            int window = 0;
            vector<int> ansower;
            unordered_map<char, int> result, record, temp, record_word[words.size()];
            for (int i = 0; i < words.size(); i++){
                for (int j = 0; j < words.at(i).length(); j++){
                    record[words.at(i).at(j)]++;
                    record_word[i][(words.at(i).at(j))]++;
                }
                window += words.at(i).length();
            }

            for (int x = 0; x < s.length(); x++){
                result[s.at(x)]++;
                if (x >= (window - 1)){
                    if (x > (window - 1)){
                        result[s.at(x - window)]--;
                        if (result[s.at(x - window)]==0){
                            result.erase(s.at(x - window));
                        }
                        
                    }
                    if (result == record)
                    {
                        int num = x - window + 1;
                        unordered_map<string, int> substring;
                        for (int i = 0; i < window; i++)
                        {
                            temp[s.at(num + i)]++;
                            if (temp == record_word[0]){
                                substring[words.at(0)]++;
                                temp.clear();
                            }
                            else if (temp == record_word[1]){
                                substring[words.at(1)]++;
                                temp.clear();
                            }
                            else if (temp == record_word[2])
                            {
                                substring[words.at(2)]++;
                                temp.clear();
                            }
                        }
                        if(substring.size()==words.size()){
                            ansower.push_back(x - window + 1);
                        }
                        
                    }
                }
            }

            return ansower;
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 100;
    string s_test;
    vector<string> words = {"hello", "world", "Cprogram"};
    for (int i = 0; i < array_len; i++)
    {
        int temp = rand() % 32;
        if (temp < 26){
            s_test.append(1, 'a' + temp);
        }
        else if(temp <29){
            int num[] = {0, 1, 2};
            for (int k = 0; k < 2;k++){
                int temp = num[0], index = rand() % 3;
                num[0] = num[index];
                num[index] = temp;
            }
            for (int i = 0; i < 3; i++){

                s_test.insert(s_test.size(), words.at(num[i]));
            }
                
        }
        else{
            for (int i = 0; i < 3; i++)
            {

                s_test.insert(s_test.size(), words.at(rand() % 3));
            }
        }
    }
    cout << s_test << endl;
    vector<int> result = so.findSubstring(s_test, words);
    for (int num : result){
        cout << num << "\t";
    }

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。



示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
*/