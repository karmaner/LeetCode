/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
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
    int s_minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, min_num = INT_MAX;
        for(right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum >= target) {
                min_num = min(min_num, right - left + 1);
                sum -= nums[left++];
            }
        }
        return min_num == INT_MAX ? 0 : min_num;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        return s_minSubArrayLen(target, nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

