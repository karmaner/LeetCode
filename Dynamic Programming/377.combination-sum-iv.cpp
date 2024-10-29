/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30204
 *
 * [377] 组合总和 Ⅳ
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
    int s1_combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long int> dp(target + 1, 0);  // dp[i]目标和为i的组合数目
        dp[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int num : nums) {
                if(i >= num) dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        return s1_combinationSum4(nums, target);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */

