// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30114
 *
 * [746] 使用最小花费爬楼梯
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
	int s1_minCostClimbingStairs(vector<int>& cost) {

		vector<int> dp(cost.size(), 0);

		for(int i = 2; i <= cost.size(); ++i) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}

	int s2_minCostClimbingStairs(vector<int>& cost) {
		int prev = 0, curr = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int next = min(curr + cost[i-1], prev + cost[i-2]);
            prev = curr;
            curr = next;
        }
        return curr;
	}
public:
	int minCostClimbingStairs(vector<int>& cost) {
		// return s1_minCostClimbingStairs(cost);
		return s2_minCostClimbingStairs(cost);
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
