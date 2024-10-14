/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30113
 *
 * [135] 分发糖果
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
	// 最低糖在哪里? 可以不用找 每个人至少一颗糖
	int s1_candy(vector<int>& ratings) {
		vector<int> candyVec(ratings.size(), 1);
		for(int i = 1; i < ratings.size(); ++i) {
			if(ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
		}

		for(int i = ratings.size() - 2; i >= 0; --i) {
			if(ratings[i] > ratings[i + 1]) {
				candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
			}
		}
		int ans = 0;
		for(int i = 0; i < candyVec.size(); i++) ans += candyVec[i];
		return ans;
	}
public:
	int candy(vector<int>& ratings) {
		return s1_candy(ratings);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */
