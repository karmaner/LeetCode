/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
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
    vector<int> s1_intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> map;
        for(auto i : nums1) {
            map[i] = true;
        }
        vector<int> ans;
        for(auto i : nums2) {
            if(map[i] == true) {
                auto f = find(ans.begin(), ans.end(), i);
                if(f == ans.end())
                    ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> s2_intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        int hash[1005] = {0};
        for(auto i : nums1) {
            hash[i] = 1;
        }
        for(auto i : nums2) {
            if(hash[i] == 1) {
                set.insert(i);  // 去重
            }
        }
        return vector<int>(set.begin(), set.end());
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // return s1_intersection(nums1, nums2);
        return s2_intersection(nums1, nums2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

