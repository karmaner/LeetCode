/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30204
 *
 * [1] 两数之和
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
    vector<int> s1_twoSum(vector<int>& nums, int target) { 
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i + 1;   // 0索引 和 map 0默认值冲突 
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(map[target - nums[i]] > 0 && (map[target - nums[i]] - 1) != i) {
                return {i, map[target - nums[i]] - 1};
            }
        }
        return {};
    }
    // 版本优化
    vector<int> s2_twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                return {iter->second, i};
            }

            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
    vector<int> s3_twoSum(vector<int>& nums, int target) {
        return {};
    }
    vector<int> s4_twoSum(vector<int>& nums, int target) {
        return {};
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return s2_twoSum(nums, target);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

