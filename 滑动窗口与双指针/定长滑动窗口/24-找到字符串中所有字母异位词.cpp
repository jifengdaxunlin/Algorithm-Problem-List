#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.empty() || p.empty() || s.size() < p.size())
        {
            return {};
        }
        else{
            vector<int> result;
            unordered_map<char, int> record, test;
            for (int i = 0; i < p.size(); i++){
                record[p.at(i)]++;
            }
            for (int j = 0; j < s.size(); j++){
                test[s.at(j)]++;
                if (j >= (p.size() - 1)){
                    if (j > (p.size() - 1)){
                        test[s.at(j - p.size())]--;
                        if (test[s.at(j - p.size())]==0){
                            test.erase(s.at(j - p.size()));
                        }
                    }

                    if(record==test){
                        result.push_back(j - p.size() + 1);
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
    int array_len = 100; // 字符串长度
    string s_test, substring("adc");
    for (int i = 0; i < array_len; i++)
    {
        int temp = rand() % 10;
        s_test.append(1, temp + 'a');
    }
    cout << s_test << endl;

    vector<int> result = so.findAnagrams(s_test, substring);
    for (int num : result)
    {
        cout << num << "\t";
    }

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}