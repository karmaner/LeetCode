// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30204
 *
 * [452] 用最少数量的箭引爆气球
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
    int s1_findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto a, auto b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        // for(auto i : points) {
        //     cout << "["<< i[0] << ", " << i[1] << "]" << endl;
        // }
        int count = 1;
        int min = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] <= min) {
                continue;
            } else {
                min = points[i][1];
                count++;
            }
            // cout << count << " ";
        }
        return count;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        return s1_findMinArrowShots(points);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */

