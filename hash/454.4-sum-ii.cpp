/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> sum12;
        std::unordered_map<int, int> sum34;

        for(auto i : nums1) {   // 1 2数组出现的和次数
            for(auto j : nums2) {
                sum12[i + j]++;
            }
        }

        for(auto i : nums3) {   // 3 4数组出现的和次数
            for(auto j : nums4) {
                sum34[i + j]++;
            }
        }

        int times = 0;
        for(auto s : sum12) {
            if(sum34[-s.first] > 0) {
                times += (s.second * sum34[-s.first]);
            }
        }
        return times;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */

