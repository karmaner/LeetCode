/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30113
 *
 * [455] 分发饼干
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
/** 算法思想  给胃口大的给大饼干 */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = s.size() - 1;

        int ans = 0;

        // 把大的饼干给大胃口的小孩
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                ans++;
                index--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

