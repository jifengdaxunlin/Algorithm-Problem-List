#include <iostream>
#include <ctime> // time()
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        if(eventTime==0||startTime.empty()||endTime.empty()){
            return 0;
        }
        else{
            int max = 0, result = 0, temp = 0;
            vector<int> time;
            for (int i = 0; i < (startTime.size() + 1);i++){
                if (i < startTime.size()){
                    time.push_back(startTime[i] - temp);
                    temp = endTime[i];

                }
                else{
                    time.push_back((eventTime-1) - temp);
                }
                
            }

            for (int flag = 0; flag < time.size();flag++){
                max += time[flag];
                if (flag > k){
                    max -= time[flag - k - 1];
                }
                if (result < max)
                {
                    result = max;
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
    int eventTime = 10, n = 3, k = 2; // 活动总时长、会议数、可动会议数
    vector<int> startTime(n), endTime(n);
    for (int i = 0; i < n; i++)
    {
        static int temp = 0;
        startTime[i] = temp + 1;
        endTime[i] = startTime[i] + rand() % (n - 1) + 1;
        temp = endTime[i];
        cout << "|"<<startTime[i] << "    " << endTime[i]<<"\t";
    }
    cout <<"|"<< endl;
    cout << "活动总时长为 " << eventTime << " ，会议数为 " << n << " 可动会议数为 " << k << " ，安排后最大空余时间为：" << so.maxFreeTime(eventTime, k, startTime, endTime) << endl;
    clock_t end = clock();
    printf("\n算法运行了 %d ms", end - start);
    return 0;
}
/*
给你一个整数 eventTime 表示一个活动的总时长，这个活动开始于 t = 0 ，结束于 t = eventTime 。

同时给你两个长度为 n 的整数数组 startTime 和 endTime 。它们表示这次活动中 n 个时间 没有重叠 的会议，其中第 i 个会议的时间为 [startTime[i], endTime[i]] 。

你可以重新安排 至多 k 个会议，安排的规则是将会议时间平移，且保持原来的 会议时长 ，你的目的是移动会议后 最大化 相邻两个会议之间的 最长 连续空余时间。

移动前后所有会议之间的 相对 顺序需要保持不变，而且会议时间也需要保持互不重叠。

请你返回重新安排会议以后，可以得到的 最大 空余时间。

注意，会议 不能 安排到整个活动的时间以外。



示例 1：

输入：eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]

输出：2

解释：



将 [1, 2] 的会议安排到 [2, 3] ，得到空余时间 [0, 2] 。

示例 2：

输入：eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]

输出：6

解释：



将 [2, 4] 的会议安排到 [1, 3] ，得到空余时间 [3, 9] 。

示例 3：

输入：eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

输出：0

解释：

活动中的所有时间都被会议安排满了。
*/