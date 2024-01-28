// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30114
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    // // dp[i] 表示爬到第i个台阶需要的最小费用
    // vector<int> dp(cost.size() + 1);
    // dp[0] = 0;
    // dp[1] = 0;

    // for (int i = 2; i <= cost.size(); i++) {
    //   dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    // }

    // return dp[cost.size()];

    // 动态规划 优化空间复杂度
    int dp0 = 0;
    int dp1 = 0;
    for (int i = 2; i <= cost.size(); i++) {
      int next = min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
      dp0 = dp1;
      dp1 = next;
    }
    return dp1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */
