/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30114
 *
 * [70] 爬楼梯
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
  int climbStairs(int n) {
    // // 简单递归     // 递归边界用例超时
    // if (n < 3) return n;
    // return climbStairs(n - 1) + climbStairs(n - 2);

    // 动态规划一个一个算
    if (n < 3) return n;
    vector<int> dp(3);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      int next = dp[1] + dp[2];
      dp[1] = dp[2];
      dp[2] = next;
    }
    return dp[2];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
