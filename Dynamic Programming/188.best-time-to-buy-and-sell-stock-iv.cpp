/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30204
 *
 * [188] 买卖股票的最佳时机 IV
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
    int s1_maxProfit(int k, vector<int>& prices) {
        vector<int> f(2 * k + 1, 0);
        for(int i = 1; i < f.size(); i+=2) f[i] = -prices[0];

        for(int i = 1; i < prices.size(); ++i) {
            f[1] = max(f[1], -prices[i]);
            int flag = 1;
            for(int j = 2; j <= 2 * k; ++j) {
                f[j] = max(f[j], f[j - 1] + prices[i] * flag);
                flag *= -1;
            }
        }
        // for(auto i : f) cout << i << " ";
        return f[2 * k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return s1_maxProfit(k, prices);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */

