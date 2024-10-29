/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30204
 *
 * [474] 一和零
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
    int s1_findMaxFrom(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int> (n + 1));
        for(auto s : strs) {
            int oneNum = 0, zeroNum = 0;
            for(auto c : s) {
                if(c == '0') zeroNum++;
                else oneNum++;
            }
            for(int i = m; i >= zeroNum; i--) {
                for(int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j-oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return s1_findMaxFrom(strs, m, n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["10", "0001", "111001", "1", "0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10", "0", "1"]\n1\n1\n
// @lcpr case=end

 */

