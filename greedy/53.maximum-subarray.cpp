// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30113
 *
 * [53] 最大子数组和
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // // 暴力部分用例超时
        // int ans = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         sum += nums[j];
        //         ans = sum > ans ? sum : ans;
        //     }
        // }
        // return ans;

        // 贪心算法
        // 连续和为负数  则从新的起点开始  为正数则可以继续加
        int ans = INT_MIN;
        int sum = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {

            /* 判断连续和 */
            if (sum < 0 && nums[right] >= sum) { // 解决全部事负数的问题
                left = right;
                sum = 0;
            }
            sum += nums[right];
            ans = ans > sum ? ans : sum;
        }
        return ans;

        // 后续有动态规划解法 

    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

