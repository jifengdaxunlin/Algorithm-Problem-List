#include <iostream>
#include <ctime> // time()
#include <unordered_map>    //哈希表头文件
#include <math.h>   
#include <vector>
using namespace std;

class Solution
{
public:
    int sample()
    {
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int string_len = 10, k = 3; // 字符串长度
    string s_test;
    for (int i = 0; i < string_len; i++)
    {
        int temp = rand() % 52;
        if (temp < 26)
        {
            s_test.append(1, temp + 'a');
        }
        else
        {
            s_test.append(1, temp - 26 + 'A');
        }
    }
    cout << s_test << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}