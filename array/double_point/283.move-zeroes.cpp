/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] 移动零
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
    void copy_array(vector<int>& nums) {
        int right = nums.size();
        int i = 0;
        vector<int> ans(right, 0);
        for(int left = 0; left < right; left++) {
            if(nums[left] != 0) {
                ans[i++] = nums[left];
            }
        }
        nums = ans;
    }
public:
    void double_point(vector<int>& nums) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if(nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        while(slowIndex < nums.size()) {
            nums[slowIndex++] = 0;
        }
    }
public:
    void moveZeroes(vector<int>& nums) {
        //copy_array(nums);
        double_point(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

