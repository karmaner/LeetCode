/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=30114
 *
 * [343] 整数拆分
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
	int s1_integerBreak(int n) {
		vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
	}

	int s2_integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        vector <int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }

	int s3_integerBreak(int n) {
		if(n == 2) {
			return 1;
		}
		if(n == 3) {
			return 2;
		}
		int temp = 1;
		while(n > 4) {
			temp *= 3;
			n -= 3;
		}
		return temp * n;
	}

public:
	int integerBreak(int n) {
		// return s1_integerBreak(n);
		// return s2_integerBreak(n);
		return s3_integerBreak(n);
	}
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
