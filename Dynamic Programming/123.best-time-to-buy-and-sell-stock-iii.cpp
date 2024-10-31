/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30204
 *
 * [123] 买卖股票的最佳时机 III
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
    int buy(vector<int>& prices, int start, int end) {
        int cost = INT_MAX, profit = 0;
        for(int i = start; i < end; ++i) {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
        }
        return profit;
    }

    int s1_maxProfit(vector<int>& prices) { // O(n^2)  部分用力超时
        int sum = 0;
        for(int i = 0; i < prices.size(); ++i) {
            int one = buy(prices, 0, i);
            int two = buy(prices, i, prices.size());
            sum = max(sum, one + two);
        }
        return sum;
    }

    int s2_maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);                   // 第一次持有的现金
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);     // 第一次不持有的现金余额
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);     // 第二次持有的现金
            dp[i][3] = max(dp[i - 1][3], prices[i] + dp[i - 1][2]);     // 第二次不持有的现金
            // cout << dp[i][0] << " "<< dp[i][1]  << " " << dp[i][2] << " " << dp[i][3] << endl;; 
        }
        return dp[prices.size() - 1][3];
    }

    int s3_maxProfit(vector<int>& prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for(int i = 1; i < prices.size(); ++i) {
            f1 = max(f1, -prices[i]);
            f2 = max(f2, f1 + prices[i]);
            f3 = max(f3, f2 - prices[i]);
            f4 = max(f4, f3 + prices[i]);
        }
        return f4;
    }
    int maxProfit(vector<int>& prices) {
        return s3_maxProfit(prices); 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

