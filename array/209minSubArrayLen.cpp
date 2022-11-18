/*
    LeetCode:209
    我的第一个中等难度的题目

    思路 1:
        暴力求解(双重遍历)
    思路 2：
        模拟队列
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// /*solution 1 暴力求解 */ 超时间
// class Solution
// {
// public:
//     int minSubArrayLen(int target, vector<int> &nums)
//     {
//         int sum = 0;
//         int ans = INT_MAX;
//         int SubLength = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             sum = 0;
//             for (int j = i; j < nums.size(); j++)
//             {
//                 sum += nums[j];
//                 if (sum >= target)
//                 {
//                     SubLength = j - i + 1;
//                     ans = (SubLength < ans) ? SubLength : ans;
//                     break;
//                 }
//             }
//         }
//         if (ans == INT_MAX)
//             return 0;
//         return;
//     }
// };

/* 双指针实现滑动窗口*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;       // 滑动窗口数值之和
        int i = 0;         // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= target)
            {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};
int main()
{

    int target = 11;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    Solution solution;
    int ans = solution.minSubArrayLen(target, nums);
    cout << ans << endl;
    return 0;
}
