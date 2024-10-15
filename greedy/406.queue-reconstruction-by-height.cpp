/*
 * @lc app=leetcode.cn id=406 lang=cpp
 * @lcpr version=30204
 *
 * [406] 根据身高重建队列
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort (people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        // 局部最优 是插入前元素 是排序正常的
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]\n
// @lcpr case=end

 */

