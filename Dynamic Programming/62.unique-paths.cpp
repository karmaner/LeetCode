/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30114
 *
 * [62] 不同路径
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
  // 深度搜索
  int dfs(int i, int j, int m, int n) {
    if (i > m || j > n) return 0;
    if (i == m && j == n) return 1;
    return dfs[i - 1][j] + dfs[i][j - 1];
  }
  int uniquePaths(int m, int n) {
    // int ans = dfs(1, 1, m, n);
    // return ans;
  }

  // // dp[i][j]表示到(i,j)位置的方法数
  // vector<vector<int>> dp(m, vector<int>(n));

  // // 初始化
  // for (int i = 0; i < m; ++i) dp[i][0] = 1;
  // for (int j = 0; j < n; ++j) dp[0][j] = 1;

  // // 递推方程  dp[i][j] = dp[i -1][j] + dp[i][j - 1];
  // // 计算位置
  // for (int i = 1; i < m; ++i) {
  //   for (int j = 1; j < n; ++j) {
  //     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
  //   }
  // }
  // return dp[m - 1][n - 1];
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */
