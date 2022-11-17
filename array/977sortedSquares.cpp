/*
    2022/11/17
    LeetCode 977

    给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

    双指针 给左右两个指针
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int n = right;
        vector<int> ans(nums.size(), 0);
        if (nums[left] * nums[left] >= nums[right] * nums[right])
        {
            ans[n--] = nums[left] * nums[left];
            left++;
        }
        else
        {
            ans[n--] = nums[right] * nums[right];
            right--;
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    return 0;
}
