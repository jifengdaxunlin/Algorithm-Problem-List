#include <iostream>
#include <ctime>   // time()
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numKLenSubstrNoRepeats(string s, int k)
    {
        if (s.empty() || k == 0)
        {
            return 0;
        }
        else{
            int result = 0;
            unordered_map<char, int> uns;
            for (int i = 0; i < s.size();i++){
                ++uns[s[i]];
                if (i >= (k-1))
                {
                    if(i==(k-1)){
                        result = (uns.size() == k);
                    }
                    else{
                        --uns[s[i - k]];
                        if(uns[s[i-k]]==0){
                            uns.erase(s[i-k]);
                        }
                        result += (uns.size() == k);
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
    int array_len = 50, k = 5; // 字符串数组长度、窗口长度
    string* num_array=new string();
    for (int i = 0; i < array_len;i++){
        int temp = rand() % 52;
        if(temp<26){
            *num_array += temp + 'a';
        }
        else
        {
            *num_array += (temp - 26) + 'A';
        }
    }
    cout << *num_array << endl;
    cout << "长度为 " << k << " 的子字符串无重复子串有：" << so.numKLenSubstrNoRepeats(*num_array, k) << "个" << endl;

    delete num_array;
    clock_t end = clock();
    cout << "算法运行了 " << end - start << " ms" << endl;
    return 0;
}