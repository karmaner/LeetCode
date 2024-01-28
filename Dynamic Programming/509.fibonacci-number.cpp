// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30114
 *
 * [509] 斐波那契数
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
  int fib(int n) {
    // // 普通递归 o(2^n)
    // if (n < 2) return n;
    // return fib(n - 1) + fib(n - 2);

    //     // 动态规划
    //     if (n < 2) return n;

    //     vector<int> dp(n + 1);
    //     dp[0] = 0;
    //     dp[1] = 1;

    //     for (int i = 2; i <= n; ++i) {
    //       dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    //   }

    // 动态规划优化 (没必要都存储n前的每一个值) 结合递推
    if (n < 2) return n;
    vector<int> dp(2);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      int next = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = next;
    }
    return dp[1];
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

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
