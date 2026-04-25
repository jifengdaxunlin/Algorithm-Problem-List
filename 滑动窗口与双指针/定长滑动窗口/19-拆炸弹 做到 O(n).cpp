#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        if(code.empty()){
            return {};
        }
        else{
            int size = code.size(), temp = 0;
            vector<int> result(size,0);
            if(k==0){
                return result;
            }
            else if(k>0){
                for (int j = 0; j < k; j++)
                {
                    temp += code.at(j);
                }
                result.at(0) = temp;
                for (int i = 0; i < (size-1);i++){
                    temp -= code.at(i);
                    temp += code.at((i + k) % size);
                    result.at(i + 1) = temp;
                }
            }
            else if(k < 0)
            {
                k = -k;
                for (int j = 0; j < k; j++)
                {
                    temp += code.at((size - j) % size);
                }
                result.at(0) = temp;
                for (int i = 0; i < (size - 1); i++)
                {
                    temp -= code.at((i + size - k + 1) % size);
                    temp += code.at(i + 1);
                    result.at(i + 1) = temp;
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
    int array_len = 10, k = -2; // 数组长度、窗口长度
    vector<int> num_array(array_len);
    for (int i = 0; i < array_len; i++)
    {
        num_array[i] = rand() % 10;
        cout << num_array[i] << "\t";
    }
    cout << endl;

    vector<int> result = so.decrypt(num_array,k);
    for (int j = 0; j < array_len;j++){
        cout << result.at(j) << "  ";
    }
    cout << endl;

    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}

/*
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
如果 k == 0 ，将第 i 个数字用 0 替换。
由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。

给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！

示例 1：

输入：code = [5,7,1,4], k = 3
输出：[12,10,16,13]
解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
示例 2：

输入：code = [1,2,3,4], k = 0
输出：[0,0,0,0]
解释：当 k 为 0 时，所有数字都被 0 替换。
示例 3：

输入：code = [2,4,9,3], k = -2
输出：[12,5,6,13]
解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。
*/