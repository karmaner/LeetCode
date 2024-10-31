/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30204
 *
 * [121] 买卖股票的最佳时机
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
    int s1_maxProfit(vector<int>& prices) { // 暴力解法
        int max_profit = 0;
        for(int right = prices.size() - 1;right >= 0; right--) {
            for(int left = 0; left <= right; left++) {
                max_profit = max(max_profit, prices[right] - prices[left]);
                // cout << max_profit << endl;
            }
        }
        return max_profit;
    }

    int s2_maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for(auto price : prices) {
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;
    }

    int s3_maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(2, 0)); // dp[i][0]  0表示持有现金 dp[i][1]表示不持有现金

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);   // 找最低价格
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i][0]); // 计算利益
            // cout << dp[i][1] << endl;
        }
        return dp[prices.size() - 1][1];
    }

    int maxProfit(vector<int>& prices) {
        return s3_maxProfit(prices);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

