/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
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
    vector<vector<int>> s1_merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        if (intervals.size() == 0) return ans; // 区间集合为空直接返回
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });

        // 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
        ans.push_back(intervals[0]); 

        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] >= intervals[i][0]) { // 发现重叠区间
                // 合并区间，只更新右边界就好，因为ans.back()的左边界一定是最小值，因为我们按照左边界排序的
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
            } else {
                ans.push_back(intervals[i]); // 区间不重叠 
            }
        }
        return ans;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return s1_merge(intervals);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

