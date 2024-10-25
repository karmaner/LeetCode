// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30114
 *
 * [416] 分割等和子集
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
	bool ans = false;
	void backtrack(int start, vector<int>& nums, vector<bool>& used, int sum, int target) {
		if(sum > target) return;
		if(sum == target) {
			ans = true;
			return;
		}
		for(int i = 0; i < nums.size(); ++i) {
			if(used[i]) continue;
			sum += nums[i];
			used[i] = true;
			backtrack(i + 1, nums, used, sum, target);
			used[i] = false;
			sum -= nums[i];
		}
		return;
}
public:
	bool s1_canPartition(vector<int>& nums) {
		int sum = 0;
		for(auto i : nums) sum += i;
		if(sum % 2) return false;
        vector<int> dp(10001, 0);

		int target = sum / 2;

        // 开始 01背包
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
        return false;

	}

public:
	bool canPartition(vector<int>& nums) {
		// // 超时
		// int sum = 0;
		// for(auto i : nums) sum += i;
		// vector<bool> used(nums.size(), false);
		// if(sum % 2) return false;
		// backtrack(0, nums, used, 0, sum / 2);
		// return ans;
		return s1_canPartition(nums);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
