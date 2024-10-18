/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30114
 *
 * [96] 不同的二叉搜索树
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
	int s1_numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[0] = 1;

		for(int i = 2; i <= n; ++i) {
			for(int j = 1; j <= i; ++j) {
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}

	int s2_numTrees(int n) {
		return 0;
	}
public:
	int numTrees(int n) {
		return s1_numTrees(n);
	}
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
