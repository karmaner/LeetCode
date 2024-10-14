// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=30113
 *
 * [122] 买卖股票的最佳时机 II
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
	int s1_maxProfit(vector<int>& prices) {	// 贪心就是不记录 路径的动态规划
		int ans = 0;
		for(int i = 0; i < prices.size(); ++i) {
			ans += max(prices[i] - prices[i - 1], 0);
		}
		return ans;
	}

	int s2_maxProfit(vector<int>& prices) {
		vector<int> dp(prices.size(), 0);	// dp[i] i位置最大利益
		dp[0] = 0;
		for(int i = 1; i < prices.size(); ++i) {
			dp[i] = dp[i - 1] + max(prices[i] - prices[i - 1], 0);	// 前为卖 后为不卖
		}

		return dp[prices.size() - 1];
	}
public:
	int maxProfit(vector<int>& prices) {
		// return s1_maxProfit(prices);
		return s2_maxProfit(prices);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
