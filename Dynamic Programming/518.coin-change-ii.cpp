/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30204
 *
 * [518] 零钱兑换 II
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
    int s1_change(int amount, vector<int>& coins) { // 错误做法 做成排列了
        vector<int> dp(amount + 1, 1);
        for(int i = amount; i >= 0; --i) {
            for(int j = 0; j < coins.size(); ++j) {
                if(i >= coins[j])
                    dp[i] += (dp[i - coins[j]] + 1);
            }
            cout << i << " " << dp[i] << endl;
        }
        return dp[amount];
    }
    int s2_change(int amount, vector<int>& coins) {

        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 组成金额0的方式有1种

        for (int coin : coins) { // 遍历每种硬币
            for (int i = coin; i <= amount; ++i) { // 从coin开始到amount
                dp[i] += dp[i - coin]; // 更新组合数
            }
        }

        return dp[amount]; // 返回组成amount的组合数
    }
    int change(int amount, vector<int>& coins) {
        return s2_change(amount, coins);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */

