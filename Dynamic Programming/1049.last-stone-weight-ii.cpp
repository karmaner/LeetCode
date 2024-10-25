/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 * @lcpr version=30204
 *
 * [1049] 最后一块石头的重量 II
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
    int s1_lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) sum += stone;
        
        int n = stones.size();
        int target = sum / 2;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (stones[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        
        return sum - 2 * dp[n][target];
    }
    
    // 优化
    int s2_lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0, std::plus<int>());
        int target = sum / 2;
        
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int i = target; i >= 0; --i) {
            if (dp[i]) {
                return sum - 2 * i;
            }
        }
    
    return sum; // If all stones are the same weight
    }

    int lastStoneWeightII(vector<int>& stones) {
        return s2_lastStoneWeightII(stones);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,4,1,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [31,26,33,21,40]\n
// @lcpr case=end

 */

