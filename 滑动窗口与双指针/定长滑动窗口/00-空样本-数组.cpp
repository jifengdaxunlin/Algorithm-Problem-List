#include <iostream>
#include <ctime> // time()
#include <unordered_map>    //哈希表头文件
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int sample(){

    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    clock_t start = clock(); // 表示当前cpu记录下的已经过了的毫秒数

    Solution so;
    int array_len = 10, k = 3; // 数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 20001;
        cout << num_array[i] << "\t";
    }
    cout << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}