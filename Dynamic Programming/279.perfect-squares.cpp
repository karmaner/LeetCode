/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30204
 *
 * [279] 完全平方数
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
    int s1_numSquares(int n) {
        vector<unsigned> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        // dp[i] = min(dp[i], dp[i - j * j]);

        for(int i = 0; i <= n; ++i) {
            for(int j = 1; j <= n / 2; ++j) {   // bug fixed
                if(i >= j * j)
                    dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
            cout << i << " " << dp[i] << endl;
        }
        return dp[n];
    }
    int numSquares(int n) {
        return s1_numSquares(n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

