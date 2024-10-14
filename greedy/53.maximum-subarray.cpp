// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30113
 *
 * [53] 最大子数组和
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
    int s1_maxSubArray(vector<int>& nums) {
        // 暴力部分用例超时
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                ans = sum > ans ? sum : ans;
            }
        }
        return ans;
    }
    int s2_maxSubArray(vector<int>& nums) { // 双指针 左指针为
        int ans = INT_MIN;
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {

            /* 判断连续和 */
            if (sum < 0 && nums[right] >= sum) { // 解决全部事负数的问题
                sum = 0;
            }
            sum += nums[right];
            ans = ans > sum ? ans : sum;
        }
        return ans;
    }

    int s3_maxSubArray(vector<int>& nums) {
        // dp[i] 表示 i位置的最大和
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > ans) ans = dp[i];
        }
        return ans;
    }

    int s4_maxSubArray(vector<int>& nums) {
        // TODO: 分治
        return 0;
    }
public:
    int maxSubArray(vector<int>& nums) {
        return s3_maxSubArray(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

