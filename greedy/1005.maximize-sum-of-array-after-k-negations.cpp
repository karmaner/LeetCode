/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 * @lcpr version=30113
 *
 * [1005] K 次取反后最大化的数组和
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
    /** 按照绝对值排序 */
    int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) > abs(b); });
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] < 0 && k > 0) {
				nums[i] *= -1;
				k--;
			}
		}
		if (k % 2 == 1) nums[nums.size() - 1] *= -1;

		int ans = 0;
		for (auto a : nums) ans += a;
		return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,-1,0,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,-3,-1,5,-4]\n2\n
// @lcpr case=end

 */
