/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
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
    vector<int> s1_sortedSquares(vector<int>& nums) {   // 暴力解法
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> s2_sortedSquares(vector<int>& nums) {   // 双指针
        vector<int> ans(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;
        while(left <= right) {
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                ans[index--] = nums[left] * nums[left];
                left++;
            } else {
                ans[index--] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        return s2_sortedSquares(nums);
        // return s1_sortedSquares(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

