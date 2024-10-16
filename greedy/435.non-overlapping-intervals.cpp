/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30204
 *
 * [435] 无重叠区间
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
    int s1_eraseOverlapIntervals(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
            return a[1] < b[1];
        });
        int min = intervals[0][1];
        int count = 1;
        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i][0] < min) {
                continue;
            } else {
                min = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        return s1_eraseOverlapIntervals(intervals);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [1,2], [1,2] ]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [2,3] ]\n
// @lcpr case=end

 */

