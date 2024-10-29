/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30204
 *
 * [198] 打家劫舍
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
    int s1_rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]); // 下标问题
        }

        return dp[nums.size()];
    }
    int rob(vector<int>& nums) {
        return s1_rob(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

