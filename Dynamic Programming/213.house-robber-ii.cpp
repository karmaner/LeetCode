/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30204
 *
 * [213] 打家劫舍 II
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

    int rob_range(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size(), 0);
        if (end == start) return nums[start];
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        
        for(int i = start + 2; i <= end; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }

    int s1_rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int ans1 = rob_range(nums, 0, nums.size() - 2);
        int ans2 = rob_range(nums, 1, nums.size() - 1);
        return max(ans1, ans2);
    }
    int rob(vector<int>& nums) {
        return s1_rob(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

