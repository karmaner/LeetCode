/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
vector<int> binary_search(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    int left = 0, right = nums.size() - 1;
    // 找到左边界
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (left >= nums.size() || nums[left] != target) {
        return ans; // 如果没有找到目标
    }
    
    ans[0] = left; // 左边界
    
    // 找到右边界
    right = nums.size() - 1; // 重置右边界
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    ans[1] = right; // 右边界
    return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return binary_search(nums, target);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

