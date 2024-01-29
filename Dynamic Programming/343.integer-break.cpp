/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=30114
 *
 * [343] 整数拆分
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
  int integerBreak(int n) {
    // 动态规划
    // vector<int> dp(n + 1);

    // dp[2] = 1;
    // for (int i = 3; i <= n; ++i) {
    //   for (int j = 1; j <= i / 2; ++j) {
    //     dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
    //   }
    // }
    // return dp[n];

    // 贪心
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    int ans = 1;
    while (n > 4) {
        ans *= 3;
        n -= 3;
    }
    ans *= n;
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
